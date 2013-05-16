#ifndef OPERATORNODESTUB_H
#define OPERATORNODESTUB_H

#include "operatornode.h"

class OperatorNodeStub :
		public OperatorNode
{
public:
	OperatorNodeStub(bool error);

	virtual double getValue(bool &error) const;

private:
	bool m_error;
};

#endif
