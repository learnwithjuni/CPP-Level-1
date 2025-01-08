#ifndef GROCERYLIST_H
#define GROCERYLIST_H

#include "DynamicArray.h"

class GroceryList {
  private:
    // Dynamic array that will hold our groceries in a private variable
    DynamicArray groceries;
  
  public:
    // Constructor that simply initializes the array
    GroceryList();

    // Adds an item to the array
    void addItem(Grocery item);

    // Prints the current array
    void printList();

    // Removes an item from the array
    void removeItem(size_t itemNum);
};

#endif // GROCERYLIST_H