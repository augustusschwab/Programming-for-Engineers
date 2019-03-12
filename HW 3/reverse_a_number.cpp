// Augustus Schwab
// HW 3 - ME EN 5250
// Due: 9/23/15
// Problem 5 - Reverse a Number
// 
// This program will reverse and integer. It involves a function that takes in an int
// and reverses. Also, the program will print an invalid statement if the input is not
// a positive integer. 


#include <iostream>
#include <limits>

int rev(int num) {
	int rev = 0;
	while (num != 0) {

		rev = rev * 10;
		rev = num % 10 + rev;
		num = num / 10;
	}

	return rev;
}

int main() {
	int cases = 0;
	std::cin >> cases;

	for (int i = 0; i < cases; ++i) {
		int num = 0;
		std::cin >> num;
		int reverse = 0;

		if(std::cin.fail() || num < 0) {
			std::cout << "Case " << i << ":" << "\n";
			std::cout << "Invalid input" << "\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		else {
			reverse = rev(num);
			std::cout << "Case " << i << ":" << "\n";
			std::cout << reverse << "\n";
		}
		

	}

	return 0;
}