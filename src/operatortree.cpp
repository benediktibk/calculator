#include "operatortree.h"

using namespace std;

OperatorTree::OperatorTree(const string &expression) :
	m_expression(expression),
	m_rootNode(0),
	m_parsingFailed(true)
{ }

OperatorTree::~OperatorTree()
{
	delete m_rootNode;
	m_rootNode = 0;
}

std::vector<const OperatorNode*> OperatorTree::getNodesInOrder() const
{
	return vector<const OperatorNode*>();
}

bool OperatorTree::parsingFailed() const
{
	return m_parsingFailed;
}
