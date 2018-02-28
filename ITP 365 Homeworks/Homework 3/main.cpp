// ITP 365 Fall 2016
// HW3 - Towers of Hanoi
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// Main.cpp
// Runs the Tower of Hanoi program
//

#include "Disk.h"
#include "Peg.h"

// Function: promptForDisks
// Purpose: Asks user to enter number of disks to use for the program in range 2-10
// Input: None
// Output: Number of disks user requests to use for program
int promptForDisks(){
	int numDisks;
	std::cout << "Please enter number of disks (2-10 inclusive): ";
	std::cin >> numDisks;
	// Error check
	while (numDisks < 2 || numDisks > 10){
		std::cout << "Please enter number of disks (2-10 inclusive): ";
		std::cin >> numDisks;
	}
	return numDisks;
}

// Function: promptForPegs
// Purpose: Asks user to enter which peg to start Disks at and which peg to end on
// Input: Two integers by reference holding the start Peg and end Peg number values
// Output: None
void promptForPegs(int& inputOne, int& inputTwo){
	int startPeg, endPeg;
	std::cout << "What peg would you like to start at? Please enter 1, 2, or 3: ";
	std::cin >> startPeg;
	// Check if user enters bad input
	while (startPeg != 1 && startPeg != 2 && startPeg != 3){
		std::cout << "What peg would you like to start at? Please enter 1, 2, or 3: ";
		std::cin >> startPeg;
	}
	std::cout << "What peg would you like to end at? (1 - 3 inclusive, but not " << startPeg << "): ";
	std::cin >> endPeg;
	// Check if user enters same number as starting peg
	while (endPeg == startPeg){
		std::cout << "What peg would you like to end at? (1 - 3 inclusive, but not " << startPeg << "): ";
		std::cin >> endPeg;
	}
	// Check if user enters bad input
	while (endPeg != 1 && endPeg != 2 && endPeg != 3){
		std::cout << "What peg would you like to end at? (1 - 3 inclusive, but not " << startPeg << "): ";
		std::cin >> endPeg;
	}
	// Set user's input startPeg to the first input, and endPeg to second input
	inputOne = startPeg;
	inputTwo = endPeg;
}

// Function: draw
// Purpose: Draws all the pegs and therefore all disks on pegs
// Input: GWindow reference, vector of pegs reference
// Output: None
void draw(GWindow& gwMain, Vector<Peg>& pegVec){
	// Clear current graphics in window
	gwMain.clear();
	// Draw all the pegs
	for (int i = 0; i < pegVec.size(); i++){
		pegVec[i].draw(gwMain);
	}
	// Pause to show animation
	pause(1000);
}

// Function: moveDisk
// Purpose: Move the top most disk from start peg to ending peg and redraw the window
// Input: GWindow reference, vector of pegs reference, integer starting peg, integer ending peg
// Output: none
void moveDisk(GWindow& gwRef, Vector<Peg>& pegVector, int startPeg, int endPeg){
	// Remove top most disk from start peg
	Disk dObject;
	dObject = pegVector[startPeg - 1].removeDisk();
	// Add disk to the destination peg
	pegVector[endPeg - 1].addDisk(dObject);
	// Call draw function from main
	draw(gwRef, pegVector);
}

// Function: towerSolver
// Purpose: To use recursion along with the moveDisk function to move all disks from starting peg to ending peg
// Input: GWindow reference, vector of pegs reference, integer starting peg, integer ending peg
// Output: None
void towerSolver(GWindow& gwObj, Vector<Peg>& pegCollection, int begPeg, int destPeg, int numDisksMove){
	if (numDisksMove == 0){
		return;
	}
	else{
		// to get number of tempPeg, use the fact that sum of all 3 will = 6
		int tempPeg = 6 - (begPeg + destPeg);
		// Call recursion so that N - 1 disks move from start peg to temporary peg
		towerSolver(gwObj, pegCollection, begPeg, tempPeg, numDisksMove - 1);
		// Move the last disk (disk 0) to end peg
		moveDisk(gwObj, pegCollection, begPeg, destPeg);
		// Call recursion so that N - 1 disks move from temporary peg to end peg
		towerSolver(gwObj, pegCollection, tempPeg, destPeg, numDisksMove - 1);
	}
}

int main(int argc, char** argv)
{
	// Prompt user for Disks
	int numDisks;
	numDisks = promptForDisks();
	
	// Prompt user for Pegs
	int begPeg, endPeg;
	promptForPegs(begPeg, endPeg);

	// Create a 800x500 window
	GWindow gw(800, 500);
	
	// Create and store Peg objects
	Peg p1(150, 480, 10, 460);
	Peg p2(400, 480, 10, 460);
	Peg p3(650, 480, 10, 460);
	
	// Create peg vector and add corresponding pegs to vector
	Vector<Peg> pegVector;
	pegVector.add(p1);
	pegVector.add(p2);
	pegVector.add(p3);
	
	// Go through all disks and add all to the beginning peg
	int j = 0;
	for (int i = 0; i < numDisks; i++){
		Disk d(150, 480, 200 - j, 40);
		pegVector[begPeg - 1].addDisk(d);
		j = j + 20;
	}
	
	// Draw the entire window with pegs and therefore disks
	draw(gw, pegVector);
	
	// Call towerSolver recursively to have all disks end up on ending peg
	towerSolver(gw, pegVector, begPeg, endPeg, numDisks);
	
	return 0;
}


