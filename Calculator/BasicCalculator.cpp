#include "stdafx.h"
#include "BasicCalculator.h"
#include <cctype>


BasicCalculator::BasicCalculator()
{
}


BasicCalculator::~BasicCalculator()
{
}


std::vector<char> BasicCalculator::Parse(const std::vector<char> user_input)
{
	// Copy user input
	std::vector<char> input_string = user_input;

	// Apply Substitutions to copy
	substitute(input_string);

	// Format into Operations
	std::vector<char> message;
	message = createParts(input_string);

	// Find BIDMAS sequence
	bidmasSort;

	return message;
}


std::vector<char> BasicCalculator::Result(myTypes::notation notate, int sig_fig)
{
	// Calculate Result
	while (sequence.size > 0) {
		// Seporate Next Operation


		// Calculate Result


		// Feed into Operations

	}

	// Format Output
	std::vector<char> output;
	output = format(answer, notate, sig_fig);

	return output;
}


void BasicCalculator::substitute(std::vector<char> &input_string)
{
	// Substitute operators character by character
	for ( int i = 0; i < input_string.size; i++ )
	{
		// seporate value
		char character = input_string[i];

		// substitute values
		switch(character) {
			case 'x' :  // multiply
				input_string[i] = '*';
				break;
			case ',' :  // decimal seporator
				input_string[i] = '.';
				break;
			default :
		}
	}
}


std::vector<char> BasicCalculator::createParts(std::vector<char> input_string)
{
	// check if first value is operator


	// read char by char
	for (int i = 0; i < input_string.size; i++)
	{
		// seporate value
		char character = input_string[i];

		// split values
		if (std::isspace(character)) {

		}
		else if (std::isdigit(character) || character == '.') {

		}
		else if (isOperator(character)) {

		}
		else {

		}
	}

	//operations = ;
	return ...;
}


bool BasicCalculator::isOperator(char character)
{
	bool valid = false;

	// check character
	switch (character) {
		case '/':
			valid = true;
		case '*':
			valid = true;
		case '+':
			valid = true;
		case '-':
			valid = true;
		default :
	}

	return valid;
}


void BasicCalculator::bidmasSort()
{
	// Assign number to each operator

	// Sort numbers

}


double BasicCalculator::calculateSingle(calcParts single)
{
	double result;

	// Calculate based on operator
	switch(single.op) {
		case '/' : // Divide
			result = single.num1 / single.num2;
			break;
		case '*' : // Multiply
			result = single.num1 * single.num2;
			break;
		case '+' : // Add
			result = single.num1 + single.num2;
			break;
		case '-' : // Subtract
			result = single.num1 - single.num2;
			break;
		default : // error
			
	}
	return result;
}


std::vector<char> BasicCalculator::format(double num_value, myTypes::notation notate, int sig_fig)
{
	// Reduce to Significant Figures


	// Shift to notation


	return std::vector<char>();
}
