// Augustus Schwab
// HW 4 - ME EN 5250
// Due: 10/4/15
// Problem 1 - Word Swap
// 
// This program will call a function that will swap the order of 2 words 
// read from a standard input. The function will only read up to 19 characters
// since you store words in arrays of size 20.


#include <iostream>


void swap(char*& wordptr1, char*& wordptr2) {
	
	char* old_wordptr1 = wordptr1;
	wordptr1 = wordptr2;
	wordptr2 = old_wordptr1;
		
}

int main() {
	int num_cases;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
		'\n');
	const int size_max = 20;
	char storage1[size_max] = "";
	char storage2[size_max] = "";
	// Since we can't swap arrays, we need to create pointers to
	// refer to our words
	char* word1_ptr = storage1;
	char* word2_ptr = storage2;

	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		std::cin.getline(storage1, size_max, ' ');
		// Put the last read character back to the stream and
		// clear failbit if set
		std::cin.clear();
		std::cin.unget();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
			' ');
		std::cin.getline(storage2, size_max);
		std::cin.clear();
		std::cin.unget();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
			'\n');
		std::cout << word1_ptr << " " << word2_ptr << "\n";
		swap(word1_ptr, word2_ptr);
		std::cout << word1_ptr << " " << word2_ptr << "\n";
	}
	return 0;
}