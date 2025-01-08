#include <iostream>
#include <string>

int main() {

  // This is an example of an integer
  int myAge = 13;
  std::cout << myAge << std::endl;
  // We can also initialize a variable and assign it a value later
  int anotherNum;
  anotherNum = 25;

  // This is an example of a double
  double myRating = 9.6;
  std::cout << myRating << std::endl;

  // This is an example of casting a double to and int
  std::cout << int(myRating) << std::endl;

  // This is an example of a boolean
  bool isHot = false;
  std::cout << isHot << std::endl;
  // We can also use integers to assign boolean values
  isHot = 1337;
  std::cout << isHot << std::endl;

  // This is an example of a character
  char myChar = 'M';
  std::cout << myChar << std::endl;
  // The below line throws an error
  // char anotherChar = "M";

  // This is an example of a string
  std::string myString = "Hello world!";
  std::cout << myString << std::endl;
  std::cout << myString[0] << std::endl;
  std::cout << myString.length() << std::endl;
  // This is an example of concatenation
  std::string myString2 = " How are you?";
  std::cout << myString + myString2 << std::endl;

  return 0;
}