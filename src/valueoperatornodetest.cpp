#include "valueoperatornodetest.h"
#include "valueoperatornode.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(ValueOperatorNodeTest);

void ValueOperatorNodeTest::constructor_5_valueIs5()
{
	ValueOperatorNode node(5);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(5, node.getValue(), 0.0001);
}
