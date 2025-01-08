#include <iostream>
#include <string>

int main() {
	int i = 0;
	while (i <= 10) {
		std::cout << i << std::endl;
		i++;
	}

	i = 0;
	while (i <= 10) {
		std::cout << i << std::endl;
		i += 2;
	}

	i = 10;
	while (i >= 0) {
		std::cout << i << std::endl;
		i--;
	}

	std::string word;
	std::cout << "Enter a word: ";
	std::cin >> word;
	i = 0;
	while (i < word.length()) {
		std::cout << word[i] << std::endl;
		i++;
	}

	i = word.length() - 1;
	while (i >= 0) {
		std::cout << word[i] << std::endl;
		i--;
	}

	int sum = 0;
	i = 0;
	while (i <= 100) {
		sum += i;
		i++;
	}
	std::cout<< "Sum of first 100 = " << sum << std::endl;

	int factorial = 1;
	i = 1;
	while (i <= 10) {
		factorial *= i;
		i++;
	}
	std::cout << "Factorial of 10 = " << factorial;
	return 0;
}