#include "operatortreetest.h"
#include "operatortree.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(OperatorTreeTest);

void OperatorTreeTest::constructor_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_notParsingFailed()
{
	string expression("5.2+6*(4-2)-3/2.423");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT(!tree.parsingFailed());
}

void OperatorTreeTest::getNodesInOrder_emptyExpression_resultSizeIs1()
{
	OperatorTree tree("");

	vector<const OperatorNode*> nodes = tree.getNodesInOrder();

	CPPUNIT_ASSERT_EQUAL((size_t)1, nodes.size());
}

void OperatorTreeTest::getNodesInOrder_oneValue_resultSizeIs1()
{
	OperatorTree tree("34");

	vector<const OperatorNode*> nodes = tree.getNodesInOrder();

	CPPUNIT_ASSERT_EQUAL((size_t)1, nodes.size());
}

void OperatorTreeTest::calculateValue_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_correctValue()
{
	string expression("5.2+6*(4-2)-3/2.423");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(15.9618654560, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_addition_correctValue()
{
	string expression("2+3");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(5, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_multiplication_correctValue()
{
	string expression("2*4");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(8, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_subtraction_correctValue()
{
	string expression("5-2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(3, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_division_correctValue()
{
	string expression("8/4");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(2, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_additionAndMultiplication_correctValue()
{
	string expression("4+3*2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(10, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_additionAndMultiplicationWithParentheses_correctValue()
{
	string expression("(4+3)*2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(14, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_nestedParentheses_correctValue()
{
	string expression("(20-3*(1+3)+7)/2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(7.5, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_twoDivisionsInARow_correctValue()
{
	string expression("8/4/2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(1, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_twoSubtractionsInARow_correctValue()
{
	string expression("8-4-2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(2, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_subtractionAndAddition_correctValue()
{
	string expression("8-4+2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(6, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_divisionAndMultiplication_correctValue()
{
	string expression("8/4*2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(4, tree.calculateValue(), 0.000001);
}
