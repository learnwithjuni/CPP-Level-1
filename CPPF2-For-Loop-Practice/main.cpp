#include <iostream>
#include <string>

int main() {
	for (int i = 11; i <= 20; i++) {
		std::cout << i << std::endl;
	}

	for (int i = 2; i <= 10; i += 2) {
		std::cout << i << std::endl;
	}

	for (int i = 10; i >= 0; i--) {
		std::cout << i << std::endl;
	}

	std::string word;
	std::cout << "Enter a word: ";
	std::cin >> word;
	for (int i = 0; i < word.length(); i++) {
		std::cout << word[i] << std::endl;
	}

	for (int i = word.length() - 1; i >= 0 ; i--) {
		std::cout << word[i] << std::endl;
	}

	int sum = 0;
	for (int i = 0; i <= 100; i++) {
		sum += i;
	}
	std::cout << "Sum of first 100 = " << sum << std::endl;

	int factorial = 1;
	for (int i = 1; i <= 10; i++) {
		factorial *= i;
	}
	std::cout << "Factorial of 10 = " << factorial;
	return 0;
}