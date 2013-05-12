#include "valueoperatornode.h"

using namespace std;

ValueOperatorNode::ValueOperatorNode(double value) :
	m_value(value)
{ }

double ValueOperatorNode::getValue() const
{
	return m_value;
}
