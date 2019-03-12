#pragma once
#include "statistic.h"

class Stddev : public Statistic {
	double stdDev;
	double avg;
	double avg_sq;
	double count;
public:
	Stddev();
	//~Stddev();
	void accumulate(double x) override;
	void postprocess() override;
	double result() const override;
	void print(std::ostream &os) const override;
};
