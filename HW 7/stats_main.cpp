#include <vector>
#include <string>
#include "statistic.h"
#include "min_stat.h"
#include "max_stat.h"
#include "average_stat.h"
#include "sum_stat.h"
#include "stddev_stat.h"

// We can define an output operator overload for a Statistic&
// and it will call the child's overloaded print method,
// allowing us to generically print objects.
std::ostream& operator<<(std::ostream &os, const Statistic &stat) {
	stat.print(os);
	return os;
}


int main() {
	int num_cases = 0;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int k = 0; k < num_cases; ++k) {
		std::cout << "Case " << k << ":\n";
		int num_stats = 0;
		std::cin >> num_stats;
		std::string stat;
		// We can now create a vector of Statistic pointers to point to the
		// different statistics we want to compute about some dataset
		std::vector<Statistic*> statistics;
		for (int i = 0; i < num_stats; ++i) {
			std::cin >> stat;
			if (stat == "min") statistics.push_back(new Min{});
			if (stat == "max") statistics.push_back(new Max{});
			if (stat == "average") statistics.push_back(new Average{});
			if (stat == "sum") statistics.push_back(new Sum{});
			if (stat == "stddev") statistics.push_back(new Stddev{});
		}
		int num_vals = 0;
		std::cin >> num_vals;
		double val = 0;
		std::vector<double> vals;
		for (int i = 0; i < num_vals; ++i) {
			std::cin >> val;
			vals.push_back(val);
		}
		for (int i = 0; i < num_vals; ++i) {
			double x = vals[i];
			for (size_t j = 0; j < statistics.size(); ++j) {
				statistics[j]->accumulate(x);
			}
		}
		// Do any post processing our statistics may need and print the results
		for (size_t i = 0; i < statistics.size(); ++i) {
			statistics[i]->postprocess();
			std::cout << *statistics[i] << "\n";
		}
		// Go through and delete all our dynamically allocated statistics
		for (size_t i = 0; i < statistics.size(); ++i) {
			delete statistics[i];
			statistics[i] = nullptr;
		}
	}
	return 0;
}