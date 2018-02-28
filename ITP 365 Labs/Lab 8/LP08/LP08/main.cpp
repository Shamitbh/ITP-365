// Shamit Bhatia
// ITP 365, Spring 2017
// Lab 8
// Shamitbh@usc.edu
// Platform: Mac


#include <iostream>
#include <list>

// Function: printList
// Purpose: prints out the values in the current list
// Input: some list of integers
// Output: None
void printList(std::list<int> thisList)
{
	
	std::cout << "{ ";
	for (int i : thisList)
	{
		std::cout << i << "  ";
	}
	std::cout << "}" << std::endl;
}


int main()
{
	std::list<int> myList;
	
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i*2);
	}
	std::cout << "Beginning list..." << std::endl;
	printList(myList);
	auto itr = myList.begin();
	
	// Insert value of 100 before beginning and have iterator point to it
	itr = myList.insert(itr, 100);
	std::cout << "After insert @ begin..." << std::endl;
	printList(myList);
	
	// Increase iterator by 4 to point to value of 6
	itr++;
	itr++;
	itr++;
	itr++;
	
	// Insert value of 101 before value 6 and have iterator point to it
	itr = myList.insert(itr, 101);
	std::cout << "After one insert @ 1st half..." << std::endl;
	printList(myList);
	
	// Increase iterator by 4 to point to value of 12
	itr++;
	itr++;
	itr++;
	itr++;
	
	// Insert value of 103 before value 12 and have iterator point to it
	itr = myList.insert(itr, 103);
	// Insert value of 102 before value 103 and have iterator point to it
	itr = myList.insert(itr, 102);
	std::cout << "After a double insert @ 2nd half..." << std::endl;
	printList(myList);
	
	// Have iterator take value at end and insert 104
	itr = myList.end();
	
	itr = myList.insert(itr, 104);
	std::cout << "After a insert @ end..." << std::endl;
	printList(myList);
	
	// Erase beginning
	itr = myList.begin();
	itr = myList.erase(itr);
	std::cout << "After a erase @ begin..." << std::endl;
	printList(myList);
	
	// Erase value of 101
	itr++;
	itr++;
	itr++;
	itr = myList.erase(itr);
	std::cout << "After a erase @ 1st half..." << std::endl;
	printList(myList);
	
	// Double erase
	itr++;
	itr++;
	itr++;
	itr = myList.erase(itr);
	itr = myList.erase(itr);
	std::cout << "After a double erase @ 2nd half..." << std::endl;
	printList(myList);
	
	// Erase at end
	itr = myList.end();
	itr--;
	itr = myList.erase(itr);
	std::cout << "After a erase @ end..." << std::endl;
	printList(myList);
	
	return 0;
}
