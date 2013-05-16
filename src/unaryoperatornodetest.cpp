#include "unaryoperatornodetest.h"
#include "unaryoperatornode.h"
#include "valueoperatornode.h"
#include "operatornodestub.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(UnaryOperatorNodeTest);

void UnaryOperatorNodeTest::getValue_sineAndNode0_0()
{
	UnaryOperatorNode node(UnaryOperationTypeSine);
	node.setNode(new ValueOperatorNode(0));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_cosineAndNode0_1()
{
	UnaryOperatorNode node(UnaryOperationTypeCosine);
	node.setNode(new ValueOperatorNode(0));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_tangensAndNode0_0()
{
	UnaryOperatorNode node(UnaryOperationTypeTangens);
	node.setNode(new ValueOperatorNode(0));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_exponentialAndNode0_1()
{
	UnaryOperatorNode node(UnaryOperationTypeExponential);
	node.setNode(new ValueOperatorNode(0));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_exponentialAndNode1_271828()
{
	UnaryOperatorNode node(UnaryOperationTypeExponential);
	node.setNode(new ValueOperatorNode(1));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(2.71828, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_nodeProducesNoError_noError()
{
	UnaryOperatorNode node(UnaryOperationTypeExponential);
	node.setNode(new OperatorNodeStub(false));
	bool error;

	node.getValue(error);

	CPPUNIT_ASSERT(!error);
}

void UnaryOperatorNodeTest::getValue_nodeProducesError_error()
{
	UnaryOperatorNode node(UnaryOperationTypeExponential);
	node.setNode(new OperatorNodeStub(true));
	bool error;

	node.getValue(error);

	CPPUNIT_ASSERT(error);
}

void UnaryOperatorNodeTest::getValue_sineInDegAndNode360_0()
{
    UnaryOperatorNode node(UnaryOperationTypeSine);
    node.changeModeDegRad(true);
    node.setNode(new ValueOperatorNode(360));
    bool error;

    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_cosineInDegAndNode360_1()
{
    UnaryOperatorNode node(UnaryOperationTypeCosine);
    node.changeModeDegRad(true);
    node.setNode(new ValueOperatorNode(360));
    bool error;

    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(error), 0.0001);
}
