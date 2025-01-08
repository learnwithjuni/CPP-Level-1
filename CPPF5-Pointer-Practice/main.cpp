#include <iostream>
#include <string>

// forward declaration of question 3
void question3(std::string inputStr);

int main() {

  std::cout << "–––––––––––\n" << "Question 1:" << std::endl;
  // size_t is an only-positive type
  size_t mySize = 20;
  int arr1[mySize];

  // load values into arr1
  for (size_t i = 0 ; i < mySize; ++i) {
    arr1[i] = i;
  }

  // 1. How would we advance through an array at twice the speed using a pointer?
  // declare two pointers to point to arr1
  int *p1 = arr1;
  int *p2 = arr1;

  std::cout << "*p1 and *p2 are originally equal to: " << std::endl;
  std::cout << *p1 << " " << *p2 << std::endl;

  for (size_t i = 0; i < mySize / 2; ++i) {
    std::cout << "loop number: " << i << std::endl;
    std::cout << "p1 is: " << *(p1++) << std::endl;
    p2 += 2;
    std::cout << "p2 is: " << *p2 << std::endl;
  }

  /*
  Debug 1a for student: why would this not work?

  int *p1 = arr1;
  int *p2 = arr1;
  for (size_t i = 0; i < mySize / 2; ++i) {
    std::cout << "loop number: " << i << std::endl;
    std::cout << "p1 is: " << *(p1++) << std::endl;
    std::cout << "p2 is: " << *(p2 += 2) << std::endl;
  }
  */

  /*
  Debug 1b for student: why would this not work?

  int *p1, p2 = arr1;
  for (size_t i = 0; i < mySize / 2; ++i) {
    std::cout << "loop number: " << i << std::endl;
    std::cout << "p1 is: " << *(p1++) << std::endl;
    std::cout << "p2 is: " << *(p2 += 2) << std::endl;
  }

  //fixed version: 
  int *p1, *p2;
  p1 = p2 = arr1;
  */

  /*
  Debug 1c for student: why would this not work?

  int *p1, *p2;
  p1 = p2 = arr1;
  for (size_t i = 0; i < mySize / 2; ++i) {
    std::cout << "loop number: " << i << std::endl;
    std::cout << "p1 is: " << *(++p1) << std::endl;
    std::cout << "p2 is: " << *(p2 += 2) << std::endl;
  }
  */

  std::cout << "\n\n–––––––––––\n" << "Question 2:" << std::endl;

  // 2. Generate 2 pointers that point to a reference of an array, and start one at the beginning of the array and one at the end. Print out when these pointers meet!

  std::string startString = "JuniLearning";
  size_t stringSize = startString.size();

  // Debug 2a: this is DANGEROUS! Why?
  // size_t chrArrLen = sizeof(chrArr);

  // declare a char array of stringSize
  char chrArr[stringSize];

  // load the char array with the string characters
  for (size_t i = 0; i < stringSize; ++i) {
    chrArr[i] = startString[i];
  }

  // initialize our pointers
  char* chrP1 = &chrArr[0];
  char* chrP2 = &chrArr[stringSize - 1];

  // Keep a count of the number of times that these pointers increased
  int numP1, numP2;
  numP1 = numP2 = 0;

  // Print out some starting information about our string and pointers
  std::cout << "Starting string: " << chrArr << std::endl;
  std::cout << "Starting chrP1 is pointing to: " << *chrP1 << std::endl;
  std::cout << "Starting chrP2 is pointing to: " << *chrP2 << std::endl;

  // move up the pointers until we are matching
  while (chrP1 != chrP2) {
    chrP1++;
    numP1++;
    std::cout << "chrP1 is pointing to: " << *chrP1 << std::endl;

    // if we're already matching, don't iterate more times.
    if (chrP2 != chrP1) {
      chrP2--;
      numP2++;
    }
    std::cout << "chrP2 is pointing to: " << *chrP2 << std::endl;
  }

  // Final printing of some statistics
  std::cout << "\nNumber of times p1 pointer increased: " << numP1 << std::endl;
  std::cout << "Number of times p2 pointer decreased: " << numP2 << std::endl;


  /*
  // QUESTION 2b: Debug 
  // Why doesn't this work for even-numbered sized strings?

  while (chrP1 != chrP2) {
    chrP1++;
    chrP2--;
  }
  */


  // QUESTION 3:
  // Write a special pointer that advances its position only by the value of the integer held in the string: for example, “1hello” should only advance to h. “3hello” should advance to the first “l”. However “12e4woah” should advance to the final “h”. If the character the special pointer is pointing at is not a number, then the first pointer should not advance.

  std::cout << "\n\n–––––––––––\n" << "Question 3:" << std::endl;

  // Example 1
  std::string question3a = "1hello";
  question3(question3a);
  std::cout << "\n–––––––––––\n" << std::endl;

  // Example 2
  std::string question3b = "3hello";
  question3(question3b);
  std::cout << "\n–––––––––––\n" << std::endl;

  // Example 3
  std::string question3c = "12e4woah";
  question3(question3c);
}

// implementatino of question 3
void question3(std::string inputStr) {
  std::cout << "Now implementing question 3 on string " << inputStr << " using an integer as index:" << std::endl;

  // EASIER IMPLEMENTATION WITH INTEGER INDEX POINTER
  // this end index will keep track of the index where we end up
  int end = 0;

  // iterate through the string using i to look through the string, and only changing end if the character i is looking at is a digit or not
  for (int i = 0; i < inputStr.length(); ++i) {
    std::cout << "Now looking at character " << inputStr[i] << std::endl;
    // if this character is a digit, then advance end pointer
    if (isdigit(inputStr[i])) {
      std::cout << "We encountered a digit, " << inputStr[i] << std::endl;
      // converts the increment to its numeric value
      int increment = inputStr[i] - '0';

      // only advance end if it will not surpass the end of the length of our string
      if (end + increment < inputStr.length()) {
        end += increment;
        std::cout << "We incremented i by: " << increment << ", putting our end pointer pointing to: " << inputStr[end] << std::endl;
      } else {
        std::cout << "The increment would have passed the end of the string, we're done!" << std::endl;
        break;
      }
    }
  }
  
  // print out information about the end location of the second pointer
  std::cout << "The final location of the end pointer was pointing to: " << inputStr[end] << ", after advancing " << end << " characters." << std::endl;

  // ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

  // IMPLEMENTATION 2
  std::cout << "Now implementing question 3 on string " << inputStr << " using a char*:" << std::endl;

  // create a char pointer to the address of the first character in the string
  char* specAdvPtr = &inputStr[0];
  std::cout << "The pointer starts at: " << *specAdvPtr << std::endl;
  for (size_t i = 0; i < inputStr.length(); ++i) {
    std::cout << "Now looking at character " << inputStr[i] << std::endl;
    if (isdigit(inputStr[i])) {
      // to get the specific digit value, we need to cast it to a character
      int increment = int(inputStr[i]) - '0';
      
      specAdvPtr += increment;
      std::cout << "The pointer increased by " << (increment) << " character(s)" << std::endl;
      std::cout << "The value of where the pointer is pointing at now: " << *specAdvPtr << std::endl;
    }
  }

  // print out information about the end location of the second pointer
  std::cout << "The final location of the end pointer was pointing to: " << inputStr[end] << std::endl;
}