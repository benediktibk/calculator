#include "unaryoperatornodetest.h"
#include "unaryoperatornode.h"
#include "valueoperatornode.h"
#include "operatornodestub.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(UnaryOperatorNodeTest);

void UnaryOperatorNodeTest::getValue_sineAndNode0_0()
{
	UnaryOperatorNode node(UnaryOperationTypeSine, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(0));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_cosineAndNode0_1()
{
	UnaryOperatorNode node(UnaryOperationTypeCosine, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(0));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_tangensAndNode0_0()
{
	UnaryOperatorNode node(UnaryOperationTypeTangens, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(0));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_exponentialAndNode0_1()
{
	UnaryOperatorNode node(UnaryOperationTypeExponential, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(0));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_exponentialAndNode1_271828()
{
	UnaryOperatorNode node(UnaryOperationTypeExponential, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(1));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(2.71828, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_nodeProducesNoError_noError()
{
	UnaryOperatorNode node(UnaryOperationTypeExponential, AngleTypeRadiant);
	node.setNode(new OperatorNodeStub(false));
	bool error;

	node.getValue(error);

	CPPUNIT_ASSERT(!error);
}

void UnaryOperatorNodeTest::getValue_nodeProducesError_error()
{
	UnaryOperatorNode node(UnaryOperationTypeExponential, AngleTypeRadiant);
	node.setNode(new OperatorNodeStub(true));
	bool error;

	node.getValue(error);

	CPPUNIT_ASSERT(error);
}

void UnaryOperatorNodeTest::getValue_sineInDegAndNode360_0()
{
	UnaryOperatorNode node(UnaryOperationTypeSine, AngleTypeDegree);
	node.setNode(new ValueOperatorNode(360));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_cosineInDegAndNode360_1()
{
	UnaryOperatorNode node(UnaryOperationTypeCosine, AngleTypeDegree);
	node.setNode(new ValueOperatorNode(360));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_expOf1AndDeg_271828()
{
	UnaryOperatorNode node(UnaryOperationTypeExponential, AngleTypeDegree);
	node.setNode(new ValueOperatorNode(1));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(2.71828, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_asinOf1AndRadiant_halfOfPi()
{
	UnaryOperatorNode node(UnaryOperationTypeArcSine, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(1));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.57079632679, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_acosOf1AndRadiant_0()
{
	UnaryOperatorNode node(UnaryOperationTypeArcCosine, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(1));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_atanOf0AndRadiant_0()
{
	UnaryOperatorNode node(UnaryOperationTypeArcTangens, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(0));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(0, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_ln271828AndRadiant_1()
{
	UnaryOperatorNode node(UnaryOperationTypeLogarithmNaturalis, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(2.71828));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_asinOf1AndDegree_90()
{
	UnaryOperatorNode node(UnaryOperationTypeArcSine, AngleTypeDegree);
	node.setNode(new ValueOperatorNode(1));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(90, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_acosOf05AndDegree_60()
{
	UnaryOperatorNode node(UnaryOperationTypeArcCosine, AngleTypeDegree);
	node.setNode(new ValueOperatorNode(0.5));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(60, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_atanOf05AndDegree_2656505()
{
	UnaryOperatorNode node(UnaryOperationTypeArcTangens, AngleTypeDegree);
	node.setNode(new ValueOperatorNode(0.5));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(26.56505117707798, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_ln271828AndDegree_1()
{
	UnaryOperatorNode node(UnaryOperationTypeLogarithmNaturalis, AngleTypeDegree);
	node.setNode(new ValueOperatorNode(2.71828));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(1, node.getValue(error), 0.0001);
}

void UnaryOperatorNodeTest::getValue_lnOfNegativeValue_error()
{
	UnaryOperatorNode node(UnaryOperationTypeLogarithmNaturalis, AngleTypeRadiant);
	node.setNode(new ValueOperatorNode(-4));
	bool error;

	node.getValue(error);

	CPPUNIT_ASSERT(error);
}
