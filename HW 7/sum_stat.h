#pragma once
#include "statistic.h"

class Sum : public Statistic {
	double sum;
public:
	Sum();
	//~Sum();
	void accumulate(double x) override;
	void postprocess() override;
	double result() const override;
	void print(std::ostream &os) const override;
};