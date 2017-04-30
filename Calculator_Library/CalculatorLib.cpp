#include "stdafx.h"
#include "CalculatorLib.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>       /* log10 */


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
		// Clear postfix stack
		while (!postfix.empty()) {
			postfix.pop();
		}

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

		// operator or number?
		if (item.op == 'n') {
			// If number
			// Push to number stack
			numStack.push(item.num);

		}
		else if (item.op == 's' || item.op == 'c' || item.op == 't') {
			// Single Input operators
			// Calculate Result
			num2 = numStack.top();	numStack.pop();

			result = calculateSingle(0, item.op, num2);

			// Push result to number stack
			numStack.push(result);

		}
		else {
			// Multiple Input operators
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
	if (numStack.size() == 1) {
		if (!isinf(numStack.top())) {
			answer = numStack.top();
			output = format(answer, notate, sig_fig);
		}
		else {
			output = "Answer exceeds calculation limit";
		}
	}
	else {
		output = "Not enough operators to resolve calculation";
	}

	return output;
}


void CalculatorLib::substitute(std::vector<char> &input_string)
{
	// Substitute operators character by character
	for ( int i = 0; i < input_string.size(); i++ )
	{
		// seporate value
		char character = input_string[i];

		// Convert to lower case
		if (isalpha(character)) {
			character = tolower(character);
			input_string[i] = character;
		}

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
	std::stringstream errorString;		//Message string for error message
	int i;								//For loop index
	bool extendedCheck;					//boolean for isExtendedOperator check
	bool trailingNum;					//boolean for extended operator trailing number check
	

	// read char by char & check if first value is operator
	for (i = 0; i < input_string.size(); i++)
	{
		// seporate value
		char character = input_string[i];

		// if long enough perform isExtendedOperator check
		if (input_string.size() > i + 2) {
			extendedCheck = isExtendedOperator(character, input_string[i + 1], input_string[i + 2]);
		}
		else {
			extendedCheck = false;
		}

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
		else if (extendedCheck) {
			// If extended operator: check for adjacent numbers and output to stack

			// if long enough check for trailing number
			if (input_string.size() > i + 3) {
				trailingNum = false;
				if (input_string.size() >= i + 6) {
					trailingNum = isExtendedOperator(input_string[i + 3], input_string[i + 4], input_string[i + 5]);
				}
				if (!trailingNum) {
					trailingNum = isdigit(input_string[i + 3]);
				};
			}
			else {
				trailingNum = false;
			}

			// If last character was a number
			if (last == 'n') {
				if (first == true) {
					// If this is the first char
					first = false;
				}
				else {
					snum >> dnum;  //convert number to long double

					snum.str(std::string());	// clear stringstream
					snum.clear();


					// Push built number and operator to stack
					part.op = 'n';
					part.num = dnum;
					infix.push(part);  // Push number


					// Push multiply operator to stack eg: 2cos30  ==  2*cos30
					part.op = '*';
					part.num = 0;
					infix.push(part);  // Push operator
				}
			}

			// extended operator type
			switch (character) {
			case 'a':
				// Ans
				// check for no trailing num
				if (!trailingNum) {
					// If ans
					snum << answer;
					last = 'n';

					//shift loop index
					i = i + 2;
				}
				else {
					// If it has a trailing number
					last = '~';
					errorString << "Trailing number after \"" << character << input_string[i + 1] << input_string[i + 2];
				}
				break;
			case 's':
			case 'c':
			case 't':
				// Sin || Cos || Tan
				// check for trailing num
				if (trailingNum) {
					// If a valid operator
					last = 'o';
					
					part.op = character;
					part.num = 0;
					infix.push(part);  // Push operator

					//shift loop index
					i = i + 2;
				}
				else {
					// If missing trailing number
					last = '~';
					errorString << "Missing number after \"" << character << input_string[i + 1] << input_string[i + 2];
				}
				break;
			default :
				// this case cannot happen due to isExtendedOperator check
				break;
			}

			// if error occured
			if (last == '~') {
				break;
			}
		}
		else if (isOperator(character) && (last != 'o')) {
			// If operator output to stack
			last = 'o';

			if (first == true) {
				// If this is the first char
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
			errorString << "Invalid input \"" << character;

			break;
		}
	}

	
	// errors and incomplete numbers
	std::string testString1 = snum.str();
	if ((last != '~') && (first || !testString1.empty()))
	{
		// If last element was not an error and if (first or snum is not empty)
		// Push incomplete number to stack
		if (first == true) {
			// If this is the first char
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
	else if (last = '~') {
		// if last element was an error
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
		message << errorString.str() << "\" at: ";


		// add problem subset
		if (end > input_string.size() - 1) {
			end = input_string.size() - 1;
		}
		for (int x = start; x < end + 1; x++) {
			message << input_string[x];
		}
	}


	// If no error check last type was a number
	std::string testString2 = message.str();
	if (testString2.empty()) {
		// not number?
		if (infix.top().op != 'n') {
			message << "Invalid sequence: Does not end in a number";
		}
	}


	// Flip infix stack
	std::stack<calcPart> copy;
	int iterations = infix.size();
	for (int i = 0; i < iterations; i++) {

		// pop top element and push to infix stack
		copy.push(infix.top());	infix.pop();

	}
	infix = copy;


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
							numstack.push(opstack.top());	opstack.pop();	//Left Assiciativity
						}
						else if (opnewImport.assoc == 'A') {
							// If the new operator is associative

							// push top of operator stack to number stack
							numstack.push(opstack.top());	opstack.pop();	//Same Assiciativity
						}
						else if (opnewImport.assoc == 'R') {
							// If the new operator has right-associativity

							// push operator to operator stack
							opstack.push(opnew);							//Right Associativity

							// Step complete
							correct = true;
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
		case '^':
			valid = true;
			break;
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
		default:
			break;
	}

	return valid;
}


bool CalculatorLib::isExtendedOperator(char firstChar, char secondChar, char thirdChar)
{
	bool valid = false;

	// check characters
	if (firstChar == 'a' && secondChar == 'n' && thirdChar == 's') {
		// Ans
		valid = true;
	}
	else if (firstChar == 's' && secondChar == 'i' && thirdChar == 'n') {
		// Sin
		valid = true;
	}
	else if (firstChar == 'c' && secondChar == 'o' && thirdChar == 's') {
		// Cos
		valid = true;
	}
	else if (firstChar == 't' && secondChar == 'a' && thirdChar == 'n') {
		// Tan
		valid = true;
	}
	else {
		// not an extended operator
	}

	return valid;
}


CalculatorLib::precedence CalculatorLib::calcPrecedence(char op)
{
	precedence pres;

	// check character
	switch (op) {
		case 's':
			pres.value = 4;
			pres.assoc = 'R';
			break;
		case 'c':
			pres.value = 4;
			pres.assoc = 'R';
			break;
		case 't':
			pres.value = 4;
			pres.assoc = 'R';
			break;
		case '^':
			pres.value = 3;
			pres.assoc = 'R';
			break;
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
		case 's': // Sin(x)
			result = sin(num2);
			break;
		case 'c': // Cos(x)
			result = cos(num2);
			break;
		case 't': // Tan(x)
			result = tan(num2);
			break;
		case '^': // Power
			result = pow(num1, num2);
			break;
		case '/': // Divide
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
	// sig_fig empty?
	if (sig_fig == 0) {
		sig_fig = 10;
	}

	// Create Variables & Constants
	char outBuffer[256];
	std::string exponential = " x10^";
	std::size_t found;

	// Calculate base 10 exponent of number
	float exponent = log10(abs(num_value));
	if (num_value == 0) {
		exponent = 0;
	}
	else {
		exponent = floorf(exponent);
	}

	// Notation
	if (notate == myTypes::Dec)
	{ // Show without exponent when possible

		if (exponent < sig_fig)
		{ // Show without exponent    Format:  nn.nn

			// print as decimal
			int precision = sig_fig - exponent;
			sprintf_s(outBuffer, 256, "%.*f", precision, num_value);
			std::string output(outBuffer);

			// remove trailing 0s
			std::size_t found = output.find('.');
			if (found != std::string::npos) {
				while (output.substr(output.length() - 1) == "0") {
					output = output.substr(0 ,output.length() - 1);		// remove 0
				}
				if ((output.substr(output.length() - 1) == ".")) {
					output = output.substr(0, output.length() - 1);		// remove .
				}
			}

			return output;
		}
		else
		{ // Show exponent    Format:  n.nn x10^n

			// print with exponent
			sprintf_s(outBuffer, 256, "%.*e", (sig_fig - 1), num_value);
			std::string output(outBuffer);

			// remove exponent
			while (output.substr(output.length() - 1) != "e") {
				output = output.substr(0, output.length() - 1);		// remove exponent value
			}
			output = output.substr(0, output.length() - 1);		// remove e

			// remove trailing 0s
			found = output.find('.');
			if (found != std::string::npos) {
				while (output.substr(output.length() - 1) == "0") {
					output = output.substr(0, output.length() - 1);		// remove 0
				}
				if ((output.substr(output.length() - 1) == ".")) {
					output = output.substr(0, output.length() - 1);		// remove .
				}
			}
			
			// add new exponent
			int exponentInt = exponent;
			output = output + exponential + std::to_string(exponentInt);

			return output;
		}

	}
	else if (notate == myTypes::Sci)
	{ // Always show exponent    Format:  n.nn x10^n

		// print with exponent
		sprintf_s(outBuffer, 256, "%.*e", (sig_fig - 1), num_value);
		std::string output(outBuffer);

		// remove exponent
		while (output.substr(output.length() - 1) != "e") {
			output = output.substr(0, output.length() - 1);		// remove exponent value
		}
		output = output.substr(0, output.length() - 1);		// remove e

		// remove trailing 0s
		found = output.find('.');
		if (found != std::string::npos) {
			while (output.substr(output.length() - 1) == "0") {
				output = output.substr(0, output.length() - 1);		// remove 0
			}
			if ((output.substr(output.length() - 1) == ".")) {
				output = output.substr(0, output.length() - 1);		// remove .
			}
		}

		// add new exponent
		int exponentInt = exponent;
		output = output + exponential + std::to_string(exponentInt);

		return output;

	}
	else if (notate == myTypes::Eng)
	{ // Always show exponent [where exponent is always a multiple of 3]    Format:  nn.nn x10^n

		// print with exponent
		sprintf_s(outBuffer, 256, "%.*e", (sig_fig - 1), num_value);
		std::string output(outBuffer);

		// remove exponent
		while (output.substr(output.length() - 1) != "e") {
			output = output.substr(0, output.length() - 1);		// remove exponent value
		}
		output = output.substr(0, output.length() - 1);		// remove e

		// remove trailing 0s
		found = output.find('.');
		if (found != std::string::npos) {
			while (output.substr(output.length() - 1) == "0") {
				output = output.substr(0, output.length() - 1);		// remove 0
			}
			if ((output.substr(output.length() - 1) == ".")) {
				output = output.substr(0, output.length() - 1);		// remove .
			}
		}

		// calculate to engineering notation
		int engExponentNum;
		if (exponent >= 0) {
			// if positive exponent
			engExponentNum = 3 * floorf(exponent / 3);
		}
		else {
			// if negative exponent
			engExponentNum = -3 * ceilf(abs(exponent) / 3);
		}
		int remainingShift = exponent - engExponentNum;

		// shift to engineering notation
		std::size_t position = output.find('.');
		if (position != std::string::npos)
		{ // if string contains a decimal pont
			// shift until complete or end of string
			std::string beforeDot = output.substr(0, position) + output.substr(position +1, remainingShift);		// characters before new decimal point

			if (position + 1 + remainingShift > output.length())
			{ // if end of string was reached before finishing
				output = beforeDot;
				remainingShift = position + remainingShift - output.length();
			}
			else if (position + 1 + remainingShift == output.length())
			{ // if string is exact length including dot
				output = beforeDot;
				remainingShift = 0;
			}
			else
			{ // concatinate remainder of string
				output = beforeDot + "." + output.substr(position + 1 + remainingShift);
				remainingShift = 0;
			}

		}

		// pad any remaining shift with 0s
		for (remainingShift; remainingShift > 0; remainingShift--) {
			output = output + "0";								// pad with 0
		}

		// add new exponent
		output = output + exponential + std::to_string(engExponentNum);

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

long double CalculatorLib::getAnswer()
{
	return answer;			// Return value of answer
}

void CalculatorLib::setAnswer(long double value)
{
	answer = value;			// Set answer in memory to value
}
