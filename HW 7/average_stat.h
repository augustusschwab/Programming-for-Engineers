#pragma once
#include "statistic.h"

class Average : public Statistic {
	double average;
	size_t count;
public:
	Average();
	//~Average();
	void accumulate(double x) override;
	void postprocess() override;
	double result() const override;
	void print(std::ostream &os) const override;
};
