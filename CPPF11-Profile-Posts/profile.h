#ifndef PROFILE_H
#define PROFILE_H

#include <stdio.h>
#include <string>

struct Post {
  std::string caption;
  int hearts;
};

const size_t DEFAULT_SIZE = 5;

class Profile {

  private:
    size_t mySize; // this keeps track of our current size
    size_t maxSize; // this is the capacity of our array
    Post *myPosts; // keeps track of the values in an array of strings

    // helper function to check if an index is valid or not
    bool validPostIndex(size_t index);

  public:
    // default constructor
    Profile();

    // adds a Post to the current location in the dynamic array
    void addPost(Post newPost);

    // prints a specific post given an index
    void printPost(size_t postIndex);

    // print out the current vals in the array
    void printPosts();

    // sums all the hearts of all the posts in our array
    int sumHearts();

    // fills all empty slots in the array with the last entry until we have filled our current capacity.
    void fillProfile(); 

    // removes a post at a certain index
    void removePost(size_t index);

    // add hearts to a specific post
    void addHearts(size_t postIndex, int numHearts);
};

#endif // PROFILE_H