#include "operatortree.h"
#include <algorithm>

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

std::vector<const OperatorNode*> OperatorTree::getNodesInOrder() const
{
	return vector<const OperatorNode*>();
}

void OperatorTree::parse(string expression)
{
	remove(expression.begin(), expression.end(), ' ');
	m_rootNode = parseRecursive(expression);
}

OperatorNode *OperatorTree::parseRecursive(const string &expression)
{
	if (expression.size() == 0)
	{
		m_parsingFailed = true;
		return 0;
	}
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

vector<size_t> OperatorTree::findMultiplicationsAndDivisions(const string &expression)
{
	vector<size_t> multiplications = findOperatorPositions(expression, '*');
	vector<size_t> divisions = findOperatorPositions(expression, '/');
	vector<size_t> result;
	result.reserve(multiplications.size() + divisions.size());
	result.insert(result.end(), multiplications.begin(), multiplications.end());
	result.insert(result.end(), divisions.begin(), divisions.end());
	return result;
}

vector<size_t> OperatorTree::findAdditionsAndSubtractions(const string &expression)
{
	vector<size_t> additions = findOperatorPositions(expression, '+');
	vector<size_t> subtractions = findOperatorPositions(expression, '-');
	vector<size_t> result;
	result.reserve(additions.size() + subtractions.size());
	result.insert(result.end(), additions.begin(), additions.end());
	result.insert(result.end(), subtractions.begin(), subtractions.end());
	return result;
}

vector<size_t> OperatorTree::findOperatorPositions(const string &expression, char operation)
{
	vector<size_t> result;

	for (size_t i = 0; i < expression.size(); ++i)
		if (expression[i] == operation)
			result.push_back(i);

	return result;
}

bool OperatorTree::parsingFailed() const
{
	return m_parsingFailed;
}
