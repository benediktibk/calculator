#ifndef OPERATORTREETEST_H
#define OPERATORTREETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class OperatorTreeTest :
		public CPPUNIT_NS::TestFixture
{
	 CPPUNIT_TEST_SUITE(OperatorTreeTest);
	 CPPUNIT_TEST(constructor_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_notParsingFailed);
	 CPPUNIT_TEST(calculateValue_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_noError);
	 CPPUNIT_TEST(calculateValue_addition_correctValue);
	 CPPUNIT_TEST(calculateValue_multiplication_correctValue);
	 CPPUNIT_TEST(calculateValue_subtraction_correctValue);
	 CPPUNIT_TEST(calculateValue_division_correctValue);
	 CPPUNIT_TEST(calculateValue_additionAndMultiplication_correctValue);
	 CPPUNIT_TEST(calculateValue_additionAndMultiplicationWithParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_nestedParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_twoDivisionsInARow_correctValue);
	 CPPUNIT_TEST(calculateValue_twoSubtractionsInARow_correctValue);
	 CPPUNIT_TEST(calculateValue_subtractionAndAddition_correctValue);
	 CPPUNIT_TEST(calculateValue_divisionAndMultiplication_correctValue);
	 CPPUNIT_TEST(constructor_stringWithTwoOperatorsInARow_parsingFailed);
	 CPPUNIT_TEST(constructor_missingClosingBracket_parsingFailed);
	 CPPUNIT_TEST(constructor_commaInsteadOfPoint_parsingFailed);
	 CPPUNIT_TEST(constructor_missingOpeningBracket_parsingFailed);
	 CPPUNIT_TEST(calculateValue_potency_correctValue);
	 CPPUNIT_TEST(calculateValue_twoPotencysInARow_correctValue);
	 CPPUNIT_TEST(calculateValue_additionAndPotency_correctValue);
	 CPPUNIT_TEST(calculateValue_additionAndPotencyWithParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_twoPotenciesUnrelatedTogether_correctValue);
	 CPPUNIT_TEST(calculateValue_TangensWithParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_CosineWithParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_additionAndPotencyAndSineAndExpWithParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_additionAndSineWithParentheses_correctValue);
	 CPPUNIT_TEST(calculateValue_pi_pi);
	 CPPUNIT_TEST(calculateValue_piAndAddition_correctValue);
	 CPPUNIT_TEST(constructor_negativeValueInBrackets_notParsingFailed);
	 CPPUNIT_TEST(calculateValue_negativeOneInBrackets_minusOne);
	 CPPUNIT_TEST(calculateValue_divisionByZero_error);
	 CPPUNIT_TEST(constructor_piTwoInARow_parsingFailed);
	 CPPUNIT_TEST(constructor_twoUnaryFunctionsInARowWithMissingClosingBracket_parsingFailed);
	 CPPUNIT_TEST(constructor_ansFirstUse);
	 CPPUNIT_TEST(constructor_ansNotFirstUseAndAdition);
	 CPPUNIT_TEST(constructor_ansTwoInARow_parsingFailed);
	 CPPUNIT_TEST(constructor_twoWhiteSpaces_notParsingFailed);
	 CPPUNIT_TEST(constructor_absin_parsingFailed);
	 CPPUNIT_TEST(constructor_minusexp0_parsingFailed);
    	 CPPUNIT_TEST(calculateValue_atanAndasinAndacos_correctValue);
    	 CPPUNIT_TEST(calculateValue_expAndln_correctValue);
     	 CPPUNIT_TEST(calculateValue_sinAndasin_correctValue);
     	 CPPUNIT_TEST(calculateValue_asin_correctValue);	 
     	 CPPUNIT_TEST(calculateValue_sin360AndAngleTypeDegree_0);
	 CPPUNIT_TEST(calculateValue_sin360AndAngleTypeRadiant_correctResult);





	 CPPUNIT_TEST_SUITE_END();

private:
	 void constructor_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_notParsingFailed();
	 void calculateValue_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_correctValue();
	 void calculateValue_validStringWithAdditionSubtractionMultiplicationDivisionAndParentheses_noError();
	 void calculateValue_addition_correctValue();
	 void calculateValue_multiplication_correctValue();
	 void calculateValue_subtraction_correctValue();
	 void calculateValue_division_correctValue();
	 void calculateValue_additionAndMultiplication_correctValue();
	 void calculateValue_additionAndMultiplicationWithParentheses_correctValue();
	 void calculateValue_nestedParentheses_correctValue();
	 void calculateValue_twoDivisionsInARow_correctValue();
	 void calculateValue_twoSubtractionsInARow_correctValue();
	 void calculateValue_subtractionAndAddition_correctValue();
	 void calculateValue_divisionAndMultiplication_correctValue();
	 void constructor_stringWithTwoOperatorsInARow_parsingFailed();
	 void constructor_missingClosingBracket_parsingFailed();
	 void constructor_commaInsteadOfPoint_parsingFailed();
	 void constructor_missingOpeningBracket_parsingFailed();
	 void calculateValue_potency_correctValue();
	 void calculateValue_twoPotencysInARow_correctValue();
	 void calculateValue_additionAndPotency_correctValue();
	 void calculateValue_additionAndPotencyWithParentheses_correctValue();
	 void calculateValue_twoPotenciesUnrelatedTogether_correctValue();
	 void calculateValue_TangensWithParentheses_correctValue();
	 void calculateValue_CosineWithParentheses_correctValue();
	 void calculateValue_additionAndPotencyAndSineAndExpWithParentheses_correctValue();
	 void calculateValue_additionAndSineWithParentheses_correctValue();
	 void calculateValue_pi_pi();
	 void calculateValue_piAndAddition_correctValue();
	 void constructor_negativeValueInBrackets_notParsingFailed();
	 void calculateValue_negativeOneInBrackets_minusOne();
	 void calculateValue_divisionByZero_error();
	 void constructor_piTwoInARow_parsingFailed();
	 void constructor_twoUnaryFunctionsInARowWithMissingClosingBracket_parsingFailed();
	 void constructor_ansFirstUse();
	 void constructor_ansNotFirstUseAndAdition();
	 void constructor_ansTwoInARow_parsingFailed();
	 void constructor_twoWhiteSpaces_notParsingFailed();
	 void constructor_absin_parsingFailed();
	 void constructor_minusexp0_parsingFailed();
     void calculateValue_atanAndasinAndacos_correctValue();
     void calculateValue_expAndln_correctValue();
     void calculateValue_sinAndasin_correctValue();
     void calculateValue_asin_correctValue();
     	 void calculateValue_sin360AndAngleTypeDegree_0();
	 void calculateValue_sin360AndAngleTypeRadiant_correctResult();



};

#endif
