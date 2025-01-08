#include <iostream>

int main() {
  // Different ways of creating arrays
  int nums[10];
  int arr[] = { 1, 2, 3 };

  // Printing and updating an element in nums
  std::cout << nums[3] << std::endl;
  nums[3] = 42;
  std::cout << nums[3] << std::endl;

  // Calculating the size of an array
  std::cout << sizeof(nums) / sizeof(nums[0]) << std::endl;

  // Looping through and updating the elements of an array
  for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
    nums[i] = i;
  }

  // Printing the elements in an array by looping through it
  for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
    std::cout << nums[i] << std::endl;
  }
}