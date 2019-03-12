// Augustus Schwab
// HW 3 - ME EN 5250
// Due: 9/23/15
// Problem 3 - Testing Cases
// 
// This program will take 2 positive integers as inputs and use the Euclids algorithm to 
// compute the greatest common divsor of the two numbers.

#include <iostream>
#include <limits>
#include <string>

int GCD(int x, int y) {
	int a = x;
	int b = y;
	int old_b = 0;
	int old_a = 0;

	if (a < b) {
		old_a = a;
		a = b;
		b = old_a;
	}
	if (b != 0) {
		old_b = b;
		b = a % b;
		a = old_b;
	}

	if (b == 0) {
		return a;
	}
	else {
		return GCD(a, b);
	}
}

int main() {
	int cases = 0;
	int num1 = 0;
	int num2 = 0;
	int x = 0;
    std::cin >> cases;

	for (int i = 0; i < cases; ++i) {
		std::cin >> num1;
		std::cin >> num2;
		
		x = GCD(num1, num2);

		std::cout << "Case " << i << ":" << "\n";
		std::cout <<  x << "\n";
	}

	return 0;
}
