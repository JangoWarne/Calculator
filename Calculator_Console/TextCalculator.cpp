// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "../hFiles/myTypes.h"
#include "../Calculator_Library/CalculatorLib.h"
#include <stack>          // std::stack

// functions
float add_single(int num1, int num2);
float subtract_single(int num1, int num2);
float multiply_single(int num1, int num2);
float divide_single(int num1, int num2);


// Main
int main()
{
	CalculatorLib Test;
	CalculatorLib::partsOut parts;	//Input
	parts.message = "";
	CalculatorLib::calcPart item;
	item.op = 'n';
	item.num = 6.447;
	parts.infix.push(item);
	item.op = '+';
	item.num = 0;
	parts.infix.push(item);
	item.op = 'n';
	item.num = 201.525;
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
	bool i = ((parts == partsout) && error.empty());
	//char continue_str = 'Y';
	//char input_string[3];

	//while (continue_str == 'Y')
	//{
	//	// take user input
	//	std::cout << "Enter calculation:  ";
	//	std::cin >> input_string;


	//	// split into three parts
	//	int num1;
	//	char operand;
	//	int num2;

	//	num1 = atoi(&input_string[0]);
	//	operand = input_string[1];
	//	num2 = atoi(&input_string[2]);

	//	// calculate result
	//	float result;

	//	if (operand == '+')
	//	{
	//		// add
	//		result = add_single(num1, num2);
	//	}
	//	else if (operand == '-')
	//	{
	//		// subtract
	//		result = subtract_single(num1, num2);
	//	}
	//	else if ((operand == '*') || (operand == 'x'))
	//	{
	//		// multiply
	//		result = multiply_single(num1, num2);
	//	}
	//	else if (operand == '/')
	//	{
	//		// divide
	//		result = divide_single(num1, num2);
	//	}
	//	else
	//	{
	//		// do nothing
	//	}



	//	// output result

	//	std::cout << "Answer is:  " << result << std::endl << std::endl;



	//	// check if to continue
	//	std::cout << "Continue (Y/N):  ";
	//	std::cin >> continue_str;
	//}

    return 0;
}



// add two numbers
float add_single(int num1, int num2)
{
	float result;
	float float1 = num1;
	float float2 = num2;

	result = float1 + float2;

	return result;
}

// subtract two numbers
float subtract_single(int num1, int num2)
{
	float result;
	float float1 = num1;
	float float2 = num2;

	result = float1 - float2;

	return result;
}

// multiply two numbers
float multiply_single(int num1, int num2)
{
	float result;
	float float1 = num1;
	float float2 = num2;

	result = float1 * float2;

	return result;
}

// divide two numbers
float divide_single(int num1, int num2)
{
	float result;
	float float1 = num1;
	float float2 = num2;

	result = float1 / float2;

	return result;
}
