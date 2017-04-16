#include "stdafx.h"
#include "CppUnitTest.h"
#include "../hFiles/myTypes.h"
#include "../Calculator_Library/CalculatorLib.h"
#include <vector>
#include <stack>          // std::stack

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Calculator_UnitTest
{
	TEST_CLASS(UnitTest_Substitutions)
	{
	public:

		TEST_METHOD(TestMethod_x_Substitute)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '*', '2' };	//Normalised
			std::vector<char> string2 = { '2', 'x', '2' };	//Input
			Test.substitute(string2);
			Assert::IsTrue(string1 == string2);
		}
		TEST_METHOD(TestMethod_comma_Substitute)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '.', '2' };	//Normalised
			std::vector<char> string2 = { '2', ',', '2' };	//Input
			Test.substitute(string2);
			Assert::IsTrue(string1 == string2);
		}
		TEST_METHOD(TestMethod_divide_Substitute)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '/', '2' };	//Normalised
			std::vector<char> string2 = { '2', '/', '2' };	//Input
			Test.substitute(string2);
			Assert::IsTrue(string1 == string2);
		}
		TEST_METHOD(TestMethod_multiply_Substitute)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '*', '2' };	//Normalised
			std::vector<char> string2 = { '2', '*', '2' };	//Input
			Test.substitute(string2);
			Assert::IsTrue(string1 == string2);
		}
		TEST_METHOD(TestMethod_add_Substitute)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '+', '2' };	//Normalised
			std::vector<char> string2 = { '2', '+', '2' };	//Input
			Test.substitute(string2);
			Assert::IsTrue(string1 == string2);
		}
		TEST_METHOD(TestMethod_subtract_Substitute)
		{
			CalculatorLib Test;
			std::vector<char> string1 = { '2', '-', '2' };	//Normalised
			std::vector<char> string2 = { '2', '-', '2' };	//Input
			Test.substitute(string2);
			Assert::IsTrue(string1 == string2);
		}

	};
	TEST_CLASS(UnitTest_isOperator)
	{
	public:

		TEST_METHOD(TestMethod_divide_isOperator)
		{
			CalculatorLib Test;
			char op = '/';	//Input
			Assert::AreEqual(true, Test.isOperator(op));
		}
		TEST_METHOD(TestMethod_multiply_isOperator)
		{
			CalculatorLib Test;
			char op = '*';	//Input
			Assert::AreEqual(true, Test.isOperator(op));
		}
		TEST_METHOD(TestMethod_add_isOperator)
		{
			CalculatorLib Test;
			char op = '+';	//Input
			Assert::AreEqual(true, Test.isOperator(op));
		}
		TEST_METHOD(TestMethod_subtract_isOperator)
		{
			CalculatorLib Test;
			char op = '-';	//Input
			Assert::AreEqual(true, Test.isOperator(op));
		}
		TEST_METHOD(TestMethod_num_isOperator)
		{
			CalculatorLib Test;
			char op = 'n';	//Input
			Assert::AreEqual(false, Test.isOperator(op));
		}

	};
	TEST_CLASS(UnitTest_splitParts)
	{
	public:
		
		TEST_METHOD(TestMethod_NomShort_splitParts)
		{
			CalculatorLib Test;
			std::vector<char> string = { '7', '*', '8' };	//Input
			CalculatorLib::partsOut parts;	//Output
			parts.message = "";
			CalculatorLib::calcPart item;
			item.op = 'n';
			item.num = 7;
			parts.infix.push(item);
			item.op = '*';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 8;
			parts.infix.push(item);
			CalculatorLib::partsOut partsout = Test.splitParts(string);
			Assert::IsTrue(parts == partsout);
		}
		TEST_METHOD(TestMethod_NomLong_splitParts)
		{
			CalculatorLib Test;
			std::string str("6.447 +2.01525/ 9.8-4.000 ");	//Input
			std::vector<char> string(str.begin(), str.end());
			CalculatorLib::partsOut parts;	//Output
			parts.message = "";
			CalculatorLib::calcPart item;
			item.op = 'n';
			item.num = 6.447;
			parts.infix.push(item);
			item.op = '+';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 2.01525;
			parts.infix.push(item);
			item.op = '/';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 9.8;
			parts.infix.push(item);
			item.op = '-';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 4;
			parts.infix.push(item);
			CalculatorLib::partsOut partsout = Test.splitParts(string);
			Assert::IsTrue(parts == partsout);
		}
		TEST_METHOD(TestMethod_ErrorRepeat_splitParts)
		{
			CalculatorLib Test;
			std::string str("6.447 +2.01525// 9.8-4.000 ");	//Input
			std::vector<char> string(str.begin(), str.end());
			CalculatorLib::partsOut parts;	//Output
			parts.message = "Invalid input \"/\" in: 1525// 9.8-";
			CalculatorLib::calcPart item;
			item.op = 'n';
			item.num = 6.447;
			parts.infix.push(item);
			item.op = '+';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 2.01525;
			parts.infix.push(item);
			item.op = '/';
			item.num = 0;
			parts.infix.push(item);
			CalculatorLib::partsOut partsout = Test.splitParts(string);
			Assert::IsTrue(parts == partsout);
		}
		TEST_METHOD(TestMethod_ErrorOther_splitParts)
		{
			CalculatorLib Test;
			std::string str("6.447 +2.01?525/ 9.8-4.000 ");	//Input
			std::vector<char> string(str.begin(), str.end());
			CalculatorLib::partsOut parts;	//Output
			parts.message = "Invalid input \"?\" in: +2.01?525/ ";
			CalculatorLib::calcPart item;
			item.op = 'n';
			item.num = 6.447;
			parts.infix.push(item);
			item.op = '+';
			item.num = 0;
			parts.infix.push(item);
			//item.op = 'n';
			//item.num = 2.01525;
			//parts.infix.push(item);
			CalculatorLib::partsOut partsout = Test.splitParts(string);
			Assert::IsTrue(parts == partsout);
		}

	};
}