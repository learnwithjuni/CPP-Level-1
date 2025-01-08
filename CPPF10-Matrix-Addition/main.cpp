#include <iostream>
using namespace std;

int main() {
  int r, c;
  cout << "\nEnter number of rows (between 1 and 100): ";
  cin >> r;
  cout << "Enter number of columns (between 1 and 100): ";
  cin >> c;
  int a[r][c], b[r][c], sum[r][c];

  // Storing elements of first matrix entered by user.
  cout << endl << "Enter elements of 1st matrix: " << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << "Enter element a[" << i + 1 << "][" << j + 1 << "]: ";
      cin >> a[i][j];
    }
  }

  // Storing elements of second matrix entered by user.
  cout << endl << "Enter elements of 2nd matrix: " << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << "Enter element b[" << i + 1 << "][" << j + 1 << "]: ";
      cin >> b[i][j];
    }
  }

  // Adding two matrices
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      sum[i][j] = a[i][j] + b[i][j];
    }
  }
  
  // Displaying the resultant sum matrix.
  cout << endl << "Sum of two matrices is: " << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << sum[i][j] << "  ";
      if (j == c - 1) {
        cout << endl;
      }
    }
  }

  return 0;
}