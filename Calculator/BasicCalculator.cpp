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
	output = splitParts(input_string);

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


BasicCalculator::partsOut BasicCalculator::splitParts(std::vector<char> input_string)
{
	bool first = true;					//first valid character?
	std::stack<calcParts> infix;		//infix stack
	BasicCalculator::calcParts part;	//part to go on stack
	std::stringstream snum;				//characters of number being built
	snum.precision(15);					//ensure precision when converting to double
	double dnum;						//double complete number
	std::stringstream message;			//error message
	

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


			// Output warning message
			message << "Invalid input \"" << character << "\" in: ";


			// add problem subset
			for (int x = start; x = end; x++) {
				message << input_string[x];
			}

			break;
		}
	}

	// type cast error message
	std::string messageString = message.str();
	std::vector<char> messageVector(messageString.begin(), messageString.end());

	// build output
	BasicCalculator::partsOut output;
	output.infix = infix;
	output.message = messageVector;

	return output;
}

std::vector<char> BasicCalculator::postfixConvert(std::stack<calcParts> infix)
{
	// create conversion stacks
	std::stack<calcParts> numstack;
	std::stack<calcParts> opstack;
	BasicCalculator::calcParts opnew;	//new part to go on stack
	BasicCalculator::calcParts optop;	//part on top of operator stack
	bool correct;
	std::vector<char> errorMessage;


	// convert infix to postfix notation
	for (int i = 0; i < infix.size; i++) {
		
		// pop top element
		opnew = infix.pop;

		if (opnew.op = 'n') {		// if new part is a number
			opstack.push = opnew;
		}
		else {						// if new part is a operator
			correct = false;

			// Until the new operator has a higher precedence than the value at the top of the stack
			while (correct == false) {

				// Find presedence
				opnewImport = precedence(opnew.op);
				optop = infix.top;
				optopImport = precedence(optop.op);

				// Compare precedence values
				if (opnewImport.value > optopImport.value) {		// If new operator has a higher precedence

					push to stack

					correct = true;
				}
				else if (opnewImport.value < optopImport.value) {	// If new operator has a lower precedence

					pop and push
				}
				else {												// If both operators have the same precedence value

					// compare association
					if ((opnewImport.assoc == 'L') && (optopImport.assoc != 'R')) {
						// If the new operator has left-associativity...
						// and...
						// If the operator ontop of the stack does not have right-associativity

						pop and push
					}
					else if ((opnewImport.assoc == 'R') || (opnewImport.assoc == 'A')) {
						// If the new operator has right-associativity...
						// or...
						// If the new operator is associative

						push to stack

						correct = true;
					}
					else if ((opnewImport.assoc == 'N') && (opnew.op != optop.op)) {
						// If the new operator has non-associativity...
						// and...
						// If the operator ontop of the stack is not identicle

						push to stack

						correct = true;
					}
					else {
						// Otherwise

						error message
					}
				}
			}
		}
	}


	// output to postfix stack
	for (int i = 0; i < numstack.size; i++) {
		postfix.push = numstack.pop;
	}

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
