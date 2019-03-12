// Augustus Schwab
// HW 4 - ME EN 5250
// Due: 9/30/15
// Problem 2 - Interleaving Strings
// 
// This program will call a function to interleave the characters of 2 strings
// read from the user. The function will take two const char* and return a pointer 
// to the c-string containing the interleaved characters (a char*).


#include <iostream>
#include <string>


char* strinterleave(const char *a, const char *b) {
    std::size_t size_a = strlen(a);
	std::size_t size_b = strlen(b);

	std::size_t size = size_a + size_b;

	std::size_t size_max = 0;
	std::size_t size_min = 0;

	if (size_a < size_b) {
		size_max = size_b;
		size_min = size_a;
	}
	else {
		size_max = size_a;
		size_min = size_b;
	}
	
	char *strint = new char [size];
	

	std::size_t j = 1;
	std::size_t k = 0;
	std::size_t x = size_min*2;

	for (std::size_t i = 0; i < size_max; ++i) {
		if (i < size_max && i > (size_min - 1) && size_max == size_a) {
			strint[x] = a[i];
			++x;
		}
		else if (i < size_max && i > (size_min - 1) && size_max == size_b) {
			strint[x] = b[i];
			++x;
		}
		else {
			strint[k] = a[i];
			strint[j] = b[i];
		}
		
		j += 2;
		k += 2;
	}

	
	strint[size] = '\0';
	return strint;
	delete[] strint;

}

int main() {
	int num_cases;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
		'\n');

	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		std::string str1;
		std::string str2;
		
		std::getline(std::cin, str1, ' ');
		std::getline(std::cin, str2, '\n');

		char* inter = strinterleave(str1.data(), str2.data());
		
		std::cout << inter << "\n";

	}
	return 0;
}