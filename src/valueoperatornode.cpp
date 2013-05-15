#include "valueoperatornode.h"

using namespace std;

ValueOperatorNode::ValueOperatorNode(double value) :
	m_value(value)
{ }

double ValueOperatorNode::getValue(bool &error) const
{
	error = false;
	return m_value;
}
