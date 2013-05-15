#include "valueoperatornodetest.h"
#include "valueoperatornode.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(ValueOperatorNodeTest);

void ValueOperatorNodeTest::constructor_5_valueIs5()
{
	ValueOperatorNode node(5);
	bool error;

	CPPUNIT_ASSERT_DOUBLES_EQUAL(5, node.getValue(error), 0.0001);
}

void ValueOperatorNodeTest::getValue_5_noError()
{
	ValueOperatorNode node(5);
	bool error;

	node.getValue(error);

	CPPUNIT_ASSERT(!error);
}
