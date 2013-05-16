#include "binaryoperatornodetest.h"
#include "binaryoperatornode.h"
#include "valueoperatornode.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(BinaryOperatorNodeTest);

void BinaryOperatorNodeTest::constructor_validType_leftAndRightNotSet()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);

	CPPUNIT_ASSERT(!node.leftAndRightSet());
}

void BinaryOperatorNodeTest::leftAndRightSet_onlyLeftSet_false()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);
	node.setLeftNode(new ValueOperatorNode(3));

	CPPUNIT_ASSERT(!node.leftAndRightSet());
}

void BinaryOperatorNodeTest::leftAndRightSet_onlyRightSet_false()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);
	node.setRightNode(new ValueOperatorNode(3));

	CPPUNIT_ASSERT(!node.leftAndRightSet());
}

void BinaryOperatorNodeTest::leftAndRightSet_bothSet_true()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);
	node.setLeftNode(new ValueOperatorNode(3));
	node.setRightNode(new ValueOperatorNode(3));

	CPPUNIT_ASSERT(node.leftAndRightSet());
}

void BinaryOperatorNodeTest::getValue_additionAndLeftValue6AndRightValue2_8()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);
	node.setLeftNode(new ValueOperatorNode(6));
	node.setRightNode(new ValueOperatorNode(2));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(8, node.getValue(error), 0.0001);
}

void BinaryOperatorNodeTest::getValue_subtractionAndLeftValue6AndRightValue2_4()
{
	BinaryOperatorNode node(BinaryOperationTypeSubtraction);
	node.setLeftNode(new ValueOperatorNode(6));
	node.setRightNode(new ValueOperatorNode(2));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(4, node.getValue(error), 0.0001);
}

void BinaryOperatorNodeTest::getValue_multiplicationAndLeftValue6AndRightValue2_12()
{
	BinaryOperatorNode node(BinaryOperationTypeMultiplication);
	node.setLeftNode(new ValueOperatorNode(6));
	node.setRightNode(new ValueOperatorNode(2));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(12, node.getValue(error), 0.0001);
}

void BinaryOperatorNodeTest::getValue_divisionAndLeftValue6AndRightValue2_3()
{
	BinaryOperatorNode node(BinaryOperationTypeDivision);
	node.setLeftNode(new ValueOperatorNode(6));
	node.setRightNode(new ValueOperatorNode(2));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(3, node.getValue(error), 0.0001);
}

void BinaryOperatorNodeTest::getValue_potencyAndLeftValue6AndRightValue2_36()
{
	BinaryOperatorNode node(BinaryOperationTypePotency);
	node.setLeftNode(new ValueOperatorNode(6));
	node.setRightNode(new ValueOperatorNode(2));
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(36, node.getValue(error), 0.0001);
}
