#include "stdafx.h"
#include "CppUnitTest.h"
#include "../hFiles/myTypes.h"
#include "../Calculator_Library/CalculatorLib.h"
#include <vector>
#include <stack>          // std::stack

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Calculator_UnitTest
{
	// Parse Input Code
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
			Assert::IsTrue(Test.isOperator(op));
		}
		TEST_METHOD(TestMethod_multiply_isOperator)
		{
			CalculatorLib Test;
			char op = '*';	//Input
			Assert::IsTrue(Test.isOperator(op));
		}
		TEST_METHOD(TestMethod_add_isOperator)
		{
			CalculatorLib Test;
			char op = '+';	//Input
			Assert::IsTrue(Test.isOperator(op));
		}
		TEST_METHOD(TestMethod_subtract_isOperator)
		{
			CalculatorLib Test;
			char op = '-';	//Input
			Assert::IsTrue(Test.isOperator(op));
		}
		TEST_METHOD(TestMethod_num_isOperator)
		{
			CalculatorLib Test;
			char op = 'n';	//Input
			Assert::IsFalse(Test.isOperator(op));
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
			item.num = 8;
			parts.infix.push(item);
			item.op = '*';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 7;
			parts.infix.push(item);
			CalculatorLib::partsOut partsout = Test.splitParts(string);
			Assert::IsTrue(parts == partsout);
		}
		TEST_METHOD(TestMethod_NomLong_splitParts)
		{
			CalculatorLib Test;
			std::string str("6.447 +201.525/ 9.8-4.000 ");	//Input
			std::vector<char> string(str.begin(), str.end());
			CalculatorLib::partsOut parts;	//Output
			parts.message = "";
			CalculatorLib::calcPart item;
			item.op = 'n';
			item.num = 4;
			parts.infix.push(item);
			item.op = '-';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 9.8;
			parts.infix.push(item);
			item.op = '/';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 201.525;
			parts.infix.push(item);
			item.op = '+';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 6.447;
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
			item.op = '/';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 2.01525;
			parts.infix.push(item);
			item.op = '+';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 6.447;
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
			item.op = '+';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 6.447;
			parts.infix.push(item);
			CalculatorLib::partsOut partsout = Test.splitParts(string);
			Assert::IsTrue(parts == partsout);
		}

	};
	TEST_CLASS(UnitTest_calcPrecedence)
	{
	public:

		TEST_METHOD(TestMethod_divide_calcPrecedence)
		{
			CalculatorLib Test;
			char opIn = '/';	//Input
			CalculatorLib::precedence pres1;		//Output
			pres1.value = 2;
			pres1.assoc = 'L';
			CalculatorLib::precedence pres2 = Test.calcPrecedence(opIn);
			Assert::IsTrue(pres1 == pres2);
		}
		TEST_METHOD(TestMethod_multiply_calcPrecedence)
		{
			CalculatorLib Test;
			char opIn = '*';	//Input
			CalculatorLib::precedence pres1;		//Output
			pres1.value = 2;
			pres1.assoc = 'A';
			CalculatorLib::precedence pres2 = Test.calcPrecedence(opIn);
			Assert::IsTrue(pres1 == pres2);
		}
		TEST_METHOD(TestMethod_add_calcPrecedence)
		{
			CalculatorLib Test;
			char opIn = '+';	//Input
			CalculatorLib::precedence pres1;		//Output
			pres1.value = 1;
			pres1.assoc = 'A';
			CalculatorLib::precedence pres2 = Test.calcPrecedence(opIn);
			Assert::IsTrue(pres1 == pres2);
		}
		TEST_METHOD(TestMethod_subtract_calcPrecedence)
		{
			CalculatorLib Test;
			char opIn = '-';	//Input
			CalculatorLib::precedence pres1;		//Output
			pres1.value = 1;
			pres1.assoc = 'L';
			CalculatorLib::precedence pres2 = Test.calcPrecedence(opIn);
			Assert::IsTrue(pres1 == pres2);
		}
		TEST_METHOD(TestMethod_other_calcPrecedence)
		{
			CalculatorLib Test;
			char opIn = '~';	//Input
			CalculatorLib::precedence pres1;		//Output
			pres1.value = 0;
			pres1.assoc = 'A';
			CalculatorLib::precedence pres2 = Test.calcPrecedence(opIn);
			Assert::IsTrue(pres1 == pres2);
		}

	};
	TEST_CLASS(UnitTest_postfixConvert)
	{
	public:

		TEST_METHOD(TestMethod_NomShort_postfixConvert)
		{
			CalculatorLib Test;
			CalculatorLib::partsOut parts;	//Input
			parts.message = "";
			CalculatorLib::calcPart item;
			item.op = 'n';
			item.num = 8;
			parts.infix.push(item);
			item.op = '*';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 7;
			parts.infix.push(item);
			CalculatorLib::partsOut partsout;	//Output
			partsout.message = "";
			item.op = '*';
			item.num = 0;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 8;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 7;
			partsout.infix.push(item);
			std::string error = Test.postfixConvert(parts.infix);
			parts.infix = Test.readPostfix();
			Assert::IsTrue((parts == partsout) && error.empty());
		}
		TEST_METHOD(TestMethod_NomPrece_postfixConvert)
		{
			CalculatorLib Test;
			CalculatorLib::partsOut parts;	//Input
			parts.message = "";
			CalculatorLib::calcPart item;
			item.op = 'n';
			item.num = 4;
			parts.infix.push(item);
			item.op = '-';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 9.8;
			parts.infix.push(item);
			item.op = '/';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 201.525;
			parts.infix.push(item);
			item.op = '+';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 6.447;
			parts.infix.push(item);
			CalculatorLib::partsOut partsout;	//Output
			partsout.message = "";
			item.op = '-';
			item.num = 0;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 4;
			partsout.infix.push(item);
			item.op = '+';
			item.num = 0;
			partsout.infix.push(item);
			item.op = '/';
			item.num = 0;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 9.8;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 201.525;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 6.447;
			partsout.infix.push(item);
			std::string error = Test.postfixConvert(parts.infix);
			parts.infix = Test.readPostfix();
			Assert::IsTrue((parts == partsout) && error.empty());
		}
		TEST_METHOD(TestMethod_NomAssoc_postfixConvert)
		{
			CalculatorLib Test;
			CalculatorLib::partsOut parts;	//Input
			parts.message = "";
			CalculatorLib::calcPart item;
			item.op = 'n';
			item.num = 4;
			parts.infix.push(item);
			item.op = '/';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 9.8;
			parts.infix.push(item);
			item.op = '*';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 201.525;
			parts.infix.push(item);
			item.op = '/';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 6.447;
			parts.infix.push(item);
			CalculatorLib::partsOut partsout;	//Output
			partsout.message = "";
			item.op = '*';
			item.num = 0;
			partsout.infix.push(item);
			item.op = '/';
			item.num = 0;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 4;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 9.8;
			partsout.infix.push(item);
			item.op = '/';
			item.num = 0;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 201.525;
			partsout.infix.push(item);
			item.op = 'n';
			item.num = 6.447;
			partsout.infix.push(item);
			std::string error = Test.postfixConvert(parts.infix);
			parts.infix = Test.readPostfix();
			Assert::IsTrue((parts == partsout) && error.empty());
		}

	};
	TEST_CLASS(UnitTest_Parse)
	{
	public:

		TEST_METHOD(TestMethod_NomShort_Parse)
		{
			CalculatorLib Test;
			std::string stringIn("7*8");	//Input
			std::string stringOut("");	//Error Output
			CalculatorLib::partsOut parts;	//Parsed Data Target
			CalculatorLib::calcPart item;
			parts.message = "";
			item.op = '*';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 8;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 7;
			parts.infix.push(item);
			std::string error = Test.Parse(stringIn);
			CalculatorLib::partsOut partsout;	//Parsed Data Output
			partsout.message = "";
			partsout.infix = Test.readPostfix();
			Assert::IsTrue((parts == partsout) && (stringOut == error));
		}
		TEST_METHOD(TestMethod_NomLong_Parse)
		{
			CalculatorLib Test;
			std::string stringIn("6.447 +201.525/ 9.8-4.000 *84744.3");	//Input
			std::string stringOut("");	//Error Output
			CalculatorLib::partsOut parts;	//Parsed Data Target
			CalculatorLib::calcPart item;
			parts.message = "";
			item.op = '-';
			item.num = 0;
			parts.infix.push(item);
			item.op = '*';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 84744.3;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 4;
			parts.infix.push(item);
			item.op = '+';
			item.num = 0;
			parts.infix.push(item);
			item.op = '/';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 9.8;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 201.525;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 6.447;
			parts.infix.push(item);
			std::string error = Test.Parse(stringIn);
			CalculatorLib::partsOut partsout;	//Parsed Data Output
			partsout.message = "";
			partsout.infix = Test.readPostfix();
			Assert::IsTrue((parts == partsout) && (stringOut == error));
		}

	};


	// Calculate Output Code
	TEST_CLASS(UnitTest_calculateSingle)
	{
	public:

		TEST_METHOD(TestMethod_divideShort_calculateSingle)
		{
			CalculatorLib Test;
			long double num1 = 9;	//Input
			char op = '/';
			long double num2 = 3;
			long double expected = 3;	//Output
			Assert::IsTrue(expected == Test.calculateSingle(num1, op, num2));
		}
		TEST_METHOD(TestMethod_divideLong_calculateSingle)
		{
			CalculatorLib Test;
			long double num1 = 7829.54;	//Input
			char op = '/';
			long double num2 = -3.46523;
			long double expected = 7829.54 / -3.46523;	//Output
			Assert::IsTrue(expected == Test.calculateSingle(num1, op, num2));
		}
		TEST_METHOD(TestMethod_multiplyShort_calculateSingle)
		{
			CalculatorLib Test;
			long double num1 = -2;	//Input
			char op = '*';
			long double num2 = 4;
			long double expected = -8;	//Output
			Assert::IsTrue(expected == Test.calculateSingle(num1, op, num2));
		}
		TEST_METHOD(TestMethod_multiplyLong_calculateSingle)
		{
			CalculatorLib Test;
			long double num1 = 26.2;	//Input
			char op = '*';
			long double num2 = 0.56863;
			long double expected = 26.2 * 0.56863;	//Output
			Assert::IsTrue(expected == Test.calculateSingle(num1, op, num2));
		}
		TEST_METHOD(TestMethod_addShort_calculateSingle)
		{
			CalculatorLib Test;
			long double num1 = -7;	//Input
			char op = '+';
			long double num2 = 1;
			long double expected = -6;	//Output
			Assert::IsTrue(expected == Test.calculateSingle(num1, op, num2));
		}
		TEST_METHOD(TestMethod_addLong_calculateSingle)
		{
			CalculatorLib Test;
			long double num1 = -9538523.6748;	//Input
			char op = '+';
			long double num2 = 98.5685226705;
			long double expected = -9538523.6748 + 98.5685226705;	//Output
			Assert::IsTrue(expected == Test.calculateSingle(num1, op, num2));
		}
		TEST_METHOD(TestMethod_subtractShort_calculateSingle)
		{
			CalculatorLib Test;
			long double num1 = 6;	//Input
			char op = '-';
			long double num2 = 0;
			long double expected = 6;	//Output
			Assert::IsTrue(expected == Test.calculateSingle(num1, op, num2));
		}
		TEST_METHOD(TestMethod_subtractLong_calculateSingle)
		{
			CalculatorLib Test;
			long double num1 = 7829.54;	//Input
			char op = '-';
			long double num2 = -3.46523;
			long double expected = 7829.54 - -3.46523;	//Output
			Assert::IsTrue(expected == Test.calculateSingle(num1, op, num2));
		}
		TEST_METHOD(TestMethod_errorOp_calculateSingle)
		{
			CalculatorLib Test;
			long double num1 = 23.5;	//Input
			char op = 'n';
			long double num2 = -8745.564;
			long double expected = 0;	//Output
			Assert::IsTrue(expected == Test.calculateSingle(num1, op, num2));
		}

	};
	TEST_CLASS(UnitTest_format)
	{
	public:

		TEST_METHOD(TestMethod_decShort_format)
		{
			CalculatorLib Test;
			long double num = -258.0795;	//Input
			myTypes::notation format = myTypes::Dec;
			int sig_fig = 9;
			std::string expected = "-258.0795";	//Output
			Assert::IsTrue(expected == Test.format(num, format, sig_fig));
		}
		TEST_METHOD(TestMethod_decLimited_format)
		{
			CalculatorLib Test;
			long double num = 49982463158725442.735;	//Input
			myTypes::notation format = myTypes::Dec;
			int sig_fig = 16;
			std::string expected = "4.998246315872544 x10^16";	//Output
			Assert::IsTrue(expected == Test.format(num, format, sig_fig));
		}
		TEST_METHOD(TestMethod_sciShort_format)
		{
			CalculatorLib Test;
			long double num = -258.0795;	//Input
			myTypes::notation format = myTypes::Sci;
			int sig_fig = 16;
			std::string expected = "-2.580795 x10^2";	//Output
			Assert::IsTrue(expected == Test.format(num, format, sig_fig));
		}
		TEST_METHOD(TestMethod_sciLimited_format)
		{
			CalculatorLib Test;
			long double num = 49982463158725442.735;	//Input
			myTypes::notation format = myTypes::Sci;
			int sig_fig = 12;
			std::string expected = "4.99824631587 x10^16";	//Output
			Assert::IsTrue(expected == Test.format(num, format, sig_fig));
		}
		TEST_METHOD(TestMethod_engShort_format)
		{
			CalculatorLib Test;
			long double num = -258.0795;	//Input
			myTypes::notation format = myTypes::Eng;
			int sig_fig = 12;
			std::string expected = "-258.0795 x10^0";	//Output
			Assert::IsTrue(expected == Test.format(num, format, sig_fig));
		}
		TEST_METHOD(TestMethod_engLimited_format)
		{
			CalculatorLib Test;
			long double num = 49982463158725442.735;	//Input
			myTypes::notation format = myTypes::Eng;
			int sig_fig = 8;
			std::string expected = "49.982463 x10^15";	//Output
			Assert::IsTrue(expected == Test.format(num, format, sig_fig));
		}
		TEST_METHOD(TestMethod_SigfigAndRound_format)
		{
			CalculatorLib Test;
			long double num = 49982463158725442.735;	//Input
			myTypes::notation format = myTypes::Dec;
			int sig_fig = 0;
			std::string expected = "4.998246316 x10^16";	//Output
			Assert::IsTrue(expected == Test.format(num, format, sig_fig));
		}

	};
	TEST_CLASS(UnitTest_Result)
	{
	public:

		TEST_METHOD(TestMethod_NomShort_Result)
		{
			CalculatorLib Test;
			std::string stringIn("7*8");	//Input
			std::string stringOut("");	//Error Output
			CalculatorLib::partsOut parts;	//Parsed Data Target
			CalculatorLib::calcPart item;
			parts.message = "";
			item.op = '*';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 8;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 7;
			parts.infix.push(item);
			std::string error = Test.Parse(stringIn);
			CalculatorLib::partsOut partsout;	//Parsed Data Output
			partsout.message = "";
			partsout.infix = Test.readPostfix();
			bool correct = (parts == partsout) && (stringOut == error);
			Assert::IsTrue(correct, L"Incorrect Parse");

			if (correct) {
				myTypes::notation format = myTypes::Dec;
				int sig_fig = 9;
				std::string expected = "56";	//Output
				Assert::IsTrue(expected == Test.Result(format, sig_fig));
			}
		}
		TEST_METHOD(TestMethod_NomLong_Result)
		{
			CalculatorLib Test;
			std::string stringIn("6.447 +201.525/ 9.8-4.000 *84744.3");	//Input
			std::string stringOut("");	//Error Output
			CalculatorLib::partsOut parts;	//Parsed Data Target
			CalculatorLib::calcPart item;
			parts.message = "";
			item.op = '-';
			item.num = 0;
			parts.infix.push(item);
			item.op = '*';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 84744.3;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 4;
			parts.infix.push(item);
			item.op = '+';
			item.num = 0;
			parts.infix.push(item);
			item.op = '/';
			item.num = 0;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 9.8;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 201.525;
			parts.infix.push(item);
			item.op = 'n';
			item.num = 6.447;
			parts.infix.push(item);
			std::string error = Test.Parse(stringIn);
			CalculatorLib::partsOut partsout;	//Parsed Data Output
			partsout.message = "";
			partsout.infix = Test.readPostfix();
			bool correct = (parts == partsout) && (stringOut == error);
			Assert::IsTrue(correct, L"Incorrect Parse");

			if (correct) {
				myTypes::notation format = myTypes::Eng;
				int sig_fig = 13;
				std::string expected = "-338.9501892245 x10^3";	//Output
				Assert::IsTrue(expected == Test.Result(format, sig_fig));
			}
		}

	};
}