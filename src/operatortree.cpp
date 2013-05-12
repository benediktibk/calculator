#include "operatortree.h"
#include "binaryoperatornode.h"
#include "valueoperatornode.h"
#include <algorithm>
#include <sstream>
#include <assert.h>

using namespace std;

OperatorTree::OperatorTree(const string &expression) :
	m_rootNode(0),
	m_parsingFailed(false)
{
	parse(expression);
}

OperatorTree::~OperatorTree()
{
	delete m_rootNode;
	m_rootNode = 0;
}

void OperatorTree::parse(string expression)
{
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
	OperatorNode *node = parseIfAllEnclosedInBrackets(expression, topLevelBrackets);
	if (node != 0)
		return node;
	else
		return parseIfNotEnclosedInBrackets(expression, topLevelBrackets);
}

OperatorNode *OperatorTree::parseIfAllEnclosedInBrackets(const string &expression, const vector<OperatorTree::bracketPair> &brackets)
{
	string::const_iterator lastPosition = expression.end();
	--lastPosition;
	for (vector<OperatorTree::bracketPair>::const_iterator i = brackets.begin(); i != brackets.end(); ++i)
	{
		if (i->first == expression.begin() && i->second == lastPosition)
			return parseRecursive(string(++expression.begin(), --expression.end()));
	}

	return 0;
}

OperatorNode *OperatorTree::parseIfNotEnclosedInBrackets(const string &expression, const std::vector<OperatorTree::bracketPair> &brackets)
{
	vector<string::const_iterator> additionsAndSubtractions = findAdditionsAndSubtractionsNotInside(expression, brackets);
	vector<string::const_iterator> multiplicationsAndDivisions = findMultiplicationsAndDivisionsNotInside(expression, brackets);
	if (additionsAndSubtractions.size() > 0)
	{
		string::const_iterator selectedOperator = additionsAndSubtractions.back();
		return parseBinaryOperator(expression, selectedOperator);

	}
	else if (multiplicationsAndDivisions.size() > 0)
	{
		string::const_iterator selectedOperator = multiplicationsAndDivisions.back();
		return parseBinaryOperator(expression, selectedOperator);
	}
	else
		return parseValue(expression);
}

OperatorNode *OperatorTree::parseBinaryOperator(const string &expression, const string::const_iterator &selectedOperator)
{
	string::const_iterator positionAfterOperator = selectedOperator;
	++positionAfterOperator;
	string firstPart(expression.begin(), selectedOperator);
	string secondPart(positionAfterOperator, expression.end());
	BinaryOperationType operationType;

	if (*selectedOperator == '+')
		operationType = BinaryOperationTypeAddition;
	else if (*selectedOperator == '-')
		operationType = BinaryOperationTypeSubtraction;
	else if (*selectedOperator == '*')
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

OperatorNode *OperatorTree::parseValue(const string &valueString)
{
	double value;
	stringstream stream(valueString);
	stream.clear();
	stream >> value;

	if (stream.fail() || valueString.size() == 0 || !stream.eof())
	{
		m_parsingFailed = true;
		return 0;
	}
	else
		return new ValueOperatorNode(value);
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
		if (openingBracket != expression.end() && closingBracket != expression.end())
			result.push_back(OperatorTree::bracketPair(openingBracket, closingBracket));
		else if (openingBracket != expression.end() && closingBracket == expression.end())
			m_parsingFailed = true;

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
	vector<char> operations;
	operations.push_back('*');
	operations.push_back('/');
	return findOperatorPositions(expression, operations);
}

vector<string::const_iterator> OperatorTree::findAdditionsAndSubtractions(const string &expression)
{
	vector<char> operations;
	operations.push_back('+');
	operations.push_back('-');
	return findOperatorPositions(expression, operations);
}

vector<string::const_iterator> OperatorTree::findOperatorPositions(const string &expression, const vector<char> &operations)
{
	vector<string::const_iterator> result;

	for (string::const_iterator i = expression.begin(); i != expression.end(); ++i)
		if (count(operations.begin(), operations.end(), *i) == 1)
			result.push_back(i);

	return result;
}

bool OperatorTree::parsingFailed() const
{
	return m_parsingFailed;
}

double OperatorTree::calculateValue() const
{
	assert(!m_parsingFailed);

	return m_rootNode->getValue();
}
