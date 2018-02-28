// ITP 365 Spring 2017
// HW2 – itpPhone
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// Calculator.cpp
// Implements Calculator class
//

#include "Calculator.h"

// Function: Constructor
// Purpose: Does nothing
Calculator::Calculator()
{
	
}

// Function: pushNum
// Purpose: Pushes number onto the stack
// Input: number to push
// Output: None
void Calculator::pushNum(int number)
{
	// Push number on to stack
	numbers.push(number);
}

// Function: peekTop
// Purpose: Returns the number on top of the stack
//          (provided the stack is not empty)
// Input: None
// Output: Number on top of the stack
int Calculator::peekTop()
{
	// Check if stack is empty
	if (!numbers.isEmpty()){
		return numbers.peek();
	}
	// Stack is empty
	return 0;
}

// Function: doCalc
// Purpose: Performs the requested arithmetic,
//          provided there are two numbers on the stack.
//          Then pushes the result onto the stack.
//          Silently fails if the stack has less than two
//          numbers on it.
// Input: Type of arithmetic to perform
// Output: None
void Calculator::doCalc(CalcType type)
{
	int rightVal = 0;
	int leftVal = 0;
	int total = 0;
	// Check stack size to make sure atleast 2 numbers on stack
	if (numbers.size() >= 2){
		// Pop 2 numbers from stack in right order
		rightVal = numbers.pop();
		leftVal = numbers.pop();
		// Check enum type
		switch(type){
			case ADD:
				total = leftVal + rightVal;
				break;
			case SUB:
				total = leftVal - rightVal;
				break;
			case MUL:
				total = leftVal * rightVal;
				break;
			case DIV:
				total = leftVal / rightVal;
				break;
		}
		// Push the total back on to stack
		numbers.push(total);
	}
}
