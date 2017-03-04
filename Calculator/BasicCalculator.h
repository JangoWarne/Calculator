#pragma once
#include <stack>          // std::stack
#include "myTypes.h"
#include <vector>

class BasicCalculator
{
private:
	// Types
	struct calcParts {
		char op;
		double num;
	};
	struct partsOut {
		std::vector<char> message;
		std::stack<calcParts> infix;
	};

	// Global Values
	std::stack<calcParts> postfix;
	double answer;


public:
	BasicCalculator();
	~BasicCalculator();
	// External
	std::vector<char> Parse(const std::vector<char> user_input);
	std::vector<char> Result(myTypes::notation notate, int sig_fig);

	// Internal
	void substitute(std::vector<char> &input_string);
	partsOut splitParts(std::vector<char> input_string);
	void postfixConvert(std::stack<calcParts> infix);
	bool isOperator(char character);
	double calculateSingle(double num1, char op, double num2);
	std::vector<char> format(double num_value, myTypes::notation notate, int sig_fig);
};

