#include <iostream>
#include <string>
#include "matrix.h"

int main() {
	int r1, c1, r2, c2;
  std::string response = "";
  while (response != "add" && response != "multiply") {
    std::cout << "After creating your matrices, will you want to add them or multiply them? ";
    std::cin >> response;
  }
  
	std::cout << "Enter rows and column for first matrix: ";
	std::cin >> r1 >> c1;
	std::cout << "Enter rows and column for second matrix: ";
	std::cin >> r2 >> c2;

  while (response == "add" && r1 != r2 && c1 != c2) {
    std::cout << "Error! To add two matrices, they must have the same dimensions." << std::endl;
    std::cout << "Enter rows and column for first matrix: ";
    std::cin >> r1 >> c1;
    std::cout << "Enter rows and column for second matrix: ";
    std::cin >> r2 >> c2;
  }

  while (response == "multiply" && c1 != r2) {
    std::cout << "Error! To multiply two matrices, the number of columns of the first matrix must match the number of rows of the second matrix" << std::endl;
    std::cout << "Enter rows and column for first matrix: ";
    std::cin >> r1 >> c1;
    std::cout << "Enter rows and column for second matrix: ";
    std::cin >> r2 >> c2;
  }

  Matrix mat1 = Matrix(r1, c1);
  Matrix mat2 = Matrix(r2, c2);
  mat1.fillMatrix();
  mat2.fillMatrix();
  mat1.display();
  mat2.display();

  if (response == "add") {
    Matrix additionResult = mat1.add(mat2);
    additionResult.display();
  } else {
    Matrix multiplicationResult = mat1.multiply(mat2);
    multiplicationResult.display();
  }
  
	return 0;
}