// ITP 365 Fall 2016
// HW3 - Towers of Hanoi
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// Peg.cpp
// Implements Peg class
//

#include "Peg.h"

Peg::Peg()
{
	xCoordPeg = 0;
	yCoordPeg = 0;
	widthPeg = 0;
	heightPeg = 0;
}

Peg::Peg(int x, int y, int width, int height)
{
	xCoordPeg = x;
	yCoordPeg = y;
	widthPeg = width;
	heightPeg = height;
}

void Peg::draw(GWindow& gw)
{
	// Set each peg to be black in color
	gw.setColor("black");
	gw.fillRect(xCoordPeg - (widthPeg / 2), yCoordPeg - heightPeg, widthPeg, heightPeg);
	
	// Go through disk vector and draw each disk
	for (int i = 0; i < diskVec.size(); i++){
		diskVec[i].draw(gw);
	}
}

void Peg::addDisk(Disk d)
{
	// Set disk x and y value while tracking where other disks are on peg
	d.setDiskX(xCoordPeg);
	d.setDiskY(yCoordPeg - (diskVec.size() * d.getDiskHeight()));
	// Add disk to the disk vector
	diskVec.add(d);
}

Disk Peg::removeDisk()
{
	// Create temporary Disk variable to hold value of last Disk in vector
	Disk d = diskVec.get(diskVec.size()-1);
	// Remove the last Disk in vector
	diskVec.remove(diskVec.size() - 1);
	// Return the temporary Disk variable
	return d;
}


