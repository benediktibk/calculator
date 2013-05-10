#ifndef OPERATORTREETEST_H
#define OPERATORTREETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class OperatorTreeTest :
		public CPPUNIT_NS::TestFixture
{
	 CPPUNIT_TEST_SUITE(OperatorTreeTest);
	 CPPUNIT_TEST(constructor_validStringWithAdditionSubtractionMultiplicationDivisionAndParenthesis_notParsingFailed);
	 CPPUNIT_TEST(getNodesInOrder_emptyExpression_resultSizeIs0);
	 CPPUNIT_TEST(getNOdesInOrder_oneValue_resultSizeIs1);
	 CPPUNIT_TEST_SUITE_END();

private:
	 void constructor_validStringWithAdditionSubtractionMultiplicationDivisionAndParenthesis_notParsingFailed();
	 void getNodesInOrder_emptyExpression_resultSizeIs0();
	 void getNOdesInOrder_oneValue_resultSizeIs1();
};

#endif
