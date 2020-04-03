#include "GenStack.h"


//dafault constructor
GenStack:: GenStack()
{
  //init array to heap b/c we allocate this memory dynamically
  myArray = new char[128];
  mSize = 128;
  top = -1;

}

//overload constructor
GenStack:: GenStack(int maxSize)
{
  //init array to heap b/c we allocate this memory dynamically
  myArray = new char[maxSize];
  mSize = maxSize;
  top = -1;

}

GenStack::~GenStack()
{
  delete[] myArray;
}

void GenStack::push(char data)
{
  //check if full before inserting

  //increment the index where we're at, or the "top" and settng it equal to the data
  myArray[++top] = data;
}

char GenStack::pop()
{
  if(top == -1)
  {
    throw string("GenStack is empty");
  }
  //check if emmpty before proceeding

  //return myArray value of the current top, then decrement it after returning to set a new top
  return myArray[top--];
}

char GenStack::peek()
{
  if(top == -1){
    throw string("GenStack is empty");
  }
  return storage[top];
  //check if emmpty before proceeding

  //just returns it but doesn't change the top value or "remove it"
  return myArray[top];
}

bool GenStack::isFull()
{
  return (top==mSize-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}
