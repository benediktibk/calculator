#include "operatortreetest.h"
#include "operatortree.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(OperatorTreeTest);

void OperatorTreeTest::constructor_validStringWithAdditionSubtractionMultiplicationDivisionAndParenthesis_notParsingFailed()
{
	string expression("5.2+6*(4-2)-3/2.423");

	OperatorTree tree(expression);

	CPPUNIT_ASSERT(!tree.parsingFailed());
}

void OperatorTreeTest::getNodesInOrder_emptyExpression_resultSizeIs0()
{
	OperatorTree tree("");

	vector<const OperatorNode*> nodes = tree.getNodesInOrder();

	CPPUNIT_ASSERT_EQUAL((size_t)0, nodes.size());
}

void OperatorTreeTest::getNOdesInOrder_oneValue_resultSizeIs1()
{
	OperatorTree tree("34");

	vector<const OperatorNode*> nodes = tree.getNodesInOrder();

	CPPUNIT_ASSERT_EQUAL((size_t)1, nodes.size());
}
