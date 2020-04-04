#include "GenStack.h"
#include <iostream>
#include <cstring>
#include <locale>
#include <fstream>
#include <string>
#include <streambuf>
#include <math.h>

#include<bits/stdc++.h>


//default constructor
GenStack:: GenStack()
{
  //initialize array to the heap because we allocated this memory dynamically
  myArray = new char[128];
  mSize = 128;
  top = -1;

}

//overload constructor
GenStack:: GenStack(int maxSize)
{
  //initialize array to the heap because we allocated this memory dynamically
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
    throw string("Stack is empty");
  }
  //return myArray value of the current top, then decrement it after returning to set a new top
  return myArray[top--];
}

char GenStack::peek()
{
  if(top == -1){
    throw string("Stack is empty");
  }
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

void GenStack::resize(){
  if ((top==mSize-1)== true){
  char* temp = new char[mSize + 10]; //creating a new array with a bigger size
    for (int i = 0; i < mSize; ++i){
      temp[i] = myArray[i];
    }
      delete [] myArray; //gets rid of the former array
      myArray = temp; //new sized array
  }
}

bool GenStack::check(string inputFile){
  ifstream filename(inputFile);
  GenStack s(100);
  string line = "";
  if(filename.is_open()) //opening the file inputted from commandline

    while(!filename.eof()){
      getline(filename, line); //getting each line in the file
        for(int i = 0; i < line.size(); ++i){
            if ((line[i] == '(') || (line[i] == '{') || (line[i] == '[')){
              s.push(line[i]); //if it has an openining deliminator
                                    //it gets pushed into the stack
            }
            //CHECKING THE THREE POSSIBILITIES
            if((line[i]) == ')'){
              t = s.peek(); //storing the top of the stack in a dummy var
              s.pop(); //seeing if '(' AKA the same deliminator
              if((t == '{') || (t == '[')){
                return false;
              }
              break;
            }
            if((line[i]) == '}'){
              t = s.peek();//storing top of stack in dummy var
              s.pop(); // seeing if it is the same deliminator
              if((t == '(') || (t == '{')){
                return false; //they are NOT the same deliminator, therefore
                             //returning false to the user
              }
              else
                return true;
              break;
            }
            if((line[i]) == ']'){
              //DOING SAME THING AS ABOVE 2 ALGORITHMS
              t = s.peek();
              s.pop();
              if((t == '(') || (t == '{')){
                return false;
              }
              else
                return true;
              break;
            }


        }
        filename.close();
    }

}
