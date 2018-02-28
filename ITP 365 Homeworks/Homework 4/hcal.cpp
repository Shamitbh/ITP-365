// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// hcal.cpp
// Implements HCal class
//

#include "hcal.h"

HCal::HCal(){
	
}

void HCal::addEvent(HEvent* eventPtr){
	eventVec.push_back(eventPtr);
}

int HCal::getVecSize(){
	return eventVec.size();
}

HEvent* HCal::getEventPtrVec(unsigned int i){
	return eventVec[i];
}

int HCal::search(HEvent* eventPointer){
	return binarySearchPart(eventPointer, 0, getVecSize() - 1);
}

int HCal::binarySearchPart(HEvent* eventPointer, int start, int end){
	// Not found
	if (end < start){
		return -1;
	}
	// If found, return the index
	int middleIndex = (end + start) / 2;
	if (*getEventPtrVec(middleIndex) == *eventPointer){
		return middleIndex;
	}
	// Handle either 1st or 2nd section using binary Search
	if (*getEventPtrVec(middleIndex) < *eventPointer){
		return binarySearchPart(eventPointer, middleIndex + 1, end);
	}
	else{
		return binarySearchPart(eventPointer, start, middleIndex - 1);
	}
}
