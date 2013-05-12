#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include <vector>

class OperatorNode
{
public:
	virtual ~OperatorNode();

	virtual double getValue() const = 0;
};

#endif
