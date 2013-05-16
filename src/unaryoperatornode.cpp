
#include "unaryoperatornode.h"
#include <assert.h>
#include <math.h>
#include "constant.h"

using namespace std;

UnaryOperatorNode::UnaryOperatorNode(UnaryOperationType operationType, AngleType angleType) :
	m_operationType(operationType),
	m_node(0),
	m_angleType(angleType)
{ }

UnaryOperatorNode::~UnaryOperatorNode()
{
	delete m_node;
	m_node = 0;
}

double UnaryOperatorNode::getValue(bool &error) const
{
	assert(m_node != 0);

	error = false;
	double nodeValue = m_node->getValue(error);

	if (	m_angleType == AngleTypeDegree &&
			(	m_operationType == UnaryOperationTypeSine ||
				m_operationType == UnaryOperationTypeCosine ||
				m_operationType == UnaryOperationTypeTangens))
		nodeValue *= pi/180;

	switch(m_operationType)
	{
	case UnaryOperationTypeSine:
		return sin(nodeValue);
	case UnaryOperationTypeCosine:
		return cos(nodeValue);
	case UnaryOperationTypeTangens:
		return tan(nodeValue);
	case UnaryOperationTypeExponential:
		return exp(nodeValue);
	}

	assert(false);
	return 0;
}

void UnaryOperatorNode::setNode(OperatorNode *node)
{
	assert(m_node == 0);

	m_node = node;
}


