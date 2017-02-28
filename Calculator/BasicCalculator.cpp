#include "stdafx.h"
#include "BasicCalculator.h"
#include <cctype>
#include <iostream>
#include <sstream>


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

	// split into parts
	BasicCalculator::partsOut output;
	output = createParts(input_string);

	// Format into postfix and store in global
	postfixConvert(output.infix);

	return output.message;
}


std::vector<char> BasicCalculator::Result(myTypes::notation notate, int sig_fig)
{
	std::stack<int> sequence; //change name & seporate calculation into rpn calculator
	// Calculate Result using rpn
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


BasicCalculator::partsOut BasicCalculator::createParts(std::vector<char> input_string)
{
	bool first = true;
	std::stack<calcParts> infix;
	BasicCalculator::calcParts part;
	double dnum;
	std::stringstream snum;
	snum.precision(15);  // ensure precision when converting to double
	

	// read char by char & check if first value is operator
	for (int i = 0; i < input_string.size; i++)
	{
		// seporate value
		char character = input_string[i];

		// split values
		if (std::isspace(character)) {
			// If whitespace do nothing
		}
		else if (std::isdigit(character) || character == '.') {
			// If part of number build number

			if (first == true) { // Mark if first
				first = false;
			}
			else {}

			// Build number
			snum << character;

		}
		else if (isOperator(character)) {
			// If operator output to stack

			if (first == true) { // Number = previous answer if first
				dnum = answer;
				first = false;
			}
			else {
				snum >> dnum;  //convert number to double
			}
			
			// Push built number and operator to stack
			part.op = 'n';
			part.num = dnum;
			infix.push(part);  // Push number

			part.op = character;
			part.num = 0;
			infix.push(part);  // Push operator

		}
		else {
			// If other

			// find error subset start
			int start;

			if ((i - 5) < 0) {
				start = 0;
			}
			else {
				start = i - 5;
			}

			// find error subset end
			int end;

			if ((i + 5) > input_string.size) {
				end = input_string.size;
			}
			else {
				end = i + 5;
			}

			// select subset
			std::vector<char> subset;

			for (int x = start; x = end; x++) {
				subset[x - start] = input_string[x];
			}


			// Output warning message
			message << "Invalid input \"" << character << "\" in: " << subset;// change all strings to stringstreams

			break;
		}
	}

	// build output
	BasicCalculator::partsOut output;
	output.infix = infix;
	output.message = message;

	return output;
}

void BasicCalculator::postfixConvert(std::stack<calcParts> infix)
{

	return;
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


double BasicCalculator::calculateSingle(double num1, char op, double num2)
{
	double result;

	// Calculate based on operator
	switch(op) {
		case '/' : // Divide
			result = num1 / num2;
			break;
		case '*' : // Multiply
			result = num1 * num2;
			break;
		case '+' : // Add
			result = num1 + num2;
			break;
		case '-' : // Subtract
			result = num1 - num2;
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
