// Augustus Schwab
// HW 1 - ME EN 5250
// Due: 9/9/15
// Problem 3  - Compound Interest
// 
// This program will calculate the compound interest on a $50,000 loan over a period of 4 years. 
// It will then print the value of the loan after 4 years to 2 decimal places.

#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <ios>

using namespace std;

int main(){
	float loan = 5e4;
	std::cout << std::fixed;
	std::cout << std::setprecision(2); // Sets the loan value precision to 2 decimal places

		for (int count = 0; count < 4; count = count + 1){
			
			loan = loan + (loan * 5e-2);
		}

	std::cout << "Final loan = " << loan << "\n";

	cin.get();

	return 0;
}