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
