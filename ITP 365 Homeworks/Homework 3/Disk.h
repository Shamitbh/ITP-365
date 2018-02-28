// ITP 365 Fall 2016
// HW3 - Towers of Hanoi
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// Disk.h
// Defines Disk class to represent a single Disk in the simulation
//

#pragma once
#include <string>
#include "gwindow.h"

class Disk{
public:
	// Function: Default Constructor
	// Purpose: Initializes x-coord, y-coord, width, and height to 0
	// Input: None
	// Output: None
	Disk();
	
	// Function: Parameterized Constructor
	// Purpose: Initializes x-coord, y-coord, width, and height to inputted values
	// Input: int x coordinate of Disk, int y coordinate of Disk, int width of Disk, and int height of Disk
	// Output: None
	Disk(int x, int y, int width, int height);
	
	// Setters and getters
	void setDiskX(int diskX);
	void setDiskY(int diskY);
	int getDiskHeight();
	
	// Function: Draw
	// Purpose: Uses the GWindow to create colored rectangles representing Disks
	// Input: GWindow by reference
	// Output: None
	void draw(GWindow& gw);
private:
	// Add member variables here
	int xCoord;
	int yCoord;
	int diskWidth;
	int diskHeight;
	std::string diskColor = "#3389EB";
};
