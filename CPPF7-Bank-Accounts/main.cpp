#include <iostream>

int calcTotalBalance(int arr[], int n);

int main() {
  int numTransactions, amt;

  std::cout << "\nHello! How many transactions have you made this past month? " ;
  std::cin >> numTransactions;
  int amounts[numTransactions];

  std::cout << "Thank you! Please enter the amount for each transaction made. Please make sure your withdrawals are negative: " << std::endl;

  for (int i = 0; i < numTransactions; i++) {
    std::cout << "Enter a transaction amount: ";
    std::cin >> amt;
    amounts[i] = amt;
  }

  std::cout << "You have a balance of $" << calcTotalBalance(amounts, numTransactions) << " in your account at this time. Thank you!";
}

int calcTotalBalance(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}