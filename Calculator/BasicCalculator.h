#pragma once
#include <stack>          // std::stack
#include "myTypes.h"
#include <vector>

class BasicCalculator
{
private:
	// Types
	struct calcParts {
		double num1;
		char op;
		double num2;
	};

	// Global Values
	calcParts operations[16];
	std::stack<int> sequence;
	double answer;


public:
	BasicCalculator();
	~BasicCalculator();
	// External
	std::vector<char> Parse(const std::vector<char> user_input);
	std::vector<char> Result(myTypes::notation notate, int sig_fig);

	// Internal
	void substitute(std::vector<char> &input_string);
	std::vector<char> createParts(std::vector<char> input_string);
	bool isOperator(char character);
	void bidmasSort();
	double calculateSingle(calcParts single);
	std::vector<char> format(double num_value, myTypes::notation notate, int sig_fig);
};

