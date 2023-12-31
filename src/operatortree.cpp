#include "operatortree.h"
#include "binaryoperatornode.h"
#include "valueoperatornode.h"
#include "unaryoperatornode.h"
#include <algorithm>
#include <sstream>
#include <assert.h>
#include "constant.h"

using namespace std;

OperatorTree::OperatorTree(const string &expression) :
	m_ans(0),
	m_angleType(AngleTypeRadiant),
	m_rootNode(0),
	m_parsingFailed(false)
{
	parse(expression);
}

OperatorTree::OperatorTree(const string &expression, double lastAnswer, AngleType angleType) :
	m_ans(lastAnswer),
	m_angleType(angleType),
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
	string::iterator newEnd = remove(expression.begin(), expression.end(), ' ');
	string temporaryExpression(expression.begin(), newEnd);
	expression = temporaryExpression;

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

	if (m_parsingFailed)
		return 0;

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
	vector<string::const_iterator> potencies = findPotencysNotInside(expression, brackets);
	vector<string::const_iterator> unaryfunctions = findUnaryFunctionsNotInside(expression, brackets);

	if (additionsAndSubtractions.size() > 0)
	{
		string::const_iterator selectedOperator = additionsAndSubtractions.back();
		string firstPart(expression.begin(), selectedOperator);

		// if the first part is empty or ends with an opening bracket we only have a negative value and not a subtraction
		if (firstPart.size() > 0 && firstPart[firstPart.size() - 1] != '(')
			return parseBinaryOperator(expression, selectedOperator);
	}

	if (multiplicationsAndDivisions.size() > 0)
	{
		string::const_iterator selectedOperator = multiplicationsAndDivisions.back();
		return parseBinaryOperator(expression, selectedOperator);
	}
	else if (potencies.size() > 0)
	{
		string::const_iterator selectedOperator = potencies.front();
		return parseBinaryOperator(expression, selectedOperator);
	}
	else if (unaryfunctions.size() > 0)
		return parseUnaryOperator(expression);
	else if (expression.compare("pi") == 0)
		return new ValueOperatorNode(pi);
	else if (expression.compare("ans") == 0)
		return new ValueOperatorNode(m_ans);
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
	else if (*selectedOperator == '^')
		operationType = BinaryOperationTypePotency;
	else
		assert(false);

	BinaryOperatorNode *node = new BinaryOperatorNode(operationType);
	OperatorNode *leftNode = parseRecursive(firstPart);;
	OperatorNode *rightNode = parseRecursive(secondPart);
	node->setLeftNode(leftNode);
	node->setRightNode(rightNode);

	return node;
}

OperatorNode *OperatorTree::parseUnaryOperator(const string &expression)
{
	UnaryOperatorNode *result = 0;
	string childExpression;

	if (expression.find("sin") == 0)
	{
		result = new UnaryOperatorNode(UnaryOperationTypeSine, m_angleType);
		childExpression = expression.substr(3);
	}
	else if (expression.find("cos") == 0)
	{
		result = new UnaryOperatorNode(UnaryOperationTypeCosine, m_angleType);
		childExpression = expression.substr(3);
	}
	else if (expression.find("tan") == 0)
	{
		result = new UnaryOperatorNode(UnaryOperationTypeTangens, m_angleType);
		childExpression = expression.substr(3);
	}
	else if (expression.find("exp") == 0)
	{
		result = new UnaryOperatorNode(UnaryOperationTypeExponential, m_angleType);
		childExpression = expression.substr(3);
	}
	else if (expression.find("asin") == 0)
	{
		result = new UnaryOperatorNode(UnaryOperationTypeArcSine, m_angleType);
		childExpression = expression.substr(4);
	}
	else if (expression.find("acos") == 0)
	{
		result = new UnaryOperatorNode(UnaryOperationTypeArcCosine, m_angleType);
		childExpression = expression.substr(4);
	}
	else if (expression.find("atan") == 0)
	{
		result = new UnaryOperatorNode(UnaryOperationTypeArcTangens, m_angleType);
		childExpression = expression.substr(4);
	}
	else if (expression.find("ln") == 0)
	{
		result = new UnaryOperatorNode(UnaryOperationTypeLogarithmNaturalis, m_angleType);
		childExpression = expression.substr(2);
	}
	else
	{
		m_parsingFailed = true;
		return 0;
	}

	OperatorNode *child = parseRecursive(childExpression);
	result->setNode(child);

	return result;
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

vector<string::const_iterator> OperatorTree::findUnaryFunctionsNotInside(const string &expression, const vector<OperatorTree::bracketPair> &bracketPairs)
{
	vector<string::const_iterator> result;
	vector<string::const_iterator> allOperations = findAllUnaryFunctionsSorted(expression);

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

vector<string::const_iterator> OperatorTree::findAllUnaryFunctionsSorted(const string &expression)
{
	vector<string::const_iterator>  Position;
	vector<string::const_iterator>  BufPosition;
	BufPosition=findUnaryFunctions(expression,"sin");
	Position.insert(Position.end(),BufPosition.begin(),BufPosition.end());
	BufPosition=findUnaryFunctions(expression,"cos");
	Position.insert(Position.end(),BufPosition.begin(),BufPosition.end());
	BufPosition=findUnaryFunctions(expression,"tan");
	Position.insert(Position.end(),BufPosition.begin(),BufPosition.end());
	BufPosition=findUnaryFunctions(expression,"exp");
	Position.insert(Position.end(),BufPosition.begin(),BufPosition.end());
	BufPosition=findUnaryFunctions(expression,"asin");
	Position.insert(Position.end(),BufPosition.begin(),BufPosition.end());
	BufPosition=findUnaryFunctions(expression,"acos");
	Position.insert(Position.end(),BufPosition.begin(),BufPosition.end());
	BufPosition=findUnaryFunctions(expression,"atan");
	Position.insert(Position.end(),BufPosition.begin(),BufPosition.end());
	BufPosition=findUnaryFunctions(expression,"ln");
	Position.insert(Position.end(),BufPosition.begin(),BufPosition.end());
	sort(Position.begin(), Position.end());
	return Position;
}


vector<string::const_iterator> OperatorTree::findUnaryFunctions(const string &expression, const string &func)
{
	vector<string::const_iterator> Positions;
	string::const_iterator lastPosition = expression.begin();

	do
	{
		size_t foundPosition = expression.find(func, lastPosition - expression.begin());

		if (foundPosition != string::npos && foundPosition==0)
		{
			lastPosition = expression.begin() + foundPosition;
		}
		else if (foundPosition != string::npos && expression[foundPosition-1]!='a')
		{
			lastPosition = expression.begin() + foundPosition;
		}
		else
		{
			lastPosition = expression.end();
		}

		Positions.push_back(lastPosition);
		++lastPosition;
	} while(Positions.back() != expression.end());

	Positions.pop_back();
	return Positions;
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

double OperatorTree::calculateValue(bool &error) const
{
	assert(!m_parsingFailed);
	if (m_parsingFailed)
	{
		error = true;
		return 0;
	}

	return m_rootNode->getValue(error);
}

vector<string::const_iterator> OperatorTree::findPotencys(const string &expression)
{
	vector<char> operations;
	operations.push_back('^');
	return findOperatorPositions(expression, operations);
}

vector<string::const_iterator> OperatorTree::findPotencysNotInside(const string &expression, const vector<OperatorTree::bracketPair> &bracketPairs)
{
	vector<string::const_iterator> result;
	vector<string::const_iterator> allOperations = findPotencys(expression);

	return findOperationsNotInside(allOperations, bracketPairs);
}
