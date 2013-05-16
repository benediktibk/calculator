
#include "unaryoperatornode.h"
#include <assert.h>
#include <math.h>
#include "constant.h"

using namespace std;

UnaryOperatorNode::UnaryOperatorNode(UnaryOperationType operationType) :
	m_operationType(operationType),
    m_node(0),
    m_changeToDegree(false)
{ }

UnaryOperatorNode::~UnaryOperatorNode()
{
	delete m_node;
	m_node = 0;
}

void UnaryOperatorNode::changeModeDegRad(bool mode)
{
    m_changeToDegree = mode;
}

double UnaryOperatorNode::getValue(bool &error) const
{
	assert(m_node != 0);

	error = false;
	double nodeValue = m_node->getValue(error);

    if(m_changeToDegree == true)
    {
        nodeValue = nodeValue * 180 / (2*pi);
    }

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


