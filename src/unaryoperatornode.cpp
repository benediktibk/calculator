
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
	double result;

	if (	m_angleType == AngleTypeDegree &&
			(	m_operationType == UnaryOperationTypeSine ||
				m_operationType == UnaryOperationTypeCosine ||
				m_operationType == UnaryOperationTypeTangens))
		nodeValue *= pi/180;

	switch(m_operationType)
	{
	case UnaryOperationTypeSine:
		result = sin(nodeValue);
		break;
	case UnaryOperationTypeCosine:
		result = cos(nodeValue);
		break;
	case UnaryOperationTypeTangens:
		result = tan(nodeValue);
		break;
	case UnaryOperationTypeExponential:
		result = exp(nodeValue);
		break;
	case UnaryOperationTypeArcSine:
		result = asin(nodeValue);
		break;
	case UnaryOperationTypeArcCosine:
		result = acos(nodeValue);
		break;
	case UnaryOperationTypeArcTangens:
		result = atan(nodeValue);
		break;
	case UnaryOperationTypeLogarithmNaturalis:
		result = log(nodeValue);
		break;
	}

	if (	m_angleType == AngleTypeDegree &&
			(	m_operationType == UnaryOperationTypeArcSine ||
				m_operationType == UnaryOperationTypeArcCosine ||
				m_operationType == UnaryOperationTypeArcTangens))
		result *= 180/pi;

	return result;
}

void UnaryOperatorNode::setNode(OperatorNode *node)
{
	assert(m_node == 0);

	m_node = node;
}


