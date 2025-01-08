#include "profile.h"
#include <iostream>

// our default constructor
Profile::Profile() : mySize(0), myPosts(new Post[DEFAULT_SIZE]), maxSize(DEFAULT_SIZE) {}

// adds a post to the next available spot in the array
void Profile::addPost(Post newPost) {
  // doubles in size, dynamically, if we're out of space. creates a new array and swaps the values
  if (mySize == maxSize) {
    Post* temp = new Post[maxSize * 2];
    // loads in the new vals
    for (size_t i = 0; i < maxSize; ++i) {
      temp[i] = myPosts[i];
    }
    // swap changes the pointers from temp to myVals
    std::swap(myPosts, temp); 
    maxSize *= 2;
    delete[] temp;
  }
  myPosts[mySize] = newPost;
  mySize++;
}

// prints a specific post given an index
void Profile::printPost(size_t postIndex) {
  if (validPostIndex(postIndex)) {
    // create a temp just for prettier printing and another demonstration of pointers; the print statements could be achieved with myPosts[i].field
    Post* temp = &myPosts[postIndex]; 
    std::cout << "Post number: " << postIndex + 1 << std::endl;
    std::cout << "Post caption: " << temp->caption << std::endl;
    std::cout << "Post hearts: " << temp->hearts << std::endl;
    std::cout << "\n";
  } else {
    std::cout << "Error! This would have attempted to print a post that doesn't exist in the array." << std::endl;
  }
}


// print out all the values that we are holding on to right now
void Profile::printPosts() {
  std::cout << "Now printing out the current profile: " << std::endl;
  for (size_t i = 0; i < mySize; ++i) {
    // use our helper function to print out posts rather than iterating through it again
    printPost(i);
  }
  std::cout << "\n" << std::endl;
}

// bonus: add a statistic calculator
int Profile::sumHearts() {
  int total = 0;
  for (size_t i = 0; i < mySize; ++i) {
    total += myPosts[i].hearts;
  }
  return total;
}

// fills all empty slots in the array with the last entry until we have filled our current capacity.
void Profile::fillProfile() {
  // if there was no last post, then we shouldn't continue execution of code.
  if (mySize == 0) {
    std::cout << "There was no last post to duplicate!" << std::endl; 
    return;
  }

  // make a copy of our last post
  Post lastPost(myPosts[mySize - 1]);

  // iterate through all empty positions in the our array 
  for (; mySize < maxSize; ++mySize) {
    myPosts[mySize] = lastPost;
  }
  
  // print out some statements for the user to get feedback on what actions are occurring
  std::cout << "Filled remaining posts with a post that contained:\nCaption: " << lastPost.caption << "\nHearts: " << lastPost.hearts << std::endl;
  std::cout << "Your profile now contains: " << mySize << " posts!" << std::endl;
  printPosts();
}

// removes a post at a certain index
void Profile::removePost(size_t index) {
  if (validPostIndex(index)) {

    // make a copy of the old array
    Post* temp = new Post[maxSize];
    size_t j = 0;
    for (size_t i = 0; i < maxSize; ++i) {
      // once we get to that index, skip it
      if (i == index) {
        continue;
      }
      temp[j++] = myPosts[i];
    }
    
    // reassign our posts array to the new version
    std::swap(temp, myPosts);

    // clean up by deleting the old array
    delete[] temp;

    // make sure we change our size and we're ready to go
    mySize--;

  } else {
    std::cout << "Error! This would have attempted to remove a post that doesn't exist in the array." << std::endl;
  }
}

// add hearts to a specific post
void Profile::addHearts(size_t postIndex, int numHearts) {
  if (validPostIndex(postIndex)) {
    myPosts[postIndex].hearts += numHearts;
  } else {
    std::cout << "Error! This would have attempted to add hearts to a post that doesn't exist in the array." << std::endl;
  }
}

// helper function that checks to see if a post index is correct or not
bool Profile::validPostIndex(size_t index) {
  return index < mySize;
}