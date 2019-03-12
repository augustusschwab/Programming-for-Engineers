// Augustus Schwab
// HW 3 - ME EN 5250
// Due: 9/23/15
// Problem 6 - Frame a Name Revisited
// 
// This program will provide a fancy greeting for someone. It will take in the users
// name and then call a function to print out a framed greeting, passing the users 
// name. 

#include <iostream>
#include <limits>
#include <string>


void greeting(std::string name) {
	std::string wel = "* Welcome to my program ";
	std::string hi = "* Hello, ";
	std::string top = "*";
	std::string star = " *";
	std::string space = "*";

	unsigned size = wel.size();

	unsigned n_size = name.size();

	std::string greet = hi + name;
	unsigned g_size = greet.size();

	if (g_size > size) {
		size = g_size + 1;
		wel.resize(size, ' ');
		greet.resize(size, ' ');
	}
	else {
		greet.resize(size, ' ');
	}

	top.resize(size + 2, '*');
	space.resize(size, ' ');

	std::cout << top << "\n";
	std::cout << space + star << "\n";
	std::cout << greet + star << "\n";
	std::cout << wel + star << "\n";
	std::cout << space + star << "\n";
	std::cout << top << "\n";
}



int main() {
	int cases = 0;
	std::cin >> cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 0; i < cases; ++i) {
		std::string name;
		std::getline(std::cin, name);
		std::string greet;

		std::cout << "Case " << i << ":" << "\n";
		greeting(name);
	}
	

	return 0;
}