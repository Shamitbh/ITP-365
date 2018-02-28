// ITP 365 Spring 2017
// HW5 Vector and Poker Hands
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac

#include "ITPVector.hpp"
#include "Cards.h"
#include <iostream>

void optionOne()
{
	while (1)
	{
		// Test ITPVector
		ITPVector<int> testVector;
		std::cout << "***Constructing ITPVector..." << std::endl;
		
		int num;
		std::cout << "Contents: " << testVector << std::endl;
		std::cout << "Capacity: " << testVector.capacity() << ", Size: " << testVector.size() << std::endl;
		std::cout << "Enter # of elements to add: ";
		std::cin >> num;
		// insert back elements
		for (int i = 0; i < num; i++){
			testVector.insert_back(i*5);
		}
		std::cout << "Contents: " << testVector << std::endl;
		std::cout << "Capacity: " << testVector.capacity() << ", Size: " << testVector.size() << std::endl;
		std::cout << "The back element is: " << testVector.get_back() << std::endl;
		testVector.remove_back();
		std::cout << "Called remove_back" << std::endl;
		
		std::cout << "Contents: " << testVector << std::endl;
		std::cout << "Capacity: " << testVector.capacity() << ", Size: " << testVector.size() << std::endl;
		
		std::cout << "***Test Complete!" << std::endl;
	}
}
void optionTwo()
{
	std::string userInput = "y";
	while (userInput == "y")
	{
		// Make ITPVector to hold deck of cards
		ITPVector<Card> deckOfCards;
		// Create deck
		createDeck(deckOfCards);
		// Create pokerhand
		PokerHand hand(deckOfCards);
		
		std::cout << "You drew: " << hand << std::endl;
		std::cout << "You have a " << hand.getBestPokerHand() << std::endl;
		
		std::cout << "Try again (y/n) ";
		std::cin >> userInput;
	}
}

int main(int argc, char** argv)
{
	// Text-based menu
	std::string userChoice = "1";
	while (userChoice == "1" || userChoice == "2"){
		std::cout << "Select an option...(or press any other key to quit)" << std::endl;
		std::cout << "1. Test ITPVector" << std::endl;
		std::cout << "2. Poker Hands" << std::endl;
		std::cout << "> ";
		std::cin >> userChoice;
		
		if (userChoice == "1"){
			// ITPVector
			optionOne();
		}
		else if (userChoice == "2"){
			// Poker Hands
			optionTwo();
		}
	}
	return 0;
}
