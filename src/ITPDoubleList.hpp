#pragma once
#include <ostream>
#include <sstream>
#include <stdexcept>

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
            // TODO: Implement
        }
        
        Iterator(Node* inCurr)
        {
            // TODO: Implement
		}
        
        Iterator(const Iterator& src)
        {
            // TODO: Implement
        }
        
        // Assignment
        Iterator& operator=(const Iterator& src)
        {
			// TODO: Implement
			return *(new Iterator()); // FIX RETURN VALUE
		}
        
        // Incrementors / Decrementors
        // ++i
        Iterator& operator++()
        {
			// TODO: Implement
			return *(new Iterator()); // FIX RETURN VALUE
		}
        
        // i++
        Iterator operator++(int)
        {
			// TODO: Implement
			return *(new Iterator()); // FIX RETURN VALUE
		}
        
        // --i
        Iterator& operator--()
        {
			// TODO: Implement
			return *(new Iterator()); // FIX RETURN VALUE
		}
        
        // i--
        Iterator operator--(int)
        {
			// TODO: Implement
			return *(new Iterator()); // FIX RETURN VALUE
		}
        
        // Dereference
        T& operator*() const
        {
			// TODO: Implement
			return *(new T()); // FIX RETURN VALUE
		}
        
        Node* operator->() const
        {
			// TODO: Implement
			return new Node(); // FIX RETURN VALUE
        }
        
        // Comparison
        bool operator==(const Iterator& rhs) const
        {
			// TODO: Implement
			return false; // FIX RETURN VALUE
        }
        
        bool operator!=(const Iterator& rhs) const
        {
			// TODO: Implement
			return false; // FIX RETURN VALUE
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
        // TODO: Implement
	}
    
    // Function: Destructor
    // Purpose: Calls the clear function to delete the list
    // Input: None
    // Returns: Nothing
    ~ITPDoubleList()
    {
        // TODO: Implement
	}
    
    // Function: clear
    // Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
    // Input: None
    // Returns: Nothing
    void clear()
    {
        // TODO: Implement
	}
    
    // Assignment Operator
    // Function: Assignment Operator
    // Purpose: Clear this list, and then make a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: *this
    ITPDoubleList& operator=(const ITPDoubleList& other)
    {
		// TODO: Implement
		return *(new ITPDoubleList()); // FIX RETURN VALUE
    }
    
    // Function: size
    // Purpose: Gets the current size of the linked list
    // Input: None
    // Returns: size of the list
    unsigned size() const
    {
		// TODO: Implement
		return -1; // FIX RETURN VALUE
    }
    
    // Function: push_front
    // Purpose: Inserts a node at the front of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_front(const T& value)
    {
        // TODO: Implement
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& front()
    {
		// TODO: Implement
		return *(new T()); // FIX RETURN VALUE
    }
    
    // Function: pop_front
    // Purpose: Removes the node at the front of the list
    // Input: None
    // Returns: None
    void pop_front()
    {
        // TODO: Implement
    }
    
    // Function: push_back
    // Purpose: Inserts a node at the end of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_back(const T& value)
    {
        // TODO: Implement
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& back()
    {
		// TODO: Implement
		return *(new T()); // FIX RETURN VALUE
    }
    
    // Function: pop_back
    // Purpose: Removes the node at the end of the list
    // Input: None
    // Returns: None
    void pop_back()
    {
        // TODO: Implement
	}
    
    // Function: begin
    // Purpose: Gets an iterator for the start of the list
    // Input: None
    // Returns: Iterator pointing to beginning of list
    Iterator begin() const
    {
		// TODO: Implement
		return *(new Iterator); // FIX RETURN VALUE
    }
    
    // Function: end
    // Purpose: Gets an iterator for the end of the list
    // Input: None
    // Returns: Iterator pointing to end of list
    Iterator end() const
    {
		// TODO: Implement
		return *(new Iterator); // FIX RETURN VALUE
    }

	// Function: erase
	// Purpose: Removes the item at the node pointed to by i
	// Input: Iterator pointing to a valid node to remove before
	// Returns: A new iterator pointing to the node after the removed item
    Iterator erase(Iterator& i)
    {
		// TODO: Implement
		return *(new Iterator); // FIX RETURN VALUE
    }

	// Function: insert
	// Purpose: Inserts a list item before node pointed to by i
	// Input: Iterator pointing to a valid node to insert before
	// Returns: A new iterator pointing to the inserted value
    Iterator insert(Iterator& i, const T& val)
    {
		// TODO: Implement
		return *(new Iterator); // FIX RETURN VALUE
	}
    
public:
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the list to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, list to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPDoubleList<T>& list)
    {
        // TODO: Implement
        return os; // FIX RETURN VALUE
    }
    
    // Function: toString
    // Purpose: Converts list to a string
    // Input: None
    // Output: String (in the format as the ostream)
    std::string toString() const
    {
		// TODO: Implement
		return ""; // FIX RETURN VALUE
    }
    
    // Function: toReverseString
    // Purpose: Outputs the list in reverse
    // Input: None
    // Output: String in reverse
    std::string toReverseString() const
    {
		// TODO: Implement
		return ""; // FIX RETURN VALUE
    }
};
