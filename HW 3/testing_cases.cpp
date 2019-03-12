// Augustus Schwab
// HW 3 - ME EN 5250
// Due: 9/23/15
// Problem 1 - Testing Cases
// 
// This program will read the number of cases to be tested as an integer and will then
// iterate through each case, printing:
//					Case #:
//					Echo: Whatever the user entered
// The cases will start from 0.


#include <iostream>
#include <limits>
#include <string>

int main() {
	std::string text;
	int cases = 0;
	
	std::cin >> cases;

	for (int i = 0; i < cases; ++i) {
		std::cin >> text;
		std::cout << "Case " << i << ":" << "\n";
		std::cout << "Echo: " << text <<"\n";
	}
	

	return 0;
}

