#include "stdafx.h"
#include "BasicCalculator.h"


BasicCalculator::BasicCalculator()
{
}


BasicCalculator::~BasicCalculator()
{
}

char * BasicCalculator::Parse(char * input_string)
{
	// Apply Substitutions

	// Format into Operations

	// Find BIDMAS sequence

	return nullptr;
}

char * BasicCalculator::Result(myTypes::notation, int sig_fig)
{
	// Calculate Result
	while (sequence.size > 0) {
		// Seporate Next Operation

		// Calculate Result

		// Feed into Operations

	}

	// Format Output

	return nullptr;
}

void BasicCalculator::substitute(char * input_string)
{
	// Substitute operators
}

void BasicCalculator::bidmasSort(calcParts * calculation)
{
	// Assign number to each operator

	// Sort numbers

}

double BasicCalculator::calculateSingle(calcParts single)
{
	// Caculate based on operator
	switch(single.op) {
		case '/' : // Divide
			break;
		case '*' : // Multiply
			break;
		case '+' : // Add
			break;
		case '-' : // Subtract
			break;
		default : // error
			
	}
	return 0.0;
}

char * BasicCalculator::format(double num_value, myTypes::notation, int sig_fig)
{
	// Reduce to Significant Figures

	// Shift to notation

	return nullptr;
}
