// ITP 365 Fall 2016
// HW3 - Towers of Hanoi
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// Disk.cpp
// Implements Disk class
//

#include "Disk.h"

Disk::Disk()
{
	xCoord = 0;
	yCoord = 0;
	diskWidth = 0;
	diskHeight = 0;
}

Disk::Disk(int x, int y, int width, int height)
{
	xCoord = x;
	yCoord = y;
	diskWidth = width;
	diskHeight = height;
}

void Disk::setDiskX(int diskX)
{
	xCoord = diskX;
}

void Disk::setDiskY(int diskY)
{
	yCoord = diskY;
}

int Disk::getDiskHeight()
{
	return diskHeight;
}

void Disk::draw(GWindow& gw)
{
	// Change color of disk
	gw.setColor(diskColor);
	// Draw disk with x and y coordinates as top left of disk
	gw.fillRect(xCoord - (diskWidth / 2), yCoord - diskHeight, diskWidth, diskHeight);
}
