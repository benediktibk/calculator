#include "operatortreetest.h"
#include "operatortree.h"
#include "constant.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(OperatorTreeTest);

void OperatorTreeTest::constructor_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_notParsingFailed()
{
	string expression("5.2+6*(4-2)-3/2.423");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT(!tree.parsingFailed());
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

void OperatorTreeTest::constructor_stringWithTwoOperatorsInARow_parsingFailed()
{
	string expression("4+*5");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT(tree.parsingFailed());
}

void OperatorTreeTest::constructor_missingClosingBracket_parsingFailed()
{
	string expression("2*(4-3");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT(tree.parsingFailed());
}

void OperatorTreeTest::constructor_commaInsteadOfPoint_parsingFailed()
{
	string expression("4,65");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT(tree.parsingFailed());
}

void OperatorTreeTest::constructor_missingOpeningBracket_parsingFailed()
{
	string expression("4+5)*2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT(tree.parsingFailed());
}

void OperatorTreeTest::calculateValue_potency_correctValue()
{
	string expression("2^3");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(8, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_twoPotencysInARow_correctValue()
{
	string expression("4^3^2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(262144, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_additionAndPotency_correctValue()
{
	string expression("4+3^2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(13, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_additionAndPotencyWithParentheses_correctValue()
{
	string expression("(4+3)^2");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(49, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_twoPotenciesUnrelatedTogether_correctValue()
{
    string expression("(4+3)^2+5^4*2");

    OperatorTree tree(expression);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(1299, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_additionAndSineWithParentheses_correctValue()
{
    string expression("sin((4+3)^2)+1");

    OperatorTree tree(expression);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.046247347, tree.calculateValue(), 0.0001);
}

void OperatorTreeTest::calculateValue_additionAndPotencyAndSineAndExpWithParentheses_correctValue()
{
    string expression("2^2*(sin(sin(sin(0)))+exp(0))");

    OperatorTree tree(expression);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(4, tree.calculateValue(), 0.001);
}

void OperatorTreeTest::calculateValue_CosineWithParentheses_correctValue()
{
    string expression("cos(3.141592654)");

    OperatorTree tree(expression);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(-1, tree.calculateValue(), 0.0001);
}

void OperatorTreeTest::calculateValue_TangensWithParentheses_correctValue()
{
    string expression("tan(1)");

    OperatorTree tree(expression);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.557408, tree.calculateValue(), 0.001);
}

void OperatorTreeTest::test_constantPi()
{
    string expression("pi");

    OperatorTree tree(expression);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(pi, tree.calculateValue(), 0.000001);
}

void OperatorTreeTest::calculateValue_piAndAddition_correctValue()
{
    string expression("pi+2");

    OperatorTree tree(expression);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(5.141592654, tree.calculateValue(), 0.000001);
}
