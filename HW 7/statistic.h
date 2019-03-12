#pragma once
#include <iostream>
#include <algorithm>
#include <limits>

class Statistic {
public:
	virtual ~Statistic();
	virtual void accumulate(double x) = 0;
	virtual void postprocess() = 0;
	virtual double result() const = 0;
	virtual void print(std::ostream &os) const = 0;
};