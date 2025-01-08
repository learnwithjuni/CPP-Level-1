#include "matrix.h"
#include <iostream>

int numMatrices = 0;

Matrix::Matrix(int r, int c) {
  numRows = r;
  numCols = c;
  matNum = ++numMatrices;
  
  mat = new int*[numRows];
  for (int i = 0; i < numRows; i++) {
    mat[i] = new int[numCols];
  }
}

Matrix::Matrix(int r, int c, int** matrix) {
  numRows = r;
  numCols = c;
  matNum = ++numMatrices;
  mat = matrix;
}

Matrix::~Matrix() {
  for (int i = 0; i < numRows; i++) {
    delete mat[i];
  }
  delete mat;
}

int Matrix::getNumRows() {
  return numRows;
}

int Matrix::getNumCols() {
  return numCols;
}

int Matrix::get(int r, int c) {
  return mat[r][c];
}

void Matrix::fillMatrix() {
  std::cout << std::endl << "Enter elements of matrix " << matNum << ":" << std::endl;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			std::cout << "Enter element (" << i + 1 << ", " << j + 1 << "): ";
			std::cin >> mat[i][j];
		}
	}
}

Matrix Matrix::add(Matrix other) {
  if (numRows != other.getNumRows() || numCols != other.getNumCols()) {
    std::cout << "Incompatible matrices (dimensions do not match)" << std::endl;
    return Matrix(0, 0);
  }

  int **res = new int*[numRows];
  for (int r = 0; r < numRows; r++) {
    res[r] = new int[numCols];
  }

  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      res[i][j] = mat[i][j] + other.get(i, j);
    }
  }

  return Matrix(numRows, numCols, res);
}

Matrix Matrix::multiply(Matrix other) {
  if (numCols != other.getNumRows()) {
    std::cout << "Incompatible matrices (number of columns of first matrix does not match number of rows of second matrix)" << std::endl;
    return Matrix(0, 0);
  }

  int **res = new int*[numRows];
  for (int r = 0; r < numRows; r++) {
    res[r] = new int[other.getNumCols()];
  }

  for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < other.getNumCols(); j++) {
			for (int k = 0; k < numCols; k++) {
				res[i][j] += mat[i][k] * other.get(k, j);
			}
		}
	}

  return Matrix(numRows, other.getNumCols(), res);
}

void Matrix::display() {
  std::cout << "Matrix " << matNum << ":" << std::endl;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      std::cout << mat[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}