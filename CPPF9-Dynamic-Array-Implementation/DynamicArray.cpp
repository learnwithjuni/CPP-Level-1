#include "DynamicArray.h"
#include <iostream>

// our default constructor
DynamicArray::DynamicArray() : mySize(0), maxSize(DEFAULT_SIZE), myVals(new int[DEFAULT_SIZE]) {}

// our destructor
DynamicArray::~DynamicArray() {
  delete[] myVals;
  myVals = nullptr;
  mySize = 0;
}

// adds a value to the next available spot in the array
void DynamicArray::addVal(int val) {
  // doubles in size, dynamically, if we're out of space. creates a new array and swaps the values
  if (mySize == maxSize) {
    std::cout << "\nRESIZING!\n" << std::endl;
    int* temp = new int[maxSize * 2];
    // loads in the new vals
    for (size_t i = 0; i < maxSize; ++i) {
      temp[i] = myVals[i];
    }
    // swap changes the pointers from temp to myVals
    std::swap(myVals, temp); 
    maxSize *= 2;
    delete[] temp;
  }
  myVals[mySize] = val;
  mySize++;
}

// print out all the values that we are holding on to right now
void DynamicArray::printVals() {
  for (size_t i = 0; i < mySize; ++i) {
    std::cout << myVals[i] << " ";
  }
}

// access and prints out a specific value at an index, given that it's within our current bounds
int DynamicArray::get(size_t index) {
  if (index < mySize) {
    return myVals[index];
  } else {
    std::cout << "Error! This was not a valid index." << std::endl;
    return -1;
  }
}