// ITP 365 Spring 2017
// HW5 Vector and Poker Hands
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// ITPVector.hpp
// Defines and implements the ITPVector collection
//
#pragma once
#include <sstream>
#include <ostream>
#include "error.h"

template <typename T>
class ITPVector
{
	const unsigned INITIAL_CAPACITY = 10;
	const unsigned CAPACITY_MULTIPLIER = 2;
public:
	// Function: Constructor
	// Purpose: Initializes the ITP vector to have a
	// capacity of INITIAL_SIZE and a size of 0.
	// It also dynamically allocates the underlining array data
	// Input: None
	// Returns: Nothing
	ITPVector()
	{
		mCapacity = INITIAL_CAPACITY;
		mSize = 0;
		mData = new T[mCapacity];
	}

	// Function: Destructor
	// Purpose: Deletes the underlying array and
	// sets size/capacity to zero
	// Input: None
	// Returns: Nothing
	~ITPVector()
	{
		delete[] mData;
		mCapacity = 0;
		mSize = 0;
	}

	// Function: capacity
	// Purpose: Returns the current capacity of the underlying array data
	// Input: None
	// Returns: Capacity of underlying array data
	unsigned capacity() const
	{
		return mCapacity;
	}

	// Function: size
	// Purpose: Returns the current size of the vector
	// Input: None
	// Returns: Size of vector
	unsigned size() const
	{
		return mSize;
	}

	// Function: Subscript operator (read/write version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	T& operator[](unsigned index)
	{
		if (index < 0 || index >= mSize)
		{
			error("Out of bounds!");
		}
		return mData[index];
	}
	
	// Function: Subscript operator (read-only version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	const T& operator[](unsigned index) const
	{
		if (index < 0 || index >= mSize)
		{
			error("Out of bounds!");
		}
		return mData[index];
	}

	// Function: insert_back
	// Purpose: Adds the specified element to the end of the ITPVector
	// It automatically reallocates the underlying array if we are
	// going over capacity
	// Input: Value to add (by const reference)
	// Returns: Nothing
	void insert_back(const T& value)
	{
		// If size < capacity
		if (mSize < mCapacity){
			// 1. Place the element at index size (0)
			mData[mSize] = value;
			// 2. Increment size
			mSize++;
		}
		// If we go over capacity
		else{
		// 1. Increase the capacity (usually double it)
			mCapacity *= CAPACITY_MULTIPLIER;
		// 2. Dynamically allocate a new underlying array w/ new capacity
			T* tempAr = new T[mCapacity];
		// 3. Copy the data from the old array to the new array
			for (int i = 0; i < mSize; i++){
				tempAr[i] = mData[i];
			}
		// 4. Delete the old array
			delete[] mData;
		// 5. Set your pointer to the new array
			mData = tempAr;
		// 6. Add an element at index size
			mData[mSize] = value;
		// 7. Increment size by 1
			mSize++;
		}
	}

	// Function: get_back
	// Purpose: Returns the current last element in the vector
	// Does not remove this element from the vector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Value at back of vector, by reference
	T& get_back()
	{
		// 1. If size == 0 – error!
		if (mSize == 0){
			error("Nothing in vector! Size is 0");
		}
		// 2. Return the element at size - 1
		return mData[mSize - 1];
	}

	// Function: remove_back
	// Purpose: Removes the last element from the ITPVector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Nothing
	void remove_back()
	{
		// 1. If size == 0 – error!
		if (mSize == 0){
			error("Nothing in vector! Size is 0");
		}
		// 2. Decrement size by 1
		mSize--;
	}

	// Function: Output Stream Operator
	// Purpose: Prints the contents of the vector to the provided stream
	// Written in the format of {x, y, ..., z}
	// Input: Stream to write to, vector to write
	// Output: Stream after values are written
	friend std::ostream& operator<<(std::ostream& os, const ITPVector<T>& vector)
	{
		os << "{";
		for (int i = 0; i < vector.size(); i++){
			os << vector[i];
			if (i != vector.size() - 1){
				os << ",";
			}
		}
		os << "}";
		return os;
	}
private:
	// Define member variables here
	unsigned int mCapacity;
	unsigned int mSize;
	T* mData;
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// NOTE: Do not edit code below this line!!!
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// Disallow assignment and copy construction
	ITPVector<T>& operator=(const ITPVector<T>& other)
	{

	}

	ITPVector(const ITPVector<T>& other)
	{

	}
};
