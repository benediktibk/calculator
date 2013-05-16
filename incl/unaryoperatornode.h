#ifndef UNARYOPERATORNODE_H
#define UNARYOPERATORNODE_H


#include "operatornode.h"
#include "unaryoperationtype.h"

class UnaryOperatorNode :
		public OperatorNode
{
public:
	UnaryOperatorNode(UnaryOperationType operationType);
	virtual ~UnaryOperatorNode();

    void changeModeDegRad(bool mode);
    virtual double getValue(bool &error) const;
	void setNode(OperatorNode *node);

private:
	const UnaryOperationType m_operationType;
	OperatorNode *m_node;
    bool m_changeToDegree;

};


#endif // UNARYOPERATORNODE_H
