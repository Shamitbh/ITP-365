// ITP 365 Spring 2017
// HW2 – itpPhone
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// Calculator.h
// Defines Calculator class as an RPN calculator
//

#pragma once

#include "stack.h"

// CalcType enum defines the four types of
// arithmetic that the calculator supports
enum CalcType
{
	ADD, // 0
	SUB, // 1
	MUL, // 2
	DIV  // 3
};

// Calculator class is an RPN calculator
class Calculator
{
public:
	// Function: Constructor
	// Purpose: Does nothing
	Calculator();
	
	// Function: pushNum
	// Purpose: Pushes number onto the stack
	// Input: number to push
	// Output: None
	void pushNum(int number);
	
	// Function: peekTop
	// Purpose: Returns the number on top of the stack
	//          (provided the stack is not empty)
	// Input: None
	// Output: Number on top of the stack
	int peekTop();
	
	// Function: doCalc
	// Purpose: Performs the requested arithmetic,
	//          provided there are two numbers on the stack.
	//          Then pushes the result onto the stack.
	//          Silently fails if the stack has less than two
	//          numbers on it.
	// Input: Type of arithmetic to perform
	// Output: None
	void doCalc(CalcType type);
private:
	// Add member variables here
	Stack<int> numbers;
};
