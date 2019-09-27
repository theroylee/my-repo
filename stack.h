/***********************************************************************
 * Header:
 *    Assignment 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    Aaron Bateman
 * Summary:
 *   This header file contains all of the code to run the stack. It will
 *   create an array that is dynamically allocated that allows for the
 *   stack to grow and change. It also has a function resize() that will
 *   be able to resize the array (stack) if needed.
 ************************************************************************/

#ifndef stack_h
#define stack_h

#include <cassert>
#include <iomanip>
#include <string>

#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

using namespace std;

template <class T>
class stack
{
public:
    
    //constructors and destructors
    stack() : numCapacity(0), numElements(0), data(NULL) {};
    stack(int numCapacity);
    stack(const stack <T> & rhs);
    ~stack()                        {if (numElements != 0) {delete [] data;}}
    
    //assignment operator
    stack & operator = (const stack & rhs);
    
    //returns sizes of elements
    int size()  const       {return numElements;}
    
    //returns size of capacity
    int capacity() const    {return numCapacity;}
    
    //returns true if empty or false if not
    bool empty() const      {return numElements == 0;}
    
    //clears all of the data from the stack
    void clear()            {numElements = 0;}
    
    //adds an element to the stack
    void push(const T t);
    
    void pop();
    
    T & top(int number);
    const T & top() const;
    
private:
    //this method will allow for the resizing of the stack
    
    void resize(int numCapacity);
    
    int numElements;
    int numCapacity;
    T * data;
    
    
};



/***************************************
 * stack :: assignment
 ***************************************/
template <class T>
stack <T> & stack <T> :: operator = (const stack <T> & rhs)
{
    //clears results of the lefthand side of the operator
    clear();
    
    //Resizes lefthand side if the righthand side has a bigger number of elements
    if (capacity() < rhs.size())
    {
        resize(rhs.size());
    }
    
    for (int i = 0; i < rhs.size()-1; i++)
    {
        data[i] = rhs.data[i];
    }
    
    numElements = rhs.numElements;
    return *this;
}

/***************************************
 * stack :: PUSH
 * Allows for the user to add elements to the top of the stack. This will resize if the
 * capacity equals 0 or there is insufficent memory for the stack.
 ***************************************/
template <class T>
void stack <T> :: push(const T t)
{
    //make sure that capacity is at least equal to the number of elements
    assert(numCapacity >= numElements);
    
    //resize if capacity can no longer fit all of the elements
    if (capacity() == 0)
    {
        resize(1);
    }
    else if (size() == capacity())
    {
        resize(numCapacity * 2);
    }
    
    //add the elements to the stack.
    data[numElements++] = t;
}

/***************************************
 * stack :: POP
 * This removes the top most element of the stack through numElements.
 ***************************************/
template <class T>
void stack <T> :: pop()
{
    if (!empty())
        --numElements;
}

/***************************************
 * stack :: top
 ***************************************/
template <class T>
const T & stack <T> :: top() const
{
    //error handling to make sure that you can't access the top element if the stack is empty
    if (!empty())
    {
        return data[size()-1];
    }
    else
        throw "ERROR: Unable to reference the element from an empty Stack";
    
}
/***************************************
 * stack :: top
 ***************************************/
template <class T>
T & stack <T> :: top(int number)
{
    if (!empty())
    {
        data[size()-1] = number;
    }
    else
        throw "ERROR: Unable to reference the element from an empty Stack";
}
/*******************************************
 * stack :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
stack <T> :: stack(const stack <T> & rhs)
{
    assert(rhs.numCapacity >= 0);
    
    // do nothing if there is nothing to do
    if (rhs.numCapacity == 0)
    {
        numElements = 0;
        numCapacity = 0;
        data = NULL;
        return;
    }
    
    // attempt to allocate
    try
    {
        data = new T[rhs.numCapacity];
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: Unable to allocate a new buffer for Stack";
    }
    
    // copy over the capacity
    numCapacity = rhs.numCapacity;
    
    //copy over the elements
    numElements = rhs.numElements;
    
    // copy the items over one at a time using the assignment operator
    for (int i = 0; i < numCapacity; i++)
        data[i] = rhs.data[i];
}

/**********************************************
 * stack : NON-DEFAULT CONSTRUCTOR
 * Preallocate the stack to "capacity"
 **********************************************/
template <class T>
stack <T> :: stack(int numCapacity)
{
    assert(numCapacity >= 0);
    
    // do nothing if there is nothing to do.
    // since we can't grow an Vector, this is kinda pointless
    if (numCapacity == 0)
    {
        this->numCapacity = 0;
        this->data = NULL;
        return;
    }
    
    // attempt to allocate
    try
    {
        data = new T[numCapacity];
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: Unable to allocate buffer";
    }
    
    // copy over the stuff
    this->numCapacity = numCapacity;
    numElements = 0;
    
}

/**********************************************
 * stack : RESIZE
 * Resizes the stack if capacity < elements
 **********************************************/
template <class T>
void stack <T> :: resize(int numCapacity)
{
    //creates a new array to put all of the information into
    T * newData = new T[numCapacity];
    
    //copies over the data
    for (int i = 0; i < numElements; i++)
    {
        newData[i] = data[i];
    }
    
    //deletes the data
    if (numElements != 0)
    {
        delete [] data;
    }
    
    //puts the new array back into the previous making sure that all of the data is copied over.
    data = newData;
    
    
    this->numCapacity = numCapacity;
}


#endif /* stack_h */


