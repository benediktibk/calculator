#ifndef UNARYOPERATORNODETEST_H
#define UNARYOPERATORNODETEST_H



#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class UnaryOperatorNodeTest :
		public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(UnaryOperatorNodeTest);
	CPPUNIT_TEST(getValue_sineAndNode0_0);
	CPPUNIT_TEST(getValue_cosineAndNode0_1);
	CPPUNIT_TEST(getValue_tangensAndNode0_0);
	CPPUNIT_TEST(getValue_exponentialAndNode0_1);
	CPPUNIT_TEST(getValue_exponentialAndNode1_271828);
	CPPUNIT_TEST(getValue_nodeProducesNoError_noError);
	CPPUNIT_TEST(getValue_nodeProducesError_error);
	CPPUNIT_TEST(getValue_sineInDegAndNode360_0);
	CPPUNIT_TEST(getValue_cosineInDegAndNode360_1);
	CPPUNIT_TEST(getValue_expOf1AndDeg_271828);
	CPPUNIT_TEST(getValue_asinOf1AndRadiant_halfOfPi);
	CPPUNIT_TEST(getValue_acosOf1AndRadiant_0);
	CPPUNIT_TEST(getValue_atanOf0AndRadiant_0);
	CPPUNIT_TEST(getValue_ln271828AndRadiant_1);
	CPPUNIT_TEST(getValue_asinOf1AndDegree_90);
	CPPUNIT_TEST(getValue_acosOf05AndDegree_60);
	CPPUNIT_TEST(getValue_atanOf05AndDegree_2656505);
	CPPUNIT_TEST(getValue_ln271828AndDegree_1);
	CPPUNIT_TEST_SUITE_END();

private:
	void getValue_sineAndNode0_0();
	void getValue_cosineAndNode0_1();
	void getValue_tangensAndNode0_0();
	void getValue_exponentialAndNode0_1();
	void getValue_exponentialAndNode1_271828();
	void getValue_nodeProducesNoError_noError();
	void getValue_nodeProducesError_error();
	void getValue_sineInDegAndNode360_0();
	void getValue_cosineInDegAndNode360_1();
	void getValue_expOf1AndDeg_271828();
	void getValue_asinOf1AndRadiant_halfOfPi();
	void getValue_acosOf1AndRadiant_0();
	void getValue_atanOf0AndRadiant_0();
	void getValue_ln271828AndRadiant_1();
	void getValue_asinOf1AndDegree_90();
	void getValue_acosOf05AndDegree_60();
	void getValue_atanOf05AndDegree_2656505();
	void getValue_ln271828AndDegree_1();
};


#endif
