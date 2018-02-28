// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// Main.cpp
// Runs the Wedding Planner Program
//

#include "hevent.h"
#include "dateconv.h"
#include "hcal.h"
#include "strlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

// Function: loadCal
// Purpose: Loads calendars of Holiday Events in from file
// Input: string fileName and Map with string as key and int as value
// Output: Holiday Calendar pointer
HCal* loadCal(std::string& fileName, std::map<std::string, int>& monthToIntMap){
	// Load in file and read data
	std::ifstream fileInput(fileName);
	// open file
	if (fileInput.is_open()){
		// go through file contents
		// skip the first line of the file because it's the header
		std::string str;
		std::getline(fileInput, str);
		
		// Dynamically create HCal
		HCal* holidayCal = new HCal();
		while (!fileInput.eof()){
			std::string line;
			std::getline(fileInput, line);
			// Check if nothing was read in case of eof error in csv file
			if (line == "") {
				break;
			}
			// find index of hyphen
			unsigned long indexHyphen = line.find("-", 0);
			
			// get characters up to hyphen which is the date's day
			std::string dayString = line.substr(0, indexHyphen);
			
			// convert day string to integer
			int day = 0;
			if (stringIsInteger(dayString)){
				day = stringToInteger(dayString);
			}
			
			// get characters after hyphen to the comma which is the date's month
			unsigned long indexCommaOne = line.find(",",indexHyphen + 1);
			std::string monthString = line.substr(indexHyphen + 1, 3);
			
			// convert month string to integer using Map
			int monthNum = monthToIntMap[monthString];
			
			// get second comma
			unsigned long indexCommaTwo = line.find(",",indexCommaOne + 1);
		
			// get weekday string
			unsigned long lenWeekDay = indexCommaTwo - indexCommaOne - 1;
			std::string weekDay = line.substr(indexCommaOne + 1, lenWeekDay);
			
			// get third comma
			unsigned long indexCommaThree = line.find(",",indexCommaTwo + 1);
			
			// get holiday name string
			unsigned long lenHolidayName = indexCommaThree - indexCommaTwo - 1;
			std::string holidayName = line.substr(indexCommaTwo + 1, lenHolidayName);
			
			// get holiday type
			std::string holidayType = line.substr(indexCommaThree + 1);
			
			// Dynamically create each HEvent and add to calendar
			HEvent* newEvent = new HEvent(getEpochSecs(monthNum, day, 2017), holidayName);
			holidayCal->addEvent(newEvent);
		}
		return holidayCal;
	}
	else{
		std::cout << "Error! File failed to open properly." << std::endl;
		return 0;
	}
}

// Function: merge
// Purpose: Merges two calendars together in chronological order into one big calendar
// Input: Calendar pointer for 1st calendar, Calendar pointer for 2nd calendar
// Output: Holiday Calendar pointer
HCal* merge(HCal* A, HCal* B){
	
	// Dynamically create a new HCal
	HCal* C = new HCal();
	
	// Create indexes for each of the 2 inputted calendars. Index i will be used to count
	// through HCal A and index j will be used to count through HCal B.
	int i = 0;
	int j = 0;
	
	// Create a loop that executes while i and j are within range (before the ends of their respective calendars
	while ((i < A->getVecSize()) && (j < B->getVecSize())){
		// If the HEvent at A[i] occurs before the HEvent at B[j]
		if (*A->getEventPtrVec(i) < *B->getEventPtrVec(j)){
			// Add A[i] to the end of C
			C->addEvent(A->getEventPtrVec(i));
			// Then increment i
			i++;
		}
		else{
			// Otherwise add the event at B[j] to the end of C
			C->addEvent(B->getEventPtrVec(j));
			// Then increment j
			j++;
		}
	}
	// When the above loop is over there will be a portion of either A or B left over
	if (i == A->getVecSize()){
		// If B has items remaining add them to the end of C
		for (int y = j; y < B->getVecSize(); y++){
			C->addEvent(B->getEventPtrVec(y));
		}
	}
	else{
		// If A has items remaining, add them to the end of C
		for (int z = i; z < A->getVecSize(); z++){
			C->addEvent(A->getEventPtrVec(z));
		}
	}
	return C;
}

int main(int argc, char** argv)
{
	// Create Map for later to convert months from strings to ints
	std::map<std::string, int> monthNumMap;
	monthNumMap["Jan"] = 1;
	monthNumMap["Feb"] = 2;
	monthNumMap["Mar"] = 3;
	monthNumMap["Apr"] = 4;
	monthNumMap["May"] = 5;
	monthNumMap["Jun"] = 6;
	monthNumMap["Jul"] = 7;
	monthNumMap["Aug"] = 8;
	monthNumMap["Sep"] = 9;
	monthNumMap["Oct"] = 10;
	monthNumMap["Nov"] = 11;
	monthNumMap["Dec"] = 12;
	
	// Load all calendars
	std::string file_name_US = "USholiday2017.csv";
	HCal* USCal = loadCal(file_name_US, monthNumMap);
	
	std::string file_name_China = "CHholiday2017.csv";
	HCal* CHCal = loadCal(file_name_China, monthNumMap);
	
	std::string file_name_Brazil = "BRholiday2017.csv";
	HCal* BRCal = loadCal(file_name_Brazil, monthNumMap);
	
	// Merge calendars
	HCal* partMergedCal = merge(USCal, CHCal);
	HCal* fullMergedCal = merge(partMergedCal, BRCal);
	
	std::cout << "Welcome to the Wedding Planner" << std::endl;
	// Read user input
	while (true){
		std::cout << "Please enter a date (MM/DD/YYYY): ";
		std::string date;
		getline(std::cin, date);
		if (date == "q" || date == "Q") {
			std::cout << "Quitting!" << std::endl;
			break;
		}
		std::istringstream stream(date);
		unsigned int month, day, year;
		char slash;
		stream >> month >> slash >> day >> slash >> year;
		
		// Create a new event object with user entered date
		HEvent* weddingEvent = new HEvent(getEpochSecs(month, day, year),"Wedding Day");
		
		// Check merged calendar to see if user entered date exists in calendar
		int indexOfWeddingEvent = fullMergedCal->search(weddingEvent);
		
		if (indexOfWeddingEvent != -1){
			// Found event in the calendar, print out
			std::cout << *fullMergedCal->getEventPtrVec(indexOfWeddingEvent) << std::endl;
		}
		else{
			std::cout << "That's a great day for a Wedding!" << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}
