// ITP 365 Spring 2017
// HW6 Doubly Linked List and Movie Player
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// ITPDoubleList.hpp
// Defines and implements the ITPDoubleList collection
//

#pragma once
#include "error.h"
#include <ostream>
#include <sstream>
#include "leaker.h"

template <typename T>
class ITPDoubleList
{
private:
    
    // Node only used internally to list
    struct Node
    {
        // Data in this node
        T mData;
        // Link to previous node
        Node* mPrev;
        // Link to next node
        Node* mNext;
    };
    
    // Pointer to the head node
    Node* mHead;
    // Pointer to the tail node
    Node* mTail;
    // Number of nodes currently in the list
    unsigned mSize;
    
public:
    // Iterator helper class...
    class Iterator
    {
    private:
        Node* mCurr;
    public:
        // Needed for List access
        friend class ITPDoubleList;
        // Constructors
        Iterator()
        {
			mCurr = nullptr;
        }
        
        Iterator(Node* inCurr)
        {
			mCurr = inCurr;
        }
        
        Iterator(const Iterator& src)
        {
			mCurr = src.mCurr;
        }
        
        // Assignment
        Iterator& operator=(const Iterator& src)
        {
			mCurr = src.mCurr;
            return *this;
        }
        
        // Incrementors / Decrementors
        // ++i
        Iterator& operator++()
        {
            mCurr = mCurr->mNext;
			return *this;
        }
        
        // i++
        Iterator operator++(int)
        {
			Iterator retval(*this);
			mCurr = mCurr->mNext;
            return retval;
        }
        
        // --i
        Iterator& operator--()
        {
			mCurr = mCurr->mPrev;
            return *this;
        }
        
        // i--
        Iterator operator--(int)
        {
			Iterator retval(*this);
			mCurr = mCurr->mPrev;
			return retval;
        }
        
        // Dereference
        T& operator*() const
        {
            return mCurr->mData;
        }
        
        Node* operator->() const
        {
            return mCurr;
        }
        
        // Comparison
        bool operator==(const Iterator& rhs) const
        {
			return mCurr == rhs.mCurr;
        }
        
        bool operator!=(const Iterator& rhs) const
        {
			return mCurr != rhs.mCurr;
        }
    };
    
    // List functions...
    
    // Function: Default Constructor
    // Purpose: Initializes size to 0 and head/tail to null
    // Input: None
    // Returns: Nothing
    ITPDoubleList()
    {
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;
    }
    
    // Function: Copy Constructor
    // Purpose: Initializes this list as a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: Nothing
    ITPDoubleList(const ITPDoubleList& other)
    {
		// 1. Set size to 0, head to null, tail to null
		mSize = 0;
		mHead = nullptr;
		mTail = nullptr;
		// 2. Create a temp that points to the head node in “other”
		Node* temp = other.mHead;
		// 3. While temp is not null…
		while (temp != nullptr){
			// 1. Insert_back temp’s data into this list
			push_back(temp->mData);
			// 2. Advance temp to the next node
			temp = temp->mNext;
		}
    }
    
    // Function: Destructor
    // Purpose: Calls the clear function to delete the list
    // Input: None
    // Returns: Nothing
    ~ITPDoubleList()
    {
		clear();
    }
    
    // Function: clear
    // Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
    // Input: None
    // Returns: Nothing
    void clear()
    {
		// 1. While size > 0…
		while (mSize > 0){
			// a) Call remove_front
			pop_front();
		}
    }
    
    // Assignment Operator
    // Function: Assignment Operator
    // Purpose: Clear this list, and then make a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: *this
    ITPDoubleList& operator=(const ITPDoubleList& other)
    {
		// 1. Call clear (to clear out any values already in this list)
		clear();
		// 2. Create a temp that points to the head node in “other”
		Node* temp = other.mHead;
		// 3. While temp is not null…
		while (temp != nullptr){
			// 1. Insert_back temp’s data into this list
			push_back(temp->mData);
			// 2. Advance temp to the next node
			temp = temp->mNext;
		}
		// 4. By convention, operator= returns *this
        return *this;
    }
    
    // Function: size
    // Purpose: Gets the current size of the linked list
    // Input: None
    // Returns: size of the list
    unsigned size() const
    {
        return mSize;
    }
    
    // Function: push_front
    // Purpose: Inserts a node at the front of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_front(const T& value)
    {
		// 1. Dynamically allocate a new node
		Node* tempNode = new Node;
		// a) Set its data to the value
		tempNode->mData = value;
		// b) Set its previous to null (since this will be the new head)
		tempNode->mPrev = nullptr;
		// c) Set its next to the current head
		tempNode->mNext = mHead;
		// 2. If the size is 0…The tail is the new node
		if (mSize == 0){
			mTail = tempNode;
		}
		else{
			// 3. Otherwise…set the previous of the current head to the new node
			mHead->mPrev = tempNode;
		}
		// 4. Set the head to the new node
		mHead = tempNode;
		// 5. Increment the size
		mSize++;
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& front()
    {
		// 1. If the size is 0, error!
		if (mSize == 0){
			error("Size is 0!");
		}
		// 2. Return the data at the head node
        return mHead->mData;
    }
    
    // Function: pop_front
    // Purpose: Removes the node at the front of the list
    // Input: None
    // Returns: None
    void pop_front()
    {
		// 1. If the size is 0…error!
		if (mSize == 0){
			error("Size is 0!");
		}
		// 2. Otherwise if the size is 1…
		else if (mSize == 1){
			// 1. Delete the head node
			delete mHead;
			// 2. Set head and tail to null, size to 0
			mHead = nullptr;
			mTail = nullptr;
			mSize = 0;
		}
		// 3. Otherwise…
		else{
			// 1. Set a temp equal to the next node after head
			Node* temp = mHead->mNext;
			// 2. Delete the head node
			delete mHead;
			// 3. The new head is temp
			mHead = temp;
			// 4. The new head previous is now null
			mHead->mPrev = nullptr;
			// 5. Decrement size
			mSize--;
		}
    }
    
    // Function: push_back
    // Purpose: Inserts a node at the end of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_back(const T& value)
    {
		// 1. Dynamically allocate a new node
		Node* tempNode = new Node;
		// a) Set its data to the value
		tempNode->mData = value;
		// b) Set its previous to the current tail
		tempNode->mPrev = mTail;
		// c) Set the next to null (since this will be the new tail)
		tempNode->mNext = nullptr;
		// 2. If the size is 0…The head is the new node
		if (mSize == 0){
			mHead = tempNode;
		}
		// 3. Otherwise…set the next of the current tail to the new node
		else{
			mTail->mNext = tempNode;
		}
		// 4. Set the tail to the new node
		mTail = tempNode;
		// 5. Increment the size
		mSize++;
    }
    
    // Function: back
    // Purpose: Gets the value of the node at the back of the list
    // Input: None
    // Returns: Value of the node at the back of the list
    T& back()
    {
		// 1. If the size is 0, error!
		if (mSize == 0){
			error("Size is 0!");
		}
		// 2. Return the data at the tail node
        return mTail->mData;
    }
    
    // Function: pop_back
    // Purpose: Removes the node at the end of the list
    // Input: None
    // Returns: None
    void pop_back()
    {
		// 1. If the size is 0…error!
		if (mSize == 0){
			error("Size is 0!");
		}
		// 2. Otherwise if the size is 1…
		else if (mSize == 1){
			// 1. Delete the tail node
			delete mTail;
			// 2. Set head and tail to null, size to 0
			mHead = nullptr;
			mTail = nullptr;
			mSize = 0;
		}
		// 3. Otherwise…
		else{
			// 1. Set a temp equal to the previous node before the tail
			Node* temp = mTail->mPrev;
			// 2. Delete the tail node
			delete mTail;
			// 3. The new tail is temp
			mTail = temp;
			// 4. The new tail next is now null
			mTail->mNext = nullptr;
			// 5. Decrement size
			mSize--;
		}
    }

    // Function: begin
    // Purpose: Gets an iterator for the start of the list
    // Input: None
    // Returns: Iterator pointing to beginning of list
    Iterator begin() const
    {
		return Iterator(mHead);
    }
    
    // Function: end
    // Purpose: Gets an iterator for the end of the list
    // Input: None
    // Returns: Iterator pointing to end of list
    Iterator end() const
    {
		return Iterator(mTail->mNext);
    }

	// Function: erase
	// Purpose: Removes the item at the node pointed to by i
	// Input: Iterator pointing to a valid node to remove before
	// Returns: A new iterator pointing to the node after the removed item
    Iterator erase(Iterator& i)
    {
		// 1. If the iterator is invalid … error! -> No need to worry since input = valid
		// 2. If the iterator is at begin
		if (i == begin()){
			// 1. pop_front
			pop_front();
			// 2. Return begin
			return begin();
		}
		// 3. If the iterator is at the tail
		else if (i == mTail){
			// 1. pop_back
			pop_back();
			// 2. Return end
			return end();
		}
		// 4. Otherwise…
		else{
			// 1. Make “before”, “after”, and “toDel” pointers
			Node* ptrAfter = i.mCurr->mNext;
			Node* ptrBefore = i.mCurr->mPrev;
			Node* ptrToDel = i.mCurr;
			// 2. Delete “toDel”
			delete ptrToDel;
			// 3. Set before’s next to after
			ptrBefore->mNext = ptrAfter;
			// 4. Set after’s previous to before
			ptrAfter->mPrev = ptrBefore;
			// 5. Decrement size
			mSize--;
			// 6. Return an iterator to after
			return Iterator(ptrAfter);
		}
    }

	// Function: insert
	// Purpose: Inserts a list item before node pointed to by i
	// Input: Iterator pointing to a valid node to insert before
	// Returns: A new iterator pointing to the inserted value
    Iterator insert(Iterator& i, const T& val)
    {
		// 1. If the iterator is invalid … error! -> No need to worry since input = valid
		// 2. If the iterator is at begin
		if (i == begin()){
			// 1. push_front
			push_front(val);
			// 2. Return begin
			return begin();
		}
		// 3. If the iterator is at end
		else if (i == end()){
			// 1. push_back
			push_back(val);
			// 2. Return iterator to last element (not end!)
			return Iterator(mTail);
		}
		// 4. Otherwise…
		else{
			// 1. Make “before” and “after” pointers
			Node* ptrAfter = i.mCurr;
			Node* ptrBefore = i.mCurr->mPrev;
			// 2. Dynamically allocate a new node
			Node* tempNode = new Node;
			// a) Set its data to the value
			tempNode->mData = val;
			// b) Set its previous to before
			tempNode->mPrev = ptrBefore;
			// c) Set its next to after
			tempNode->mNext = ptrAfter;
			// 3. Set before’s next to the new node
			ptrBefore->mNext = tempNode;
			// 4. Set after’s previous to the new node
			ptrAfter->mPrev = tempNode;
			// 5. Increment size
			mSize++;
			// 6. Create an iterator pointing to the inserted node
			return Iterator(tempNode);
		}
    }
    
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!! DO NOT EDIT BELOW THIS LINE !!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
public:
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the list to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, list to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPDoubleList<T>& list)
    {
        os << "{";
        
        Node* temp = list.mHead;
        while (temp != nullptr)
        {
            os << temp->mData;
            if (temp != list.mTail)
            {
                os << ",";
            }
            
            temp = temp->mNext;
        }
        
        os << "}";
        return os;
    }
    
    // Function: toString
    // Purpose: Converts list to a string
    // Input: None
    // Output: String (in the format as the ostream)
    std::string toString() const
    {
        std::stringstream str;
        str << *this;
        return str.str();
    }
    
    // Function: toReverseString
    // Purpose: Outputs the list in reverse
    // Input: None
    // Output: String in reverse
    std::string toReverseString() const
    {
        std::stringstream str;
        
        str << "{";
        
        Node* temp = mTail;
        while (temp != nullptr)
        {
            str << temp->mData;
            if (temp != mHead)
            {
                str << ",";
            }
            
            temp = temp->mPrev;
        }
        
        str << "}";
        
        return str.str();
    }
};
