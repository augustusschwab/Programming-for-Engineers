// Augustus Schwab
// HW 5 - ME EN 5250
// Due: 10/21/15
// Problem 0 - Label Generator
// 
// This program will allow the user to input an arbitrary sequence of labels 
// consisting of a prefix string, coupled with an integer and output a lablel.
// The label will be generated with a abstract type called LabelGenerator.

#include <iostream>
#include <string>


struct LabelGenerator {
	std::string label;
	int index;
	LabelGenerator() {};
	LabelGenerator(std::string label_, int index_) {
		label = label_;
		index = index_;
	}
	std::string next_label();
};


std::string LabelGenerator::next_label() {
		std::string num;
		num = std::to_string(index);
		std::string fullLabel;
		fullLabel = label + num;
		return fullLabel;
}

int main() {
	int num_cases = 0;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
		'\n');

	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		std::string label;
		int index;
		int FinalValue;
		std::getline(std::cin, label, '\n');
		std::cin >> index;
		std::cin >> FinalValue;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
			'\n');
		
		LabelGenerator point_numbers( label, index );
		for (point_numbers.index; point_numbers.index <= FinalValue; point_numbers.index++) {
			std::cout << point_numbers.next_label() << " ";
		}
		std::cout << "\n";	
	}
	return 0;
}