#include "stddev_stat.h"
#include "average_stat.h"
#include <cmath>

Stddev::Stddev() {
	stdDev = 0;
	avg = 0;
	avg_sq = 0;
	count = 0;
}

//Stddev::~Stddev() {}

void Stddev::accumulate(double x) {
	avg += x;
	avg_sq += pow(x, 2);
	++count;
}

void Stddev::postprocess() {
	if (count > 1) {
		avg /= count;
		avg_sq /= count;
		stdDev = (sqrt(count / (count - 1)) * sqrt(avg_sq - pow(avg, 2)));
	}
	else { stdDev = NAN; }
}

double Stddev::result() const {
	return stdDev;
}

void Stddev::print(std::ostream &os) const {
	if(isnan(stdDev)){ os << "StdDev = nan"; }
	else { os << "StdDev = " << stdDev; }
}
