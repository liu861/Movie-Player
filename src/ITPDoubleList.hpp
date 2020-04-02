#pragma once
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <iostream>

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
            //set current to null
            mCurr = nullptr;
        }
        
        Iterator(Node* inCurr)
        {
            //set current to input
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
            Iterator plus(*this);
            mCurr = mCurr->mNext;
			return plus;
		}
        
        // --i
        Iterator& operator--()
        {
			// TODO: Implement
            mCurr = mCurr->mPrev;
            return *this;
		}
        
        // i--
        Iterator operator--(int)
        {
			// TODO: Implement
            Iterator minus(*this);
            mCurr = mCurr->mPrev;
			return minus;
		}
        
        // Dereference
        T& operator*() const
        {
			//return data at iterator
			return mCurr->mData;
		}
        
        Node* operator->() const
        {
            return mCurr;
        }
        
        // Comparison
        bool operator==(const Iterator& rhs) const
        {
            //if iterator equals rhs
            return mCurr == rhs.mCurr;
        }
        
        bool operator!=(const Iterator& rhs) const
        {
            //if iterator does not equal rhs
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
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;
        Node* temp = other.mHead;
        //while temp is not null
        while(temp != nullptr)
        {
            //push back temps data into the list
            push_back(temp->mData);
            //advance temp to next node
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
        while(mSize > 0)
        {
            pop_front();
        }
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;
	}
    
    // Assignment Operator
    // Function: Assignment Operator
    // Purpose: Clear this list, and then make a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: *this
    ITPDoubleList& operator=(const ITPDoubleList& other)
    {
		// TODO: Implement
        //call clear function
        clear();
        //create temp node to point to head of other
        Node* temp = new Node;
        temp = other.mHead;
        //while temp is not null
        while(temp != nullptr)
        {
            //push back temp's data into this list
            push_back(temp->mData);
            //advance temp to the next node
            temp = temp->mNext;
        }
        delete temp;
        //operator= returns *this
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
        //dynamically allocate new node
        Node* temp = new Node;
        //set data to value
        temp->mData = value;
        //set node prev to null (because this will be new head)
        temp->mPrev = nullptr;
        //set node next to current head
        temp->mNext = mHead;
        if(mSize == 0)
        {
            //set tail to new node also
            mTail = temp;
        }
        else
        {
            //set current head prev to new node
            mHead->mPrev = temp;
        }
        //set new head to new node
        mHead = temp;
        //increment size
        mSize++;
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& front()
    {
        if(mSize == 0)
        {
            throw std::out_of_range("The size of the list is 0!");
        }
		return mHead->mData;
    }
    
    // Function: pop_front
    // Purpose: Removes the node at the front of the list
    // Input: None
    // Returns: None
    void pop_front()
    {
        if(mSize == 0)
        {
            throw std::out_of_range("Ths size of the list is 0!");
        }
        else if(mSize == 1)
        {
            //delete head node
            delete mHead;
            //set head and tail to null, size to 0
            mHead = nullptr;
            mTail = nullptr;
            mSize = 0;
        }
        else
        {
            //create temp node, set to node after head
            Node* temp = mHead->mNext;
            //delete current head
            delete mHead;
            //new temp node is now head
            mHead = temp;
            //head previous is null
            mHead->mPrev = nullptr;
            //decrement size
            mSize--;
        }
    }
    
    // Function: push_back
    // Purpose: Inserts a node at the end of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_back(const T& value)
    {
        //dynamically allocate new temp node
        Node* temp = new Node;
        //set its data to value
        temp->mData = value;
        //set prev to current tail
        temp->mPrev = mTail;
        //set next to null (since this will be the new tail)
        temp->mNext = nullptr;
        if(mSize == 0)
        {
            //head is also new node
            mHead = temp;
        }
        else
        {
            //set next of current tail to new node
            mTail->mNext = temp;
        }
        //set tail to new node
        mTail = temp;
        //increment size
        mSize++;
        
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& back()
    {
		if(mSize == 0)
        {
            throw std::out_of_range("The size of the list is 0!");
        }
        return mTail->mData;
    }
    
    // Function: pop_back
    // Purpose: Removes the node at the end of the list
    // Input: None
    // Returns: None
    void pop_back()
    {
        if(mSize == 0)
        {
            throw std::out_of_range("Ths size of the list is 0!");
        }
        else if(mSize == 1)
        {
            //delete tail node
            delete mTail;
            //set head and tail to null, size to 0
            mHead = nullptr;
            mTail = nullptr;
            mSize = 0;
        }
        else
        {
            //create temp node, set to node before tail
            Node* temp = mTail->mPrev;
            //delete current tail
            delete mTail;
            //new temp node is now tail
            mTail = temp;
            //new tail next is null
            mTail->mNext = nullptr;
            //decrement size
            mSize--;
        }
	}
    
    // Function: begin
    // Purpose: Gets an iterator for the start of the list
    // Input: None
    // Returns: Iterator pointing to beginning of list
    Iterator begin() const
    {
		return Iterator(mHead); // FIX RETURN VALUE
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
		//if iterator is invalid -> error
        if(i == nullptr)
        {
            throw std::out_of_range("Iterator is invalid!");
        }
        //if iterator is at begin
        else if(i == begin())
        {
            pop_front();
            return begin();
        }
        //if iterator is at end
        else if(i == end())
        {
            pop_back();
            return end();
        }
        else
        {
            //make before, after, and toDel pointers
            Node* before = i.mCurr->mNext;
            Node* after = i.mCurr->mPrev;
            Node* toDel = i.mCurr;
            //delete toDel
            delete toDel;
            //set before's next to after
            before->mNext = after;
            //set after's previous to before
            after->mPrev = before;
            //decrement size
            mSize--;
            //return iterator to after
            return Iterator(after);
        }
    }

	// Function: insert
	// Purpose: Inserts a list item before node pointed to by i
	// Input: Iterator pointing to a valid node to insert before
	// Returns: A new iterator pointing to the inserted value
    Iterator insert(Iterator& i, const T& val)
    {
        //if iterator is invalid
        if(i == nullptr)
        {
            throw std::out_of_range("Iterator is invalid!");
        }
        //if iterator is at begin
        if(i == begin())
        {
            push_front(val);
            return begin();
        }
        //if iterator is at end
        else if(i == end())
        {
            push_back(val);
            //return iterator to last element (not end)
            return Iterator(mTail);
        }
        else
        {
            //create before and after pointers
            Node* before = i.mCurr;
            Node* after = i.mCurr->mPrev;
            //dynamically allocate new node
            Node* temp = new Node;
            //set its data to next value
            temp->mData = val;
            //set its previous to before
            temp->mPrev = before;
            //set its next to after
            temp->mNext = after;
            //set before's next to the new node
            before->mNext = temp;
            //set after's prev to the new node
            after->mPrev = temp;
            //increment size
            mSize++;
            //return iterator pointing to the inserted node
            return Iterator(temp);
        }
	}
    
public:
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the list to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, list to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPDoubleList<T>& list)
    {
        os << "{";
        //create temp node set to head of list
        Node* temp = list.mHead;
        while(temp != nullptr)
        {
            os << temp->mData;
            if(temp != list.mTail)
            {
                os << ",";
            }
            //set temp to next node
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
        std::stringstream stream;
        //write to stream this list
        stream << *this;
        return stream.str();
    }
    
    // Function: toReverseString
    // Purpose: Outputs the list in reverse
    // Input: None
    // Output: String in reverse
    std::string toReverseString() const
    {
        std::stringstream stream;
        stream << "{";
        //create temp node set to tail of list
        Node* temp = mTail;
        while(temp != nullptr)
        {
            stream << temp->mData;
            if(temp != mHead)
            {
                stream << ",";
            }
            //set temp to previous node
            temp = temp->mPrev;
        }
        stream << "}";
        return stream.str();
    }
};
