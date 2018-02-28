// ITP 365 Spring 2017
// LP5 – Recursion
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac


#include <iostream>

// Function: sumDigits
// Purpose: Takes an integer and sums each digit of the integer
// Input: integer number that user inputs
// Output: integer representing the sum of all digits of user inputted number
int sumDigits(int number){
	if (number < 10){
		return number;
	}
	else{
		int right = 0;
		int left = 0;
		right = number % 10;
		left = number / 10;
		return right + sumDigits(left);
	}
}

// Function: getGCD
// Purpose: Takes in two integers and finds the greatest common divisor
// Input: two integer numbers that user inputs
// Output: integer representing the greatest common divisor between the two numbers
int getGCD(int numFirst, int numSecond){
	if (numFirst % numSecond == 0){
		return numSecond;
	}
	else{
		return getGCD(numSecond, numFirst % numSecond);
	}
}

int main(int argc, const char * argv[]) {
	int numOne, numTwo;
	// Prompt user for input
	std::cout << "Gimme a number: ";
	std::cin >> numOne;
	std::cout << "Gimme another number: ";
	std::cin >> numTwo;
	
	// Display output to user after calculating using functions
	std::cout << "Sum digits (" << numOne << ") = " << sumDigits(numOne) << std::endl;
	std::cout << "Sum digits (" << numTwo << ") = " << sumDigits(numTwo) << std::endl;
	std::cout << "gcd(" << numOne << ", " << numTwo << ") = " << getGCD(numOne, numTwo) << std::endl;
	
    return 0;
}
