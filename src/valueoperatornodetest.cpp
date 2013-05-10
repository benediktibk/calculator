#include "valueoperatornodetest.h"
#include "valueoperatornode.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(ValueOperatorNodeTest);

void ValueOperatorNodeTest::constructor_5_valueIs5()
{
	ValueOperatorNode node(5);

	CPPUNIT_ASSERT_DOUBLES_EQUAL(5, node.getValue(), 0.0001);
}

void ValueOperatorNodeTest::addNodesInOrder_emptyVector_vectorHasSize1()
{
	vector<const OperatorNode*> nodes;
	ValueOperatorNode node(3);

	node.addNodesInOrder(nodes);

	CPPUNIT_ASSERT_EQUAL((size_t)1, nodes.size());
}
