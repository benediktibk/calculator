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

    virtual double getValue() const;
    void setLeftNode(OperatorNode *node);
    void setRightNode(OperatorNode *node);


private:
    const UnaryOperationType m_operationType;
    OperatorNode *m_left;
    OperatorNode *m_right;
};


#endif // UNARYOPERATORNODE_H
