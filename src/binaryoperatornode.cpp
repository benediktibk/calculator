#include "binaryoperatornode.h"
#include <assert.h>
#include <math.h>

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

double BinaryOperatorNode::getValue(bool &error) const
{
	assert(leftAndRightSet());

	double leftValue = m_left->getValue(error);
	if (error)
		return 0;

	double rightValue = m_right->getValue(error);
	if (error)
		return 0;

	switch(m_operationType)
	{
	case BinaryOperationTypeAddition:
		return leftValue + rightValue;
	case BinaryOperationTypeSubtraction:
		return leftValue - rightValue;
	case BinaryOperationTypeMultiplication:
		return leftValue * rightValue;
	case BinaryOperationTypeDivision:
		if (rightValue == 0)
		{
			error = true;
			return 0;
		}
		return leftValue / rightValue;
	case BinaryOperationTypePotency:
		return pow(leftValue, rightValue);
	}

	assert(false);
	return 0;
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
