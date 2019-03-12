#include "sum_stat.h"

Sum::Sum() {
	sum = 0;
}

//Sum::~Sum() {}

void Sum::accumulate(double x) {
	sum += x;
}

void Sum::postprocess() {
	// Nothing to do
}

double Sum::result() const {
	return sum;
}

void Sum::print(std::ostream &os) const {
	os << "Sum = " << sum;
}