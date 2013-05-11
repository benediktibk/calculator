#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include <vector>

class OperatorNode
{
public:
	virtual ~OperatorNode();

	virtual void addNodesInOrder(std::vector<const OperatorNode*> &nodes) const = 0;
	virtual double getValue() const = 0;
};

#endif
