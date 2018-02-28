// ITP 365 Spring 2017
// HW5 Vector and Poker Hands
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// Cards.cpp
// Implements Cards and Poker Hand functionality
#include "Cards.h"
#include <random>
#include <algorithm>

// Function: Constructor
// Purpose: Draws 5 cards from the supplied deck, and sorts them
// by rank
// Input: Takes in a ITPVector of cards for the deck
// Returns: Nothing
PokerHand::PokerHand(ITPVector<Card>& deck)
{
	// Draw 5 cards and store them in the mHand variable
	for (int i = 0; i < 5; i++){
		Card card = deck.get_back();
		deck.remove_back();
		mHand.insert_back(card);
	}
	// Sort the hand
	std::sort(&mHand[0], &mHand[0] + mHand.size());
}

// Function: getBestPokerHand
// Purpose: Returns a string describing the poker hand this PokerHand
// contains
// Input: None
// Returns: The name of the best poker hand
std::string PokerHand::getBestPokerHand() const
{
	if (hasStraight() && hasFlush()){
		return "straight flush";
	}
	else if (hasFourOfAKind()){
		return "four of a kind";
	}
	else if (hasFullHouse()){
		return "full house";
	}
	else if (hasFlush()){
		return "flush";
	}
	else if (hasStraight()){
		return "straight";
	}
	else if (hasThreeOfAKind()){
		return "three of a kind";
	}
	else if (hasTwoPairs()){
		return "two pair";
	}
	else if (hasPair()){
		return "pair";
	}
	return "high card";
}

// Function: hasStraight
// Purpose: Determines if the hand has a straight
// Input: None
// Returns: true if there's a straight
bool PokerHand::hasStraight() const
{
	bool retVal = false;
	
	// Check sorted hand to see if rank of next card is 1 higher than before
	if ((mHand[0].mRank == mHand[1].mRank - 1) &&
		(mHand[1].mRank == mHand[2].mRank - 1) &&
		(mHand[2].mRank == mHand[3].mRank - 1) &&
		(mHand[3].mRank == mHand[4].mRank - 1)){
		retVal = true;
	}
	return retVal;
}

// Function: hasFlush
// Purpose: Determines if the hand has a flush
// Input: None
// Returns: true if there's a flush
bool PokerHand::hasFlush() const
{
	bool retVal = false;
	
	// Check if each suit of each card is the same for flush
	if ((mHand[0].mSuit == mHand[1].mSuit) &&
		(mHand[1].mSuit == mHand[2].mSuit) &&
		(mHand[2].mSuit == mHand[3].mSuit) &&
		(mHand[3].mSuit == mHand[4].mSuit)){
		retVal = true;
	}
	return retVal;
}

// Function: hasFourOfAKind
// Purpose: Determines if the hand has a 4 of a kind
// Input: None
// Returns: true if there's a 4 of a kind
bool PokerHand::hasFourOfAKind() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x x y
	// or
	// x y y y y
	bool retVal = false;
	
	// Check if front 4 cards have same rank
	if ((mHand[0].mRank == mHand[1].mRank) &&
		(mHand[1].mRank == mHand[2].mRank) &&
		(mHand[2].mRank == mHand[3].mRank)){
		retVal = true;
	}
	// Check if back 4 cards have same rank
	else if ((mHand[4].mRank == mHand[3].mRank) &&
			 (mHand[3].mRank == mHand[2].mRank) &&
			 (mHand[2].mRank == mHand[1].mRank)){
		retVal = true;
	}
	return retVal;
}

// Function: hasFullHouse
// Purpose: Determines if the hand has a full house
// Input: None
// Returns: true if there's a full house
bool PokerHand::hasFullHouse() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x y y
	// or
	// x x y y y
	bool retVal = false;
	
	// Check if first 3 cards have same rank and back 2 cards have same rank
	if ((mHand[0].mRank == mHand[1].mRank) &&
		(mHand[1].mRank == mHand[2].mRank) &&
		(mHand[3].mRank == mHand[4].mRank)){
		retVal = true;
	}
	// Check if first 2 cards have same rank and back 3 cards have same rank
	else if ((mHand[0].mRank == mHand[1].mRank) &&
			 (mHand[2].mRank == mHand[3].mRank) &&
			 (mHand[3].mRank == mHand[4].mRank)){
		retVal = true;
	}
	return retVal;
}

// Function: hasThreeOfAKind
// Purpose: Determines if the hand has a three of a kind
// Input: None
// Returns: true if there's a three of a kind
bool PokerHand::hasThreeOfAKind() const
{
	// There are three possibilities:
	// x x x y z
	// x y y y z
	// x y z z z

	bool retVal = false;
	
	// Check first possibility x x x y z
	if ((mHand[0].mRank == mHand[1].mRank) &&
		(mHand[1].mRank == mHand[2].mRank)){
		retVal = true;
	}
	// Check second possibilty x y y y z
	else if ((mHand[1].mRank == mHand[2].mRank) &&
			 (mHand[2].mRank == mHand[3].mRank)){
		retVal = true;
	}
	// Check third possibility x y z z z
	else if ((mHand[2].mRank == mHand[3].mRank) &&
			 (mHand[3].mRank == mHand[4].mRank)){
		retVal = true;
	}
	return retVal;
}

// Function: hasTwoPairs
// Purpose: Determines if the hand has two pairs
// Input: None
// Returns: true if there's two pairs
bool PokerHand::hasTwoPairs() const
{
	// There are three possibilities:
	// x x y y z
	// x y y z z
	// x x y z z
	
	bool retVal = false;
	
	// Check first possibility x x y y z
	if ((mHand[0].mRank == mHand[1].mRank) &&
		(mHand[2].mRank == mHand[3].mRank)){
		retVal = true;
	}
	// Check second possibility x y y z z
	else if ((mHand[1].mRank == mHand[2].mRank) &&
			 (mHand[3].mRank == mHand[4].mRank)){
		retVal = true;
	}
	// Check third possibility x x y z z
	else if ((mHand[0].mRank == mHand[1].mRank) &&
			 (mHand[3].mRank == mHand[4].mRank)){
		retVal = true;
	}
	return retVal;
}

// Function: hasPair
// Purpose: Determines if there's a pair
// Input: None
// Returns: true if there's a pair
bool PokerHand::hasPair() const
{
	// There's a pair if any neighbors are equal to each other
	bool retVal = false;
	
	// Check each neighbor to see if they are equal
	if ((mHand[0].mRank == mHand[1].mRank) ||
		(mHand[1].mRank == mHand[2].mRank) ||
		(mHand[2].mRank == mHand[3].mRank) ||
		(mHand[2].mRank == mHand[3].mRank)){
		retVal = true;
	}
	return retVal;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Do not edit code below this line!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// Function: createDeck
// Purpose: Given an empty ITPVector of Cards, inserts a
// standard 52 card deck and shuffles it
// Input: An ITPVector of Cards (by reference)
// Returns: nothing
void createDeck(ITPVector<Card>& deck)
{
	for (int i = 0; i < 4; i++)
	{
		Suit suit = Suit(i);
		for (int value = 2; value <= 14; value++)
		{
			deck.insert_back(Card(value, suit));
		}
	}

	// Shuffle the deck
	std::shuffle(&deck[0], &deck[0] + deck.size(), std::random_device());
}

// Function: << operator for Card
// Purpose: Outputs the name and suit of the card
// Input: ostream and card
// Returns: ostream, with card data output to it
std::ostream& operator<<(std::ostream& os, const Card& card)
{
	// Output value
	if (card.mRank < 11) // Number card
	{
		os << card.mRank;
	}
	else // Face card
	{
		switch (card.mRank)
		{
		case 11:
			os << "Jack";
			break;
		case 12:
			os << "Queen";
			break;
		case 13:
			os << "King";
			break;
		case 14:
			os << "Ace";
			break;
		default:
			os << "Invalid";
			break;
		}
	}

	// Output suit
	os << " of ";
	switch (card.mSuit)
	{
	case CLUBS:
		os << "Clubs";
		break;
	case DIAMONDS:
		os << "Diamonds";
		break;
	case HEARTS:
		os << "Hearts";
		break;
	case SPADES:
		os << "Spades";
		break;
	default:
		os << "Invalid";
		break;
	}

	return os;
}


// Function: < comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left < right
bool operator<(const Card& left, const Card& right)
{
	// If their values are the same, compare the suits
	if (left.mRank == right.mRank)
	{
		return left.mSuit < right.mSuit;
	}
	else
	{
		return left.mRank < right.mRank;
	}
}

// Function: << operator
// Purpose: Prints out the hand
std::ostream& operator<<(std::ostream& os, const PokerHand& hand)
{
	os << hand.mHand;
	return os;
}
