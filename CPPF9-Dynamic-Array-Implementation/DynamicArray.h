#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdio.h>

const size_t DEFAULT_SIZE = 5;

class DynamicArray {

  private:
    size_t mySize; // this keeps track of our current size
    size_t maxSize; // this is the capacity of our array
    int *myVals; // keeps track of the values in an int array

  public:
    DynamicArray();   
    ~DynamicArray();  

    // adds a value to the current location in the dynamic array
    void addVal(int val);

    // print out the current vals in the array
    void printVals();

    // access and prints out a specific value at an index, given that it's within our current bounds
    int get(size_t index);

};

#endif // DYNAMICARRAY_H