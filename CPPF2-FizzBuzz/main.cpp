#include <iostream>

int main() {
  std::cout << "\n";
  for (int i = 1; i <= 50; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      std::cout << "FizzBuzz!" << std::endl;
    } else if (i % 3 == 0) {
      std::cout << "Fizz!" << std::endl;
    } else if (i % 5 == 0) {
      std::cout << "Buzz!" << std::endl;
    } else {
      std::cout << i << std::endl;
    }
  }
  
  /*
  // One possible approach to solving the bonus problem
  int num1, num2;
  std::cout << "Enter a number: ";
  std::cin >> num1;
  std::cout << "Enter a number: ";
  std::cin >> num2;

  for (int i = 1; i <= 50; i++) {
    if (i % num1 == 0 && i % num2 == 0) {           
      std::cout << "FizzBuzz!" << std::endl;
    } else if (i % num1 == 0) {
      std::cout << "Fizz!" << std::endl;
    } else if (i % num2 == 0) {
      std::cout << "Buzz!" << std::endl;
    } else {
      std::cout << i << std::endl;
    }
  }
  */

  return 0;
}