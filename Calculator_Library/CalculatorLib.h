#pragma once
#include <stack>          // std::stack
#include "../hFiles/myTypes.h"
#include <vector>

class CalculatorLib
{
private:
	// Types
	struct calcParts {
		char op;
		long double num;
	};
	struct partsOut {
		std::string message;
		std::stack<calcParts> infix;
	};
	struct precedence {
		int value;
		char assoc;
	};

	// Global Values
	std::stack<calcParts> postfix;
	long double answer;


public:
	CalculatorLib();
	~CalculatorLib();
	// External
	std::string Parse(const std::string user_input);
	std::string Result(myTypes::notation notate, int sig_fig);

	// Internal
	void substitute(std::vector<char> &input_string);
	partsOut splitParts(std::vector<char> input_string);
	std::string postfixConvert(std::stack<calcParts> infix);
	bool isOperator(char character);
	precedence calcPrecedence(char op);
	long double calculateSingle(long double num1, char op, long double num2);
	std::string format(long double num_value, myTypes::notation notate, int sig_fig);
};

