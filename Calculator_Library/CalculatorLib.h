#pragma once
#include <stack>          // std::stack
#include "../hFiles/myTypes.h"
#include <vector>

#include "iostream"

class CalculatorLib
{
public:
	// Types
	struct calcPart {
		char op;
		long double num;

		bool operator==(calcPart& other) const
		{
			return (op == other.op) && (num == other.num);
		}
	};

	struct partsOut {
		std::string message;
		std::stack<calcPart> infix;

		bool operator==(partsOut& other) const
		{
			bool result2(true);
			CalculatorLib::calcPart copyTop;						// stack elements
			std::stack<calcPart> otherCopy = other.infix;			// copy of "other" stack
			std::stack<calcPart> infixCopy = infix;					// copy of "infix" stack
			for (int i = 0; i < otherCopy.size() && i < infixCopy.size(); i++) {
				if (otherCopy.top() == infixCopy.top()) {
					otherCopy.pop();	infixCopy.pop();			// pop stacks
				} else {
					otherCopy.pop();	infixCopy.pop();			// pop stacks
					result2 = false;								// stacks are not equal
					break;
				}
			}
			return (message == other.message) && result2;
		}
	};

	struct precedence {
		int value;
		char assoc;

		bool operator==(precedence& other) const
		{
			return (value == other.value) && (assoc == other.assoc);
		}
	};

private:
	// Global Values
	std::stack<calcPart> postfix;
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
	std::string postfixConvert(std::stack<calcPart> infix);
	bool isOperator(char character);
	bool isExtendedOperator(char firstChar, char secondChar, char thirdChar);
	precedence calcPrecedence(char op);
	long double calculateSingle(long double num1, char op, long double num2);
	std::string format(long double num_value, myTypes::notation notate, int sig_fig);
	std::stack<calcPart> readPostfix();
	long double getAnswer();
	void setAnswer(long double value);
};

