#include "stdafx.h"
#include "CalculatorLib.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>


CalculatorLib::CalculatorLib()
{
}


CalculatorLib::~CalculatorLib()
{
}


std::string CalculatorLib::Parse(const std::string user_input)
{
	// Copy user input
	std::vector<char> input_string(user_input.begin(), user_input.end());

	// Apply Substitutions to copy
	substitute(input_string);

	// split into parts
	CalculatorLib::partsOut output;
	std::string errorMessage;

	output = splitParts(input_string);

	errorMessage = output.message;

	if (errorMessage.empty()) {
		// Format into postfix and store in global
		errorMessage = postfixConvert(output.infix);
	}
	return output.message;
}


std::string CalculatorLib::Result(myTypes::notation notate, int sig_fig)
{
	std::stack<calcPart> sequence = postfix;
	std::stack<long double> numStack;
	calcPart item;
	long double num1;
	long double num2;
	long double result;

	// Calculate Result using rpn and stacks
	while (sequence.size() > 0) {
		// read and pop next item
		item = sequence.top();	sequence.pop();

		// Is number?
		if (item.op == 'n') {

			// Push to number stack
			numStack.push(item.num);

		}
		else {
			
			// Calculate Result
			num2 = numStack.top();	numStack.pop();
			num1 = numStack.top();	numStack.pop();

			result = calculateSingle(num1, item.op, num2);

			// Push result to number stack
			numStack.push(result);

		}
	}
	
	// Format Output
	std::string output;
	output = format(numStack.top(), notate, sig_fig);

	return output;
}


void CalculatorLib::substitute(std::vector<char> &input_string)
{
	// Substitute operators character by character
	for ( int i = 0; i < input_string.size(); i++ )
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
				;
		}
	}
}


CalculatorLib::partsOut CalculatorLib::splitParts(std::vector<char> input_string)
{
	bool first = true;					//first valid character?
	std::stack<calcPart> infix;			//infix stack
	CalculatorLib::calcPart part;		//part to go on stack
	std::stringstream snum;				//characters of number being built
	snum.precision(15);					//ensure precision when converting to double
	long double dnum;					//double complete number
	std::stringstream message;			//error message
	char last = 'n';					//Last Type
	

	// read char by char & check if first value is operator
	for (int i = 0; i < input_string.size(); i++)
	{
		// seporate value
		char character = input_string[i];

		// split values
		if (std::isspace(character)) {
			// If whitespace do nothing
		}
		else if (std::isdigit(character) || character == '.') {
			// If part of number build number
			last = 'n';

			if (first == true) { // Mark if first
				first = false;
			}
			else {}

			// Build number
			snum << character;

		}
		else if (isOperator(character) && (last!='c')) {
			// If operator output to stack
			last = 'c';

			if (first == true) { // Number = previous answer if first
				dnum = answer;
				first = false;
			}
			else {
				snum >> dnum;  //convert number to long double

				snum.str(std::string());	// clear stringstream
				snum.clear();
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
			// If other input or repeated operator
			last = '~';

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

			if ((i + 5) > input_string.size()) {
				end = input_string.size();
			}
			else {
				end = i + 5;
			}


			// Output warning message
			message << "Invalid input \"" << character << "\" in: ";


			// add problem subset
			for (int x = start; x < end+1; x++) {
				message << input_string[x];
			}

			break;
		}
	}

	// If last element was not an error
	if (last != '~')
	{
		// Push incomplete number to stack
		if (first == true) { // Number = previous answer if first
			dnum = answer;
			first = false;
		}
		else {
			snum >> dnum;  //convert number to long double
		}
		part.op = 'n';
		part.num = dnum;
		infix.push(part);  // Push number
	}


	// type cast error message
	std::string messageString = message.str();

	// build output
	CalculatorLib::partsOut output;
	output.infix = infix;
	output.message = messageString;

	return output;
}


std::string CalculatorLib::postfixConvert(std::stack<calcPart> infix)
{
	// create conversion stacks
	std::stack<calcPart> numstack;
	std::stack<calcPart> opstack;
	CalculatorLib::calcPart opnew;		//new part to go on stack
	CalculatorLib::calcPart optop;		//part on top of operator stack
	bool correct;
	std::stringstream message;			//error message

	// Size of stack
	int iterations = infix.size();

	// Flip infix stack
	opstack = infix;
	for (int i = 0; i < iterations; i++) {

		// pop top element and push to infix stack
		infix.push(opstack.top());	opstack.pop();

	}


	// convert infix to postfix notation
	for (int i = 0; i < iterations; i++) {
		
		// pop top element
		opnew = infix.top();	infix.pop();

		if (opnew.op == 'n') {		// if new part is a number

			// push number to number stack
			numstack.push(opnew);
		}
		else {						// if new part is a operator
			correct = false;

			// Until the new operator has a higher precedence than the value at the top of the stack
			while (correct == false) {

				// Is operator stack empty?
				if (opstack.empty()) {

					// push operator to operator stack
					opstack.push(opnew);

					// Step complete
					correct = true;

				}
				else {

					// Find presedence
					precedence opnewImport = calcPrecedence(opnew.op);
					optop = opstack.top();
					precedence optopImport = calcPrecedence(optop.op);

					// Compare precedence values
					if (opnewImport.value > optopImport.value) {		// If new operator has a higher precedence

						// push operator to operator stack
						opstack.push(opnew);

						// Step complete
						correct = true;
					}
					else if (opnewImport.value < optopImport.value) {	// If new operator has a lower precedence

						// push top of operator stack to number stack
						numstack.push(opstack.top());	opstack.pop();
					}
					else {												// If both operators have the same precedence value

						// compare association
						if ((opnewImport.assoc == 'L') && (optopImport.assoc != 'R')) {
							// If the new operator has left-associativity...
							// and...
							// If the operator ontop of the stack does not have right-associativity

							// push top of operator stack to number stack
							numstack.push(opstack.top());	opstack.pop();	//Lower Assiciativity
						}
						else if ((opnewImport.assoc == 'R') || (opnewImport.assoc == 'A')) {
							// If the new operator has right-associativity...
							// or...
							// If the new operator is associative

							// push top of operator stack to number stack
							numstack.push(opstack.top());	opstack.pop();	//Same Assiciativity
						}
						else if ((opnewImport.assoc == 'N') && (opnew.op != optop.op)) {
							// If the new operator has non-associativity...
							// and...
							// If the operator ontop of the stack is not identicle

							// push operator to operator stack
							opstack.push(opnew);							//Higher Associativity

							// Step complete
							correct = true;
						}
						else {
							// Otherwise

							// Output warning message
							message << "Invalid operator sequence. Operator: \"" << opnew.op << "\"";

						}
					}
				}
			}
		}
	}

	// type cast error message
	std::string errorMessage = message.str();


	// If there was no error
	if (errorMessage == "") {
		// Size of stack
		iterations = opstack.size();

		// Empty opstack to numstack
		for (int i = 0; i < iterations; i++) {

			// pop top element and push to numstack stack
			numstack.push(opstack.top());	opstack.pop();

		}
	}


	// output to postfix stack
	iterations = numstack.size();
	for (int i = 0; i < iterations; i++) {
		postfix.push(numstack.top());	numstack.pop();
	}

	return errorMessage;
}


bool CalculatorLib::isOperator(char character)
{
	bool valid = false;

	// check character
	switch (character) {
		case '/':
			valid = true;
			break;
		case '*':
			valid = true;
			break;
		case '+':
			valid = true;
			break;
		case '-':
			valid = true;
			break;
		default :
			break;
	}

	return valid;
}


CalculatorLib::precedence CalculatorLib::calcPrecedence(char op)
{
	precedence pres;

	// check character
	switch (op) {
	case '/':
		pres.value = 2;
		pres.assoc = 'L';
		break;
	case '*':
		pres.value = 2;
		pres.assoc = 'A';
		break;
	case '+':
		pres.value = 1;
		pres.assoc = 'A';
		break;
	case '-':
		pres.value = 1;
		pres.assoc = 'L';
		break;
	default:
		pres.value = 0;
		pres.assoc = 'A';
		break;
	}

	return pres;
}


long double CalculatorLib::calculateSingle(long double num1, char op, long double num2)
{
	long double result;

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
			result = 0;
	}
	return result;
}


std::string CalculatorLib::format(long double num_value, myTypes::notation notate, int sig_fig)
{
	// std::vector<char> output;
	char buffer[50];

	// Notation
	if (notate == myTypes::Dec)
	{ // Show without exponent when possible    Format:  nnn.nn

		if (num_value < (1 * 10 ^ sig_fig)) {

			// print as decimal
			sprintf_s(buffer, 1000, "%f", num_value);
			std::string output(buffer);
			output = output.substr(0, sig_fig + 1);

			return output;
		}
		else
		{

			// print with exponent
			sprintf_s(buffer, 1000, "%.40e", num_value);

			// limit to sig_fig and replace exponent
			std::string output(buffer);

			std::string exponential = " x10^";
			std::string exponentString = output.substr(output.length() - 3, output.length());
			std::string exponent = std::to_string(std::stoi(exponentString, nullptr));

			output = output.substr(0, sig_fig + 1) + exponential + exponent;
			return output;
		}

	}
	else if (notate == myTypes::Sci)
	{ // Always show exponent    Format:  n.nnx10^n

		// print with exponent
		sprintf_s(buffer, 1000, "%.40e", num_value);

		// limit to sig_fig and replace exponent
		std::string output(buffer);

		std::string exponential = " x10^";
		std::string exponentString = output.substr(output.length() - 3, output.length());
		std::string exponent = std::to_string(std::stoi(exponentString, nullptr));

		output = output.substr(0, sig_fig + 1) + exponential + exponent;
		return output;

	}
	else if (notate == myTypes::Eng)
	{ // Always show exponent [where exponent is always a multiple of 3]    Format:  nn.nx10^n

		// print with exponent
		sprintf_s(buffer, 1000, "%.40e", num_value);

		// limit to sig_fig and replace exponent
		std::string output(buffer);

		std::string exponential = " x10^";
		std::string exponentString = output.substr(output.length() - 3, output.length());
		double sciExponentNum = std::stoi(exponentString, nullptr);

		// calculate to engineering notation
		int engExponentNum = 3 * floor(sciExponentNum / 3);
		std::string exponent = std::to_string(engExponentNum);

		// shift to engineering notation
		int shift = round(3 * fmod(sciExponentNum, 3));
		output = output.substr(0, 1), output.substr(2, shift - 2), output.substr(1, 1), output.substr(shift - 2, sig_fig + 1);   // current first digit, digits to shift left, dot, everything else

		// concatinate
		output = output.substr(0, sig_fig + 1) + exponential + exponent;
		return output;

	}
	else
	{ // error

		return std::string ();

	}
}


std::stack<CalculatorLib::calcPart> CalculatorLib::readPostfix()
{
	return postfix;			// Return postfix value
}
