// Augustus Schwab
// HW 6 - ME EN 5250
// Due: 10/30/15
// Problem 0 - n-Dimensional Vector
// 
// This program will read in two different combinations of nucleotides
// the first being the base and the second being the template. It will then
// determine how many positions the template can be paired to the base.


#include <iostream>
#include <string>
#include <vector>


bool match(const char base_, const char template_)
{
	if(	base_ == 'A' && template_ == 'T' ||
		base_ == 'T' && template_ == 'A' ||
		base_ == 'G' && template_ == 'C' ||
		base_ == 'C' && template_ == 'G'	)
	{
		return true;
	}
	else { return false; }
}

std::vector<int> pairs(const char* base_, const char* template_)
{
	int size_base = strlen(base_);
	int size_template = strlen(template_);
	std::vector<int> result;
	for (int i = 0; i < 1; ++i) {
		for (int j = 0; j < size_base; ++j) {
				if (match(base_[j], template_[i]))
				{
					bool success = false;
					for (int k = 0; k < size_template-1; ++k) {
						
						if (!match(base_[(j + 1) + k], template_[k + 1])) { 
							success = false; 
							break;
						}
						else { success = true; }
						
					}
					if (size_template == 1) success = true;
					if(success == true) { 
						result.push_back(j);
					}
				}
		}
	}
	if (result.empty()) {
		throw 1;
	}
	return result;
}

int main() {
	int num_cases = 0;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
		'\n');
	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		std::string base_, template_;
		std::cin >> base_ >> template_;
		try {
			std::vector<int> positions = pairs(base_.data(), template_.data());
			size_t size = positions.size();
			for (unsigned int j = 0; j < size; ++j) {
				std::cout << positions[j] << " ";
			}
			std::cout << "\n";
		}
		catch (int fail) {
			if (fail == 1) std::cout << "None" << "\n";
		}
	}
	return 0;
}