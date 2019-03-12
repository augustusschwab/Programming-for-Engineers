#pragma once
#include "statistic.h"

class Max : public Statistic {
	double max;
public:
	Max();
	//~Max();
	void accumulate(double x) override;
	void postprocess() override;
	double result() const override;
	void print(std::ostream &os) const override;
};
