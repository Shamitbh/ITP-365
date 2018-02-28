// ITP 365 Fall 2016
// HW3 - Towers of Hanoi
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// Peg.h
// Defines Peg class to represent a single Peg in the simulation
//

#pragma once
#include "Disk.h"
#include "vector.h"

class Peg{
public:
	// Function: Default Constructor
	// Purpose: Initializes x-coord, y-coord, width, and height to 0
	// Input: None
	// Output: None
	Peg();
	
	// Function: Parameterized Constructor
	// Purpose: Initializes x-coord, y-coord, width, and height to inputted values
	// Input: int x coordinate of Peg, int y coordinate of Peg, int width of Peg, and int height of Peg
	// Output: None
	Peg(int x, int y, int width, int height);
	
	// Function: Draw
	// Purpose: Uses the GWindow to draw the Peg AND all of the disks that are on that peg centered to the peg
	// Input: GWindow by reference
	// Output: None
	void draw(GWindow& gw);
	
	// Function: addDisk
	// Purpose: Disk object that is passed in as input is added to the end of the Vector
	// Input: Disk object
	// Output: None
	void addDisk(Disk d);
	
	// Function: removeDisk
	// Purpose: Removes the last Disk on the peg and returns it
	// Input: None
	// Output: Returns a Disk variable
	Disk removeDisk();
	
private:
	// Add member variables here
	Vector<Disk> diskVec;
	int xCoordPeg;
	int yCoordPeg;
	int widthPeg;
	int heightPeg;
	std::string colorPeg;
};
