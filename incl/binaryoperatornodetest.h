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
	 CPPUNIT_TEST(addNodesInOrder_leftAndRightValueNodeSet_resultSizeIs3);
	 CPPUNIT_TEST(addNodesInOrder_leftAndRightValueNodeSet_secondNodeIsRoot);
	 CPPUNIT_TEST_SUITE_END();

private:
	 void constructor_validType_leftAndRightNotSet();
	 void leftAndRightSet_onlyLeftSet_false();
	 void leftAndRightSet_onlyRightSet_false();
	 void leftAndRightSet_bothSet_true();
	 void addNodesInOrder_leftAndRightValueNodeSet_resultSizeIs3();
	 void addNodesInOrder_leftAndRightValueNodeSet_secondNodeIsRoot();
};

#endif
