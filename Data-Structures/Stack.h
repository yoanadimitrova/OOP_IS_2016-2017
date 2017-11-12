#pragma once

#ifndef LINKEDSTACK_H // Checks if LINKEDSTACK_H is defined
#define LINKEDSTACK_H // If not - it defines it

// Main operation needed for stack: push, pop, isEmpty

template<typename T>
class Stack
{
    struct Element
    {
        T data;
        Element* nextElem;
        Element(const T& other)
        {
            data = other;
            nextElem = 0;
        }
    };

public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    void init();
    bool isEmpty() const;
    void pop();
    void push(const T& newElem);
    const T& top() const;
    size_t GetSize() const;
    T& peek();

private:
    Element* topElem; // Pointer to the element on the top of the stack
    int used;

    void destroy();
    void copyFrom(Stack const& other);
};

// Creates an empty stack
template<typename T>
Stack<T>::Stack()
{
    init();
}

// Copy constructor
template<typename T>
Stack<T>::Stack(const Stack& other)
{
    init();
    copyFrom(other);
}

// Operator =
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
    if(this != &other)
    {
        destroy(); // First we free the currently allocated memory
        copyFrom(other); // Then we copy

    }
    return *this;
}

// Destructor
template<typename T>
Stack<T>::~Stack()
{
    destroy();
}

// Assigning initial values for the data-members of the object
// The values are proper for an empty stack
template<typename T>
void Stack<T>::init()
{
    this -> topElem = 0;
    this -> used = 0;
}

// Checks if the stack is empty
template<typename T>
bool Stack<T>::isEmpty() const
{
    return topElem == 0;
}

// Removes and returns the element on top of the stack
template<typename T>
void Stack<T>::pop()
{
    if(!isEmpty())
    {
        T& nextElem;
        nextElem = topElem -> nextElem;
        delete topElem;
        topElem = nextElem;
        used--;

        /*Element *newData = topElem;
        topElem = topElem -> nextElem; // If the stack is empty there will be error
        T data = newData -> data; // We make an extra copy of the item
        delete newData; // Deleting the old data
        return data;*/
    }
    else
        return 0; // If the stack is empty
}

// Adds an element on the top if the stack
template<typename T>
void Stack<T>::push(const T& newElem) // newElement is the value to which the inserted element is initialized
{
    // One line solution:
    // topElem = new Element(newElem, topElem);

    Element* pushElem = new Element(newElem);
    pushElem -> nextElem = topElem;
    topElem = pushElem;
    used++;
}

// Empties the stack and frees the allocated memory
template<typename T>
void Stack<T>::destroy()
{
    Element* junk; // Variable to save the data to be deleted

    while(topElem)
    {
        junk = topElem;
        topElem = topElem -> nextElem;
        delete junk;
    }
    init();
}

// Accesses the next element and returns a reference to the top element (the last element inserted) in the stack
template<typename T>
const T& Stack<T>::top() const
{
    if(isEmpty())
        return 0; // topElem is nullptr
    return topElem -> data;
    // return data[topElem - 1];
}

// Makes the current object a copy of another one
template<typename T>
void Stack<T>::copyFrom(Stack const& other)
{   // The object to copy from can be either empty or non-empty, so we check it if it is empty
    if(other.isEmpty())
        return;

    //Element<T> *orig, *reversed;
    T *orig, *reversed;

    topElem = new Element(other.topElem -> data);

    orig = topElem;
    reversed = other.topElem -> nextElem;

		while (reversed)
		{
			orig -> nextElem = new Element(reversed -> data);
			orig = orig -> nextElem;
			reversed = reversed -> nextElem;
		}

		used = other.used;

		destroy();
}

// Returns the number of elements currently stored in the stack
template<typename T>
size_t Stack<T>::GetSize() const
{
    return used;
}

// Peek next character
// Returns the next character in the input sequence (as a value of type int), without extracting it: The character is left as 
// the next character to be extracted from the stream.
template<typename T>
T& Stack<T>::peek()
{
	if(used == 0)
        return topElem -> data;
    else
        return 1;
}

#endif // LINKEDSTACK_H
