// Augustus Schwab
// HW 2 - ME EN 5250
// Due: 9/16/15
// Problem 5 - Estimating pi using Leibniz's Formula
// 
// This program will calculate pi using the first 10,000 terms of Leibniz's series.
// The answer will be output to the debugger screen to 4 decimal places.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int count = 0;
	double pi = 0;
	double denom = 1;

	for (; count < 10000; count = count + 1){

		if (count % 2 == 0){
			pi = pi + (1 / denom);
		}
		else{
			pi = pi - (1 / denom);
		}

		denom += 2;
		
	}

	pi = pi * 4;

	std::cout << std::fixed;
	std::cout << std::setprecision(4);
	std::cout << pi << "\n";

	cin.get();
	return 0;

}