#include "operatornodestub.h"

OperatorNodeStub::OperatorNodeStub(bool error) :
	m_error(error)
{ }

double OperatorNodeStub::getValue(bool &error) const
{
	error = m_error;
	return 0;
}