#include "operatortree.h"
#include "binaryoperatornode.h"
#include "valueoperatornode.h"
#include <algorithm>
#include <sstream>
#include <assert.h>

using namespace std;

OperatorTree::OperatorTree(const string &expression) :
	m_rootNode(0),
	m_parsingFailed(true)
{
	parse(expression);
}

OperatorTree::~OperatorTree()
{
	delete m_rootNode;
	m_rootNode = 0;
}

vector<const OperatorNode*> OperatorTree::getNodesInOrder() const
{
	vector<const OperatorNode*> result;
	m_rootNode->addNodesInOrder(result);
	return result;
}

void OperatorTree::parse(string expression)
{
	m_parsingFailed = false;
	remove(expression.begin(), expression.end(), ' ');

	if (expression.size() == 0)
		m_rootNode = new ValueOperatorNode(0);
	else
		m_rootNode = parseRecursive(expression);
}

OperatorNode *OperatorTree::parseRecursive(const string &expression)
{
	if (expression.size() == 0)
	{
		m_parsingFailed = true;
		return 0;
	}

	vector<OperatorTree::bracketPair> topLevelBrackets = findTopLevelBracketPairs(expression);
	vector<string::const_iterator> additionsAndSubtractions = findAdditionsAndSubtractionsNotInside(expression, topLevelBrackets);
	vector<string::const_iterator> multiplicationsAndDivisions = findMultiplicationsAndDivisionsNotInside(expression, topLevelBrackets);

	string::const_iterator lastPosition = expression.end();
	--lastPosition;
	for (vector<OperatorTree::bracketPair>::const_iterator i = topLevelBrackets.begin(); i != topLevelBrackets.end(); ++i)
	{
		if (i->first == expression.begin() && i->second == lastPosition)
			return parseRecursive(string(++expression.begin(), --expression.end()));
	}

	if (additionsAndSubtractions.size() > 0)
	{
		string::const_iterator selectedOperator = additionsAndSubtractions.back();
		string::const_iterator positionAfterOperator = selectedOperator;
		++positionAfterOperator;
		string firstPart(expression.begin(), selectedOperator);
		string secondPart(positionAfterOperator, expression.end());
		BinaryOperationType operationType;

		if (*selectedOperator == '+')
			operationType = BinaryOperationTypeAddition;
		else if (*selectedOperator == '-')
			operationType = BinaryOperationTypeSubtraction;
		else
			assert(false);

		BinaryOperatorNode *node = new BinaryOperatorNode(operationType);
		OperatorNode *leftNode = parseRecursive(firstPart);
		OperatorNode *rightNode = parseRecursive(secondPart);
		node->setLeftNode(leftNode);
		node->setRightNode(rightNode);

		return node;
	}
	else if (multiplicationsAndDivisions.size() > 0)
	{
		string::const_iterator selectedOperator = multiplicationsAndDivisions.back();
		string::const_iterator positionAfterOperator = selectedOperator;
		++positionAfterOperator;
		string firstPart(expression.begin(), selectedOperator);
		string secondPart(positionAfterOperator, expression.end());
		BinaryOperationType operationType;

		if (*selectedOperator == '*')
			operationType = BinaryOperationTypeMultiplication;
		else if (*selectedOperator == '/')
			operationType = BinaryOperationTypeDivision;
		else
			assert(false);

		BinaryOperatorNode *node = new BinaryOperatorNode(operationType);
		OperatorNode *leftNode = parseRecursive(firstPart);
		OperatorNode *rightNode = parseRecursive(secondPart);
		node->setLeftNode(leftNode);
		node->setRightNode(rightNode);

		return node;
	}
	else
	{
		double value;
		stringstream stream(expression);
		stream >> value;
		ValueOperatorNode *node = new ValueOperatorNode(value);
		return node;
	}
}

vector<OperatorTree::bracketPair> OperatorTree::findTopLevelBracketPairs(const string &expression)
{
	vector<OperatorTree::bracketPair> result;
	string::const_iterator openingBracket;
	string::const_iterator closingBracket = expression.begin();

	do
	{
		openingBracket = findOpeningBracket(expression, closingBracket);
		closingBracket = findClosingBracket(expression, openingBracket);
		result.push_back(OperatorTree::bracketPair(openingBracket, closingBracket));

	} while(openingBracket != expression.end());

	return result;
}

string::const_iterator OperatorTree::findOpeningBracket(const string &expression)
{
	return find(expression.begin(), expression.end(), '(');
}

string::const_iterator OperatorTree::findOpeningBracket(const string &expression, const string::const_iterator &start)
{
	return find(start, expression.end(), '(');
}

string::const_iterator OperatorTree::findClosingBracket(const string &expression, const string::const_iterator &openingBracket)
{
	unsigned openBrackets = 0;
	for (string::const_iterator i = openingBracket; i != expression.end(); ++i)
	{
		if (*i == '(')
			++openBrackets;
		else if (*i == ')')
			--openBrackets;

		if (openBrackets == 0)
			return i;
	}

	return expression.end();
}

vector<string::const_iterator> OperatorTree::findMultiplicationsAndDivisionsNotInside(const string &expression, const vector<OperatorTree::bracketPair> &bracketPairs)
{
	vector<string::const_iterator> result;
	vector<string::const_iterator> allOperations = findMultiplicationsAndDivisions(expression);

	return findOperationsNotInside(allOperations, bracketPairs);
}

vector<string::const_iterator> OperatorTree::findAdditionsAndSubtractionsNotInside(const string &expression, const vector<OperatorTree::bracketPair> &bracketPairs)
{
	vector<string::const_iterator> result;
	vector<string::const_iterator> allOperations = findAdditionsAndSubtractions(expression);

	return findOperationsNotInside(allOperations, bracketPairs);
}

vector<string::const_iterator> OperatorTree::findOperationsNotInside(const vector<string::const_iterator> &operations, const vector<OperatorTree::bracketPair> &bracketPairs)
{
	vector<string::const_iterator> result;

	for (vector<string::const_iterator>::const_iterator i = operations.begin(); i != operations.end(); ++i)
	{
		bool insideBracket = false;

		for (vector<OperatorTree::bracketPair>::const_iterator j = bracketPairs.begin(); j != bracketPairs.end() && !insideBracket; ++j)
		{
			string::const_iterator firstBracket = j->first;
			string::const_iterator secondBracket = j->second;

			if (firstBracket < *i && *i < secondBracket)
				insideBracket = true;
		}

		if (!insideBracket)
			result.push_back(*i);
	}

	return result;
}

vector<string::const_iterator> OperatorTree::findMultiplicationsAndDivisions(const string &expression)
{
	vector<string::const_iterator> multiplications = findOperatorPositions(expression, '*');
	vector<string::const_iterator> divisions = findOperatorPositions(expression, '/');
	vector<string::const_iterator> result;
	result.reserve(multiplications.size() + divisions.size());
	result.insert(result.end(), multiplications.begin(), multiplications.end());
	result.insert(result.end(), divisions.begin(), divisions.end());
	return result;
}

vector<string::const_iterator> OperatorTree::findAdditionsAndSubtractions(const string &expression)
{
	vector<string::const_iterator> additions = findOperatorPositions(expression, '+');
	vector<string::const_iterator> subtractions = findOperatorPositions(expression, '-');
	vector<string::const_iterator> result;
	result.reserve(additions.size() + subtractions.size());
	result.insert(result.end(), additions.begin(), additions.end());
	result.insert(result.end(), subtractions.begin(), subtractions.end());
	return result;
}

vector<string::const_iterator> OperatorTree::findOperatorPositions(const string &expression, char operation)
{
	vector<string::const_iterator> result;

	for (string::const_iterator i = expression.begin(); i != expression.end(); ++i)
		if (*i == operation)
			result.push_back(i);

	return result;
}

bool OperatorTree::parsingFailed() const
{
	return m_parsingFailed;
}

double OperatorTree::calculateValue() const
{
	if(m_parsingFailed)
		return 0;

	return m_rootNode->getValue();
}
