
#include "unaryoperatornode.h"
#include <assert.h>
#include <math.h>

using namespace std;

UnaryOperatorNode::UnaryOperatorNode(UnaryOperationType operationType) :
    m_operationType(operationType),
    m_node(0)
{ }

UnaryOperatorNode::~UnaryOperatorNode()
{
    delete m_node;
    m_node = 0;
}

double UnaryOperatorNode::getValue() const
{
    assert(m_node != 0);

    double nodeValue = m_node->getValue();

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


