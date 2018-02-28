// ITP 365 Spring 2017
// HW1 - Sieve of Eratosthenes
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac

#include "gwindow.h"
#include "sieve.h"
#include "vector.h"


int main(int argc, char** argv)
{
	// Create a 500x500 window
	GWindow gw(500, 500);    
	
    // Part 3: initVectors function
    Vector<int> numberPrime;
    Vector<NumberType> compOrPrime;
    initVectors(numberPrime, compOrPrime);
	
    // Part 4: drawGrid function
    drawGrid(gw, numberPrime, compOrPrime);
    
    // Part 5: calcNextPrime function
    int startAt = 2;
    while (startAt > 0){
		// update startAt value using calcNextPrime method
        startAt = calcNextPrime(numberPrime, compOrPrime, startAt);
        drawGrid(gw, numberPrime, compOrPrime);
		// Pause for one second between iterations
        pause(1000.0);
    }
	return 0;
}
