// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// hcal.h
// Defines HCal class to represent a single Holiday Calendar of events
//

#pragma once

#include <vector>
#include "hevent.h"

class HCal{
public:
	// Function: Default Constructor
	// Purpose: Creates object of class HCal
	// Input: None
	// Output: None
	HCal();
	
	// Function: addEvent
	// Purpose: Takes a HEvent pointer and pushes it back into Vector for HCal class object
	// Input: HEvent Pointer
	// Output: None
	void addEvent(HEvent* eventPtr);
	
	// Function: getVecSize
	// Purpose: Return the HCal class object's vector size integer
	// Input: None
	// Output: int for vector's size
	int getVecSize();
	
	// Function: getEventPtrVec
	// Purpose: Gets the HEvent pointer using the integer index in the HCal class object's vector
	// Input: unsigned int for index
	// Output: HEvent pointer to specific holiday
	HEvent* getEventPtrVec(unsigned int i);
	
	// Function: search
	// Purpose: Calls binarySearch Part function
	// Input: None
	// Output: None
	int search(HEvent* eventPointer);
	
	// Function: binarySearchPart
	// Purpose: Binary search helper function to figure out index of eventPointer in merged calendar
	// Input: HEvent pointer with date we're looking for, int start index, int end index
	// Output: int for index of where event was found in the merged calendar
	int binarySearchPart(HEvent* eventPointer, int start, int end);
	
private:
	// Class member variables
	std::vector<HEvent*> eventVec;
};
