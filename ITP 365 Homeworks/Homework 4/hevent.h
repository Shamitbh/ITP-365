// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// hevent.h
// Defines HEvent class to represent a single Holiday event
//


#pragma once

#include <string>
#include <iostream>

class HEvent{
public:
	// Function: Parameterized Constructor
	// Purpose: Creates object of class HEvent
	// Input: unsigned long long epoch time, string holiday Name
	// Output: None
	HEvent(unsigned long long eTime, std::string hName);
	
	// GETTERS:

	// Function: getEpochTime
	// Purpose: returns epoch time
	// Input: None
	// Output: unsigned long long epoch time
	unsigned long long getEpochTime();
	
	// Function: getHolidayName
	// Purpose: returns holiday name
	// Input: None
	// Output: string holiday Name
	std::string getHolidayName();
	
	// OVERLOADED OPERATORS:

	// Function: Comparison (less than) operator
	// Purpose: Compares the epoch times for event 1 versus event 2
	// Input: Event 1 and event 2 to compare
	// Returns: bool True if event 1 epoch time is less than event 2 epoch time
	friend bool operator <(HEvent& event1, HEvent& event2);
	
	// Function: Comparison (equals) operator
	// Purpose: Compares the epoch times for event 1 versus event 2
	// Input: Event 1 and event 2 to compare
	// Returns: bool True if event 1 epoch time is equal to event 2 epoch time
	friend bool operator ==(HEvent& event1, HEvent& event2);
	
	// Function: Output operator
	// Purpose: Writes the formatted holiday event to the given stream
	// Input: The stream and the event to print
	// Returns: The modified stream
	friend std::ostream& operator <<(std::ostream& os, HEvent& event1);
	
private:
	// Class member variables
	unsigned long long epochTime;
	std::string holidayName;

};
