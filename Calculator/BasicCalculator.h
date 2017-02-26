#pragma once
#include <stack>          // std::stack
#include "myTypes.h"

class BasicCalculator
{
private:
	// Input Values
	char* input_string;

	// Output Values
	char message[64];

	// Types
	struct calcParts {
		double num1;
		char op;
		double num2;
	};

	// Internal Values
	calcParts operations[16];
	std::stack<int> sequence;


public:
	BasicCalculator();
	~BasicCalculator();
	// External
	char* Parse(char* input_string);
	char* Result(myTypes::notation, int sig_fig);

	// Internal
	void substitute(char* input_string);
	void bidmasSort(calcParts* calculation);
	double calculateSingle(calcParts single);
	char* format(double num_value, myTypes::notation, int sig_fig);
};

