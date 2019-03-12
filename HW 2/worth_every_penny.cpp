// Augustus Schwab
// HW 2 - ME EN 5250
// Due: 9/16/15
// Problem 4 - Worth Every Penny
// 
// This program will calculate the profit made from a business of selling rings.
// The profit is stored as a double. The sales of the rings occurred as follows:
//		The first ring was sold for .01, second for .02, etc.
//				.01 + .02 + .03 ... 
// The value is then printed to the debugger screen.

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	// This calculates the profit from selling rings using doubles.
	double profit_A = 0;
	double count_A = 0;

	for (; count_A <= 100000; count_A = count_A + .01 ){
		
		profit_A = profit_A + count_A;

	}

	std::cout << std::fixed;
	std::cout << std::setprecision(2) << profit_A << "\n";

	long long int profit_B = 0;
	long long int count_B = 0;

	for (; count_B <= 10000000; count_B = count_B + 1){

		profit_B = profit_B + count_B;

	}

	profit_B = profit_B / 100;
	
	std::cout << std::fixed;
	std::cout << std::setprecision(2) << static_cast<double> (profit_B) << "\n";
	

	cin.get();

	return 0;

}