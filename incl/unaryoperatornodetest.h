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
};


#endif
