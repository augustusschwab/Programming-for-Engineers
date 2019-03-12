// Augustus Schwab
// HW 2 - ME EN 5250
// Due: 9/16/15
// Problem 1 - Sum of Multiples
// 
// This program will compute the sum of all multiples of 6 from 0-4000 and then print the value.

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int s = 0;
	int n = 6;
	int x = 6;
	int y = 3996;
	int z = 0;

	z = y / n;

	s = (z / 2)*(x + y);
	std::cout << std::fixed;
	std::cout << std::setprecision(0);
	std::cout << "Sum of multiples of 6 from 0 to 4000 is = " << s << "\n";

	cin.get();

	return 0;

}