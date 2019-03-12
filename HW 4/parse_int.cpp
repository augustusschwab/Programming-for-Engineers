// Augustus Schwab
// HW 4 - ME EN 5250
// Due: 10/4/15
// Problem 3 - Parsing Integers
// 
// This program will parse an integer from a string that is robust to invalid integers.
// The function called will recieve a char* and will output a boolean to indicate whether 
// the string is an integer or not.


#include <iostream>
#include <string>
#include <cctype>

bool parse_int(const char *str, int &val) {
	std::size_t size = strlen(str);
	int y = 0;

// Check to see if the array is composed entirely of integers	
	for (std::size_t i = 0; i < size; ++i) {
		int x = str[i] - 0;
		if(x == 43 || x == 45){
			y = 1;
		}
		else {
			if (std::isdigit(str[i]) == false) {
				y = 0;
				i = size;
			}
			else {
				y = 1;
			}
		}
		
	}

// Parsing Begins 
	if (y == 1) {
		int sign = 0;

		for (int i = 0; i < size; i++) {
			int n = 0;
			int k = 0;
			int x = str[i] - 0;
			if (x == 45) {
				val = 0;
				sign = -1;
			}
			else if(x == 43){
				val = 0;
			}
			else{
					char m = str[i];
					k = m - '0';
					n = k;
					if (n != 0) {
						while (n > 0) {
							val *= 10;
							n /= 10;
						}
						val += k;
					}
					else {
						val *= 10;
					}
				}
			
		}

		if (sign == -1)
			val *= -1;
	}

	if (y == 0) {
		return false;
	}
	else {
		return true;
	}

}


int main() {
	int num_cases;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
		'\n');

	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		std::string str;
		std::cin >> str;
		
		int val = 0;
		bool parse = false;

		parse = parse_int(str.data(), val);
		
		if (parse == false) {
			std::cout << "Parsing Failed" << "\n";
		}
		else {
			std::cout << val << "\n";
		}

	}
	return 0;
}