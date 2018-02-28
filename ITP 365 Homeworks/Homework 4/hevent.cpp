// ITP 365 Spring 2017
// HW4 - Wedding Planner
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// hevent.cpp
// Implements HEvent class
//



#include "hevent.h"
#include "dateconv.h"

HEvent::HEvent(unsigned long long eTime, std::string hName){
	epochTime = eTime;
	holidayName = hName;
}

unsigned long long HEvent::getEpochTime()
{
	return epochTime;
}

std::string HEvent::getHolidayName()
{
	return holidayName;
}

bool operator <(HEvent& event1, HEvent& event2)
{
	return event1.epochTime < event2.epochTime;
}

bool operator ==(HEvent& event1, HEvent& event2)
{
	return event1.epochTime == event2.epochTime;
}

std::ostream& operator <<(std::ostream& os, HEvent& event){
	// get month unsigned int for event object
	unsigned int month = getMonth(event.getEpochTime());
	
	// get day unsigned int for event object
	unsigned int day = getMonthDay(event.getEpochTime());
	
	// get year unsigned int for event object
	unsigned int year = getYear(event.getEpochTime());
	
	// get event holiday name
	std::string eventName = event.getHolidayName();
	
	os << month << "/" << day << "/" << year << " is " << eventName;
	return os;
}
