#include "binaryoperatornodetest.h"
#include "binaryoperatornode.h"
#include "valueoperatornode.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(BinaryOperatorNodeTest);

void BinaryOperatorNodeTest::constructor_validType_leftAndRightNotSet()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);

	CPPUNIT_ASSERT(!node.leftAndRightSet());
}

void BinaryOperatorNodeTest::leftAndRightSet_onlyLeftSet_false()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);
	node.setLeftNode(new ValueOperatorNode(3));

	CPPUNIT_ASSERT(!node.leftAndRightSet());
}

void BinaryOperatorNodeTest::leftAndRightSet_onlyRightSet_false()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);
	node.setRightNode(new ValueOperatorNode(3));

	CPPUNIT_ASSERT(!node.leftAndRightSet());
}

void BinaryOperatorNodeTest::leftAndRightSet_bothSet_true()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);
	node.setLeftNode(new ValueOperatorNode(3));
	node.setRightNode(new ValueOperatorNode(3));

	CPPUNIT_ASSERT(node.leftAndRightSet());
}

void BinaryOperatorNodeTest::addNodesInOrder_leftAndRightValueNodeSet_resultSizeIs3()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);
	node.setLeftNode(new ValueOperatorNode(3));
	node.setRightNode(new ValueOperatorNode(3));
	vector<const OperatorNode*> result;

	node.addNodesInOrder(result);

	CPPUNIT_ASSERT_EQUAL((size_t)3, result.size());
}

void BinaryOperatorNodeTest::addNodesInOrder_leftAndRightValueNodeSet_secondNodeIsRoot()
{
	BinaryOperatorNode node(BinaryOperationTypeAddition);
	const OperatorNode *nodeConst = &node;
	node.setLeftNode(new ValueOperatorNode(3));
	node.setRightNode(new ValueOperatorNode(3));
	vector<const OperatorNode*> result;

	node.addNodesInOrder(result);

	CPPUNIT_ASSERT_EQUAL(nodeConst, result[1]);
}