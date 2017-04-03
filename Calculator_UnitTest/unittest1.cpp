#include "stdafx.h"
#include "CppUnitTest.h"
#include "../hFiles/myTypes.h"
#include "../Calculator_Library/CalculatorLib.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Calculator_UnitTest
{
	TEST_CLASS(UnitTest_Substitutions)
	{
	public:

		TEST_METHOD(TestMethod_x_Nominal)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '*', '2' };	//Normalised
			std::vector<char> string2 = { '2', 'x', '2' };	//Input
			Test.substitute(string2);
			Assert::AreEqual(true, (string1 == string2));
		}
		TEST_METHOD(TestMethod_, _Nominal)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '.', '2' };	//Normalised
			std::vector<char> string2 = { '2', ',', '2' };	//Input
			Test.substitute(string2);
			Assert::AreEqual(true, (string1 == string2));
		}
		TEST_METHOD(TestMethod_divide_Nominal)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '/', '2' };	//Normalised
			std::vector<char> string2 = { '2', '/', '2' };	//Input
			Test.substitute(string2);
			Assert::AreEqual(true, (string1 == string2));
		}
		TEST_METHOD(TestMethod_multiply_Nominal)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '*', '2' };	//Normalised
			std::vector<char> string2 = { '2', '*', '2' };	//Input
			Test.substitute(string2);
			Assert::AreEqual(true, (string1 == string2));
		}
		TEST_METHOD(TestMethod_add_Nominal)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '+', '2' };	//Normalised
			std::vector<char> string2 = { '2', '+', '2' };	//Input
			Test.substitute(string2);
			Assert::AreEqual(true, (string1 == string2));
		}
		TEST_METHOD(TestMethod_subtract_Nominal)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '-', '2' };	//Normalised
			std::vector<char> string2 = { '2', '-', '2' };	//Input
			Test.substitute(string2);
			Assert::AreEqual(true, (string1 == string2));
		}

	};
	TEST_CLASS(UnitTest_isOperator)
	{
	public:

		TEST_METHOD(TestMethod_)
		{
			//
		}

	};
}