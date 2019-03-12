// Augustus Schwab
// HW 3 - ME EN 5250
// Due: 9/23/15
// Problem 4 - Password Strength Calculator
// 
// This program will ask the user to input a password (without spaces) and outputs 
// how strong the password is.

#include <iostream>
#include <limits>
#include <string>
#include <cctype>

int strength(std::string pass) {
	int score = 0;
	bool low = false;
	bool up = false;
	bool digi = false;
	bool punct = false;
	int rule_comp = 0;

	int size = pass.size();
	score = size;

	for (int i = 0; i <= size; ++i) {
		char var = pass[i];
		if (islower(var) && low != true) {
			score += 1;
			rule_comp += 1;
			low = true;
		}
		if (isupper(var) && up != true) {
			score += 1;
			rule_comp += 1;
			up = true;
		}
		if (isdigit(var) && digi != true) {
			score += 1;
			rule_comp += 1;
			digi = true;
		}
		if (ispunct(var) && punct != true) {
			score += 2;
			rule_comp += 1;
			punct = true;
		}

	}

	if (rule_comp == 2) {
		score *= 2;
	}
	else if (rule_comp == 3) {
		score *= 4;
	}
	else if (rule_comp == 4) {
		score *= 8;
	}

	return score;
}

int main() {
	int cases = 0;
	std::string pass;
	std::cin >> cases;

	for (int i = 0; i < cases; ++i) {
		std::cin >> pass;
		int score = 0;
		score = strength(pass);

		std::cout << "Case " << i << ":" << "\n";
		std::cout << "Strength: " << score << "\n";
	}


	return 0;
}