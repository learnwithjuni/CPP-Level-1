#include "GroceryList.h"
#include <iostream>

GroceryList::GroceryList() : groceries(DynamicArray()) {}

void GroceryList::addItem(Grocery item) {
  groceries.addVal(item);
}

void GroceryList::printList() {
  std::cout << "Here are your groceries! You have " << groceries.getSize() << " grocery items." << std::endl;
  groceries.printVals();
}

// Remove a grocery item based on 1-starting indexing
void GroceryList::removeItem(size_t itemNum) {
  if(itemNum <= 0 || itemNum > groceries.getSize()) {
    std::cout << "Sorry! That's not a valid item number to remove." << std::endl;
    return;
  } 
  // Generate a new dynamic array to copy the values into
  DynamicArray newArr;
  for (size_t i = 0; i < groceries.getSize(); ++i) {
    if (i + 1 == itemNum) {
      continue;
    }
    newArr.addVal( Grocery(groceries.accessVal(i)) );
  }

  // End by swapping the current groceries array with the new one
  std::swap(newArr, groceries);
  std::cout << "You have successfully removed the item number " << itemNum << " from your list." << std::endl;
}