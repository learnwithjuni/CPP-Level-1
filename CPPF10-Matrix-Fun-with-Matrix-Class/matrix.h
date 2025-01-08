#ifndef MATRIX_H
#define MATRIX_H

#include <string>

class Matrix {

  private:
    int numRows;

    int numCols;

    int** mat;

    int matNum;
    
  public:
    Matrix(int r, int c);

    Matrix(int r, int c, int** matrix);

    ~Matrix();

    int getNumRows();

    int getNumCols();

    int get(int r, int c);

    void fillMatrix();

    Matrix add(Matrix other);

    Matrix multiply(Matrix other);

    void display();

};

#endif // MATRIX_H