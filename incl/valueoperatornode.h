#ifndef VALUEOPERATORNODE_H
#define VALUEOPERATORNODE_H

#include <string>
#include "operatornode.h"

class ValueOperatorNode :
		public OperatorNode
{
public:
	ValueOperatorNode(double value);

	virtual double getValue(bool &error) const;

private:
	const double m_value;
};

#endif
