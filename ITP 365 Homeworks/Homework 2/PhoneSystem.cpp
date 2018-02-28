// ITP 365 Spring 2017
// HW2 – itpPhone
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// PhoneSystem.cpp
// Implements PhoneSystem class
//

#include "PhoneSystem.h"
#include <fstream>

// Function: Constructor
// Purpose: Constructs two maps --
//          (1) area codes -> locations
//              (loaded from areacodes.txt)
//          (2) phone numbers -> contacts
//              (loaded from contacts.txt)
// Input: None
// Output: None
PhoneSystem::PhoneSystem()
{
	std::ifstream file1("areacodes.txt");
	// open file
	if (file1.is_open()){
		// go through file contents
		while (!file1.eof()){
			std::string line;
			std::getline(file1, line);
			// get characters up to | and make it the key
			std::string key = line.substr(0, 3);
			// get characters after | and make it the value - trim because of extra white space
			std::string value = trim(line.substr(4));
			// add key and value to map
			areaCode[key] = value;
			
		}
		file1.close();
	}
	else{
		// Display error message
		error("File failed to open properly.");
	}
	
	std::ifstream file2("contacts.txt");
	// open file
	if (file2.is_open()){
		// go through file contents
		while (!file2.eof()){
			std::string line;
			std::getline(file2, line);
			// get characters up to | and make it the key
			std::string key = line.substr(0, 12);
			// get characters after | and make it the value - trim because of extra white space
			std::string value = trim(line.substr(13));
			// add key and value to map
			contact[key] = value;
		}
		file2.close();
	}
	else{
		// Display error message
		error("File failed to open properly.");
	}
}

// Function: addDigit
// Purpose: Called when the user adds a digit
//          to the current phone number
// Input: Digit to add (to the end of the number)
// Output: None
void PhoneSystem::addDigit(char digit)
{
	// Check digit count of current phone number including hyphens
	if (currPhoneNum.size() < 12){
		// Check for hyphens
		if (currPhoneNum.size() == 3){
			// Add hyphen
			currPhoneNum.push_back('-');
			// Concatenate digit to phone number
			currPhoneNum.push_back(digit);
		}
		else if (currPhoneNum.size() == 7){
			// Add hyphen
			currPhoneNum.push_back('-');
			// Concatenate digit to phone number
			currPhoneNum.push_back(digit);
		}
		else{
			// Concatenate digit to phone number
			currPhoneNum.push_back(digit);
		}
	}
}

// Function: backspace
// Purpose: Removes the rightmost digit from the number
// Input: None
// Output: None
void PhoneSystem::backspace()
{
	// Check digit count of current phone number
	if (currPhoneNum.size() > 0){
		if (currPhoneNum.size() == 9){
			// Delete digit first
			currPhoneNum.pop_back();
			// Now delete hyphen
			currPhoneNum.pop_back();
		}
		else if (currPhoneNum.size() == 5){
			// Delete digit first
			currPhoneNum.pop_back();
			// Now delete hyphen
			currPhoneNum.pop_back();
		}
		else{
			// Delete digit from number
			currPhoneNum.pop_back();
		}
	}
}

// Function: getNumber
// Purpose: Returns the current number the user has dialed
// Input: None
// Output: Current number user has dialed
std::string PhoneSystem::getNumber()
{
	// Return current number
	return currPhoneNum;
}

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
std::string PhoneSystem::lookupNumber()
{
	// Check if number is a contact
	if (contact.containsKey(currPhoneNum)){
		// number is in fact a contact - return name
		return contact.get(currPhoneNum);
	}
	// Check if the first three digits are a known area code
	else if(areaCode.containsKey(currPhoneNum.substr(0, 3))){
		// reference areaCode map to get area code
		return areaCode.get(currPhoneNum.substr(0, 3));
	}
	// Neither a contact nor contains a valid area code - UNKNOWN
	else{
		return "UNKNOWN";
	}
}
