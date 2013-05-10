#ifndef BINARYOPERATORNODE_H
#define BINARYOPERATORNODE_H

#include "operatornode.h"
#include "binaryoperationtype.h"

class BinaryOperatorNode :
		public OperatorNode
{
public:
	BinaryOperatorNode(BinaryOperationType operationType);
	virtual ~BinaryOperatorNode();

	virtual void addNodesInOrder(std::vector<const OperatorNode*> &nodes) const;
	void setLeftNode(OperatorNode *node);
	void setRightNode(OperatorNode *node);
	bool leftAndRightSet() const;

private:
	const BinaryOperationType m_operationType;
	OperatorNode *m_left;
	OperatorNode *m_right;
};

#endif
