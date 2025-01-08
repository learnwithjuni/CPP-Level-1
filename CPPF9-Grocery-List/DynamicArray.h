#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdio.h>
#include <string>

// Grocery item that will be used as the type for the dynamic array
struct Grocery {
  std::string name;
  double price;

  // Default constructor
  Grocery() : name(""), price(0) {}

  // Overloaded constructor
  Grocery(std::string newName, double newPrice) : name(newName), price(newPrice) {}
};

const size_t DEFAULT_SIZE = 5;

class DynamicArray {

  private:
    size_t mySize; // this keeps track of our current size
    size_t maxSize; // this is the capacity of our array
    Grocery *myVals; // keeps track of the values in a Grocery array

  public:
    // default constructor
    DynamicArray();   
 
    // the destructor
    ~DynamicArray();  

    // adds a value to the current location in the dynamic array
    void addVal(Grocery val);

    // print out the current vals in the array
    void printVals();

    // access and prints out a specific value at an index, given that it's within our current bounds
    Grocery accessVal(size_t index);

    // Gets the current size of the array
    size_t getSize();
};

#endif // DYNAMICARRAY_H