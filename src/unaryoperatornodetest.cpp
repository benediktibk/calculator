#include "unaryoperatornodetest.h"
#include "unaryoperatornode.h"
#include "valueoperatornode.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(UnaryOperatorNodeTest);

void UnaryOperatorNodeTest::getValue_sineAndNode0_0()
{
    UnaryOperatorNode node(UnaryOperationTypeSine);
    node.setNode(new ValueOperatorNode(0));


    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(), 0.0001);
}

void UnaryOperatorNodeTest::getValue_cosineAndNode0_1()
{
    UnaryOperatorNode node(UnaryOperationTypeCosine);
    node.setNode(new ValueOperatorNode(0));


    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(), 0.0001);
}

void UnaryOperatorNodeTest::getValue_tangensAndNode0_0()
{
    UnaryOperatorNode node(UnaryOperationTypeTangens);
    node.setNode(new ValueOperatorNode(0));


    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(), 0.0001);
}

void UnaryOperatorNodeTest::getValue_exponentialAndNode0_1()
{
    UnaryOperatorNode node(UnaryOperationTypeExponential);
    node.setNode(new ValueOperatorNode(0));


    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(), 0.0001);
}

void UnaryOperatorNodeTest::getValue_exponentialAndNode1_271828()
{
    UnaryOperatorNode node(UnaryOperationTypeExponential);
    node.setNode(new ValueOperatorNode(1));


    CPPUNIT_ASSERT_DOUBLES_EQUAL(2.71828, node.getValue(), 0.0001);
}
