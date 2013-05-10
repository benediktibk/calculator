#include "binaryoperatornode.h"
#include <assert.h>

using namespace std;

BinaryOperatorNode::BinaryOperatorNode(BinaryOperationType operationType) :
	m_operationType(operationType),
	m_left(0),
	m_right(0)
{ }

BinaryOperatorNode::~BinaryOperatorNode()
{
	delete m_left;
	m_left = 0;

	delete m_right;
	m_right = 0;
}

void BinaryOperatorNode::addNodesInOrder(vector<const OperatorNode *> &nodes) const
{
	assert(leftAndRightSet());

	m_left->addNodesInOrder(nodes);
	nodes.push_back(this);
	m_right->addNodesInOrder(nodes);
}

void BinaryOperatorNode::setLeftNode(OperatorNode *node)
{
	assert(m_left == 0);

	m_left = node;
}

void BinaryOperatorNode::setRightNode(OperatorNode *node)
{
	assert(m_right == 0);

	m_right = node;
}

bool BinaryOperatorNode::leftAndRightSet() const
{
	return m_left != 0 && m_right != 0;
}