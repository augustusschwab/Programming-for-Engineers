#pragma once
#include "statistic.h"

class Min : public Statistic {
	double min;
public:
	Min();
	//~Min();
	void accumulate(double x) override;
	void postprocess() override;
	double result() const override;
	void print(std::ostream &os) const override;
};
