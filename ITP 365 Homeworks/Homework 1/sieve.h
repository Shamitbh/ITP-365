#pragma once

#include "gwindow.h"

enum NumberType{
    UNKNOWN,
    PRIME,
    COMPOSITE
};

// Function: drawSquare
// Purpose: Draws a single 50x50 pixel square
// Parameters: A GWindow reference, integer value to display, color to display in square, double x-coord. of top left corner of square, and double y-coord. of top-left corner of square
// Returns: Nothing
void drawSquare(GWindow& gw, int number, NumberType color, double x, double y);

// Function: initVectors
// Purpose: Initialize both vectors (number vector to hold values 2-101) and numberType vector to store 100 elements all initially UNKNOWN
// Parameters: Vector of integers by reference and a Vector of NumberTypes by reference
// Returns: Nothing
void initVectors(Vector<int>& numbers, Vector<NumberType>& numType);

// Function: drawGrid
// Purpose: Draws the current state of the grid
// Parameters: A GWindow reference, a vector of integers by reference, and a vector of NumberTypes by reference
// Returns: Nothing
void drawGrid(GWindow& gw, Vector<int>& numbersSieve, Vector<NumberType>& numTypeSieve);

// Function: calcNextPrime
// Purpose: Finds next prime number in sequence and marks its multiples as composite
// Input: A vector of integers by reference, a vector of numberTypes by reference, and an integer (value) to start testing at
// Output: An integer corresponding to the next prime number or -1 if no prime numbers are found
int calcNextPrime(Vector<int>& numSieve, Vector<NumberType>& typeSieve, int startAt);
