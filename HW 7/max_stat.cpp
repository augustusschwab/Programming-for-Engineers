#include "max_stat.h"

Max::Max() {
	max = -std::numeric_limits<double>::infinity();
}

//Max::~Max() {};

void Max::accumulate(double x) {
	max = std::max(max, x);
}
	
void Max::postprocess() {
	// Nothing to do
}
	
double Max::result() const {
	return max;
}

void Max::print(std::ostream &os) const {
	os << "Max = " << max;
}