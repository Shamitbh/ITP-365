// ITP 365 Spring 2017
// LP04 - Money
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: MAC
//
// money.h
// Defines and a money class for I/O and arithmetic
//

#pragma once
#include <iostream>

class Money
{
public:
	// Function: Parameterized Constructor
	// Purpose: Initializes dollars and cents to inputted values
	// Input: A long long holding the # of dollars a short holding the # of cents
	// Returns: Nothing
	Money(long long, short);

	// Function: Default Constructor
	// Purpose: Initializes dollars and cents to 0
	// Input: None
	// Returns: Nothing
	Money();

	// Function: Addition operator
	// Purpose: Adds 2 Money values together
	// Input: The left and right Money values to add
	// Returns: A new Money object with the summed values
	friend Money operator+ (const Money&, const Money&);

	// Function: Subtraction operator
	// Purpose: Subtracts second money from 1st money
	// Input: The left and right Money values to subtract
	// Returns: A new Money object with the subtracted values
	friend Money operator- (const Money&, const Money&);

	// Function: Multiplication operator
	// Purpose: Multiples inputted money by a given factor
	// Input: The left value is the money, the right value is the factor
	// Returns: A new Money object with the multiplied values
	friend Money operator* (const Money&, const double&);

	// Function: Division operator
	// Purpose: Divides inputted money by a given factor
	// Input: The left value is the money, the right value is the factor
	// Returns: A new Money object with the divided values
	friend Money operator/ (const Money&, const double&);

	// Function: Output operator
	// Purpose: Writes the formatted money's value to the given stream
	// Input: The stream and the money to print
	// Returns: The modified stream
	friend std::ostream& operator<< (std::ostream&, Money&);

	// Function: Input operator
	// Purpose: Reads a money's value to the given stream
	// Input: The stream and the money to store the values in
	// Returns: The modified stream
	friend std::istream& operator>> (std::istream&, Money&);
private:
	long long dollars;			// Stores whole number of dollars
	short cents;				// Stores whole number of cents
};
