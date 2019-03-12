#include "average_stat.h"

Average::Average(){
	average = 0;
	count = 0;
}

//Average::~Average() {}

void Average::accumulate(double x) {
	average += x;
	++count;
}
	
void Average::postprocess() {
	if (count > 0) {
		average /= count;
	}
}

double Average::result() const {
	return average;
}
	
void Average::print(std::ostream &os) const {
	os << "Average = " << average;
}
