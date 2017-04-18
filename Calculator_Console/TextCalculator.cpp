// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "../hFiles/myTypes.h"
#include "../Calculator_Library/CalculatorLib.h"
#include <stack>          // std::stack
#include <string>


// Main
int main()
{
	char continue_str = 'Y';
	std::string input_string;
	std::string output_string;
	CalculatorLib Calculate;

	while (continue_str == 'Y')
	{
		// take user input
		system("cls");
		std::cout << "CT4021     Calculator     Joshua Walker S1609415" << std::endl << std::endl;
		std::cout << "Enter calculation:  ";
		std::cin >> input_string;


		// Parse input
		output_string = "";
		output_string = Calculate.Parse(input_string);

		// calculate result
		if (output_string.empty()) {
			output_string = Calculate.Result(myTypes::Dec, 10);
		}


		// output result
		std::cout << "Answer is:  " << output_string << std::endl << std::endl;



		// check if to continue
		std::cout << "Continue (Y/N):  ";
		std::cin >> continue_str;
	}

    return 0;
}
