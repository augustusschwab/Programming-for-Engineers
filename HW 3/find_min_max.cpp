// Augustus Schwab
// HW 3 - ME EN 5250
// Due: 9/23/15
// Problem 2 - Find the Minimum and Maximum in the List of Numbers
// 
// This program will read in a number the tells the program how many integers to expect. The user will then
// input the number of integers in the list. The program will then read the list and find the min and max
// in the list of numbers.

#include <iostream>
#include <limits>
//#include <sstream>
//#include <string>
//#include <cstring>

int main() {
	int cases = 0;
	int count = 0;
	int min = 0;
	int max = 0;
	int num;
	std::cin >> cases;
		
	for (int i = 0; i < cases; ++i) {
		std::cin >> count;

		for (int i = 0; i < count; ++i) {
			std::cin >> num;

			if (i == 0) {
				min = num;
				max = num;
			}

			if (num < min) {
				min = num;
			}

			if (num > max) {
				max = num;
			}

		}

		std::cout << "Case " << i << ":" << "\n";
		std::cout << "Min: " << min << "\n";
		std::cout << "Max: " << max << "\n";

		min = 0;
		max = 0;

	}
	
	return 0;
}

