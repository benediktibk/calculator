#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include <vector>

class OperatorNode
{
public:
	virtual ~OperatorNode();

	virtual double getValue(bool &error) const = 0;
};

#endif
