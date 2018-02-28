// ITP 365 Spring 2017
// LP6 - Timings
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac

#include <iostream>
#include <chrono>
#include <list>
#include <vector>

int main()
{
	std::vector<int> myVec;
	std::list<int> myList;
	
	unsigned int stopNum = -1;
	std::cout << "Where shall I stop counting?\n> ";
	std::cin >> stopNum;
	
	std::chrono::time_point<std::chrono::system_clock> timeStart, timeEnd;
	std::chrono::duration<double> elapsedTime;
	
	// Vector insert at end
	std::cout << "Vector insert @ end... ";
	timeStart = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < stopNum; i++)
	{
		myVec.push_back(i);
		// Does nothing,
		// Just timing loop
	}
	timeEnd = std::chrono::system_clock::now();
	elapsedTime = timeEnd - timeStart;
	std::cout << elapsedTime.count() << " s" << std::endl;
	
	// Vector remove at end
	std::cout << "Vector remove @ end... ";
	timeStart = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < stopNum; i++)
	{
		myVec.pop_back();
		// Does nothing,
		// Just timing loop
	}
	timeEnd = std::chrono::system_clock::now();
	elapsedTime = timeEnd - timeStart;
	std::cout << elapsedTime.count() << " s" << std::endl;
	
	// Vector insert at front
	std::cout << "Vector insert @ front... ";
	timeStart = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < stopNum; i++)
	{
		myVec.insert(myVec.begin(),i);
		// Does nothing,
		// Just timing loop
	}
	timeEnd = std::chrono::system_clock::now();
	elapsedTime = timeEnd - timeStart;
	std::cout << elapsedTime.count() << " s" << std::endl;
	
	// Vector remove at front
	std::cout << "Vector remove @ front... ";
	timeStart = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < stopNum; i++)
	{
		myVec.erase(myVec.begin());
		// Does nothing,
		// Just timing loop
	}
	timeEnd = std::chrono::system_clock::now();
	elapsedTime = timeEnd - timeStart;
	std::cout << elapsedTime.count() << " s" << std::endl;
	
	// List insert at end
	std::cout << "List insert @ end... ";
	timeStart = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < stopNum; i++)
	{
		myList.push_back(i);
		// Does nothing,
		// Just timing loop
	}
	timeEnd = std::chrono::system_clock::now();
	elapsedTime = timeEnd - timeStart;
	std::cout << elapsedTime.count() << " s" << std::endl;
	
	// List remove at end
	std::cout << "List remove @ end... ";
	timeStart = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < stopNum; i++)
	{
		myList.pop_front();
		// Does nothing,
		// Just timing loop
	}
	timeEnd = std::chrono::system_clock::now();
	elapsedTime = timeEnd - timeStart;
	std::cout << elapsedTime.count() << " s" << std::endl;
	
	// List insert at front
	std::cout << "List insert @ front... ";
	timeStart = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < stopNum; i++)
	{
		myList.push_front(i);
		// Does nothing,
		// Just timing loop
	}
	timeEnd = std::chrono::system_clock::now();
	elapsedTime = timeEnd - timeStart;
	std::cout << elapsedTime.count() << " s" << std::endl;
	
	// List remove at front
	std::cout << "List remove @ front... ";
	timeStart = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < stopNum; i++)
	{
		myList.pop_front();
		// Does nothing,
		// Just timing loop
	}
	timeEnd = std::chrono::system_clock::now();
	elapsedTime = timeEnd - timeStart;
	std::cout << elapsedTime.count() << " s" << std::endl;

	return 0;
}
