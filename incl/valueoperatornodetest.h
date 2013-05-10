#ifndef VALUEOPERATORNODETEST_H
#define VALUEOPERATORNODETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class ValueOperatorNodeTest :
		public CPPUNIT_NS::TestFixture
{
	 CPPUNIT_TEST_SUITE(ValueOperatorNodeTest);
	 CPPUNIT_TEST(constructor_5_valueIs5);
	 CPPUNIT_TEST(addNodesInOrder_emptyVector_vectorHasSize1);
	 CPPUNIT_TEST_SUITE_END();

private:
	 void constructor_5_valueIs5();
	 void addNodesInOrder_emptyVector_vectorHasSize1();
};

#endif
