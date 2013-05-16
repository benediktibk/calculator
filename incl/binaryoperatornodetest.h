#ifndef BINARYOPERATORNODETEST_H
#define BINARYOPERATORNODETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class BinaryOperatorNodeTest :
		public CPPUNIT_NS::TestFixture
{
	 CPPUNIT_TEST_SUITE(BinaryOperatorNodeTest);
	 CPPUNIT_TEST(constructor_validType_leftAndRightNotSet);
	 CPPUNIT_TEST(leftAndRightSet_onlyLeftSet_false);
	 CPPUNIT_TEST(leftAndRightSet_onlyRightSet_false);
	 CPPUNIT_TEST(leftAndRightSet_bothSet_true);
	 CPPUNIT_TEST(getValue_additionAndLeftValue6AndRightValue2_8);
	 CPPUNIT_TEST(getValue_subtractionAndLeftValue6AndRightValue2_4);
	 CPPUNIT_TEST(getValue_multiplicationAndLeftValue6AndRightValue2_12);
	 CPPUNIT_TEST(getValue_divisionAndLeftValue6AndRightValue2_3);
	 CPPUNIT_TEST(getValue_potencyAndLeftValue6AndRightValue2_36);
//	 CPPUNIT_TEST(getValue_additionAndTwoValueNodesSet_noError);
//	 CPPUNIT_TEST(getValue_subtractionAndTwoValueNodesSet_noError);
//	 CPPUNIT_TEST(getValue_multiplicationAndTwoValueNodesSet_noError);
//	 CPPUNIT_TEST(getValue_divisionAndTwoNonZeroValueNodesSet_noError);
//	 CPPUNIT_TEST(getValue_divisionAndRightValueZero_error);
	 CPPUNIT_TEST_SUITE_END();

private:
	 void constructor_validType_leftAndRightNotSet();
	 void leftAndRightSet_onlyLeftSet_false();
	 void leftAndRightSet_onlyRightSet_false();
	 void leftAndRightSet_bothSet_true();
	 void getValue_additionAndLeftValue6AndRightValue2_8();
	 void getValue_subtractionAndLeftValue6AndRightValue2_4();
	 void getValue_multiplicationAndLeftValue6AndRightValue2_12();
	 void getValue_divisionAndLeftValue6AndRightValue2_3();
	 void getValue_potencyAndLeftValue6AndRightValue2_36();
	 void getValue_additionAndTwoValueNodesSet_noError();
	 void getValue_subtractionAndTwoValueNodesSet_noError();
	 void getValue_multiplicationAndTwoValueNodesSet_noError();
	 void getValue_divisionAndTwoNonZeroValueNodesSet_noError();
	 void getValue_divisionAndRightValueZero_error();
};

#endif
