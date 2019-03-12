#include <iostream>
#include "my_array.h"

std::ostream& operator<<(std::ostream &os, const MyArray &a) {
	os << "{ ";
	for (size_t i = 0; i < a.get_size(); ++i) {
		os << a[i];
		if (i + 1 != a.get_size()) {
			os << ", ";
		}
		else {
			os << " }";
		}
	}
	return os;
}


int main() {
	size_t num_cases = 0;
	std::cin >> num_cases;
	for (size_t i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		size_t size;
		std::cin >> size;
		MyArray array{size};
		for (size_t j = 0; j < array.get_size(); ++j) {
			std::cin >> array[j];
		}
		std::cout << array << "\n";
	}
	return 0;
}