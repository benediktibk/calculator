#ifndef OPERATORTREETEST_H
#define OPERATORTREETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class OperatorTreeTest :
		public CPPUNIT_NS::TestFixture
{
	 CPPUNIT_TEST_SUITE(OperatorTreeTest);
	 CPPUNIT_TEST(constructor_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_notParsingFailed);
	 CPPUNIT_TEST(getNodesInOrder_emptyExpression_resultSizeIs1);
	 CPPUNIT_TEST(getNodesInOrder_oneValue_resultSizeIs1);
	 CPPUNIT_TEST(calculateValue_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_addition_correctValue);
	 CPPUNIT_TEST(calculateValue_multiplication_correctValue);
	 CPPUNIT_TEST(calculateValue_subtraction_correctValue);
	 CPPUNIT_TEST(calculateValue_division_correctValue);
	 CPPUNIT_TEST(calculateValue_additionAndMultiplication_correctValue);
	 CPPUNIT_TEST(calculateValue_additionAndMultiplicationWithParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_nestedParentheses_correctValue);
	 CPPUNIT_TEST_SUITE_END();

private:
	 void constructor_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_notParsingFailed();
	 void getNodesInOrder_emptyExpression_resultSizeIs1();
	 void getNodesInOrder_oneValue_resultSizeIs1();
	 void calculateValue_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_correctValue();
	 void calculateValue_addition_correctValue();
	 void calculateValue_multiplication_correctValue();
	 void calculateValue_subtraction_correctValue();
	 void calculateValue_division_correctValue();
	 void calculateValue_additionAndMultiplication_correctValue();
	 void calculateValue_additionAndMultiplicationWithParentheses_correctValue();
	 void calculateValue_nestedParentheses_correctValue();
};

#endif
