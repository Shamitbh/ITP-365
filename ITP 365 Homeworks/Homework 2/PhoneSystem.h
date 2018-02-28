// ITP 365 Spring 2017
// HW2 – itpPhone
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// PhoneSystem.h
// Defines PhoneSystem class that implements the
// underlying behavior for the "Dialer" app
//

#pragma once
#include "map.h"

// PhoneSystem class handles looking up the
// requested phone number from the contacts list
class PhoneSystem
{
public:
	// Function: Constructor
	// Purpose: Constructs two maps --
	//          (1) area codes -> locations
	//              (loaded from areacodes.txt)
	//          (2) phone numbers -> contacts
	//              (loaded from contacts.txt)
	// Input: None
	// Output: None
	PhoneSystem();
	
	// Function: addDigit
	// Purpose: Called when the user adds a digit
	//          to the current phone number
	// Input: Digit to add (to the end of the number)
	// Output: None
	void addDigit(char digit);
	
	// Function: backspace
	// Purpose: Removes the rightmost digit from the number
	// Input: None
	// Output: None
	void backspace();
	
	// Function: getNumber
	// Purpose: Returns the current number the user has dialed
	// Input: None
	// Output: Current number user has dialed
	std::string getNumber();
	
	// Function: lookupNumber
	// Purpose: Looks up the current number in the two maps:
	//          (1) First checks if this number is a contact
	//          (2) Otherwise, checks if the first three digits
	//              are a known area code
	// Input: None
	// Output: Returns a string that contains either:
	//         (a) The name of the contact
	//         (b) The location of the area code
	//         (c) "UNKNOWN" if it's neither a contact nor
	//             contains a valid area code
	std::string lookupNumber();
private:
	// Add member variables here
	Map<std::string, std::string> areaCode;
	Map<std::string, std::string> contact;
	std::string currPhoneNum;
};
