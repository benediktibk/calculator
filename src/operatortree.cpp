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
}

bool OperatorTree::parsingFailed() const
{
	return m_parsingFailed;
}
