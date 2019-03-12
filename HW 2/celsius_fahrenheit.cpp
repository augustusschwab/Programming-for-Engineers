// Augustus Schwab
// HW 2 - ME EN 5250
// Due: 9/16/15
// Problem 2 - Printing Table of Temperatures
// 
// This program will read a temperature value from 0 - 30 C and convert the value to the temperature in 
// fahrenheit. The values will be output in table form for example:
//		0 C = 32 F
// This will be done with integres first and then doubles to compare the different values.

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int T_C = 0;
	int T_F = 0;


	std::cout << "Celsius to Fahrenheit Table with Ints " << "\n";

	while (T_C <= 30){
		T_F = (T_C * 9)/5 + 32;
		std::cout << T_C <<"C = "<< T_F <<"F"<< "\n";
		T_C += 1;
	}

	float T_Cf = 0;
	float T_Ff = 0;

	std::cout << "\n";
	std::cout << "Celsius to Fahrenheit Table with Doubles " << "\n";


	while (T_Cf <= 30){
		T_Ff = (T_Cf*9)/5 + 32;
		std::cout << T_Cf << "C = " << T_Ff << "F" << "\n";
		T_Cf += 1;
	}

	cin.get();

	return 0;
}