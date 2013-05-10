#include "valueoperatornode.h"

using namespace std;

ValueOperatorNode::ValueOperatorNode(double value) :
	m_value(value)
{ }

void ValueOperatorNode::addNodesInOrder(vector<const OperatorNode *> &nodes) const
{
	nodes.push_back(this);
}

double ValueOperatorNode::getValue() const
{
	return m_value;
}
