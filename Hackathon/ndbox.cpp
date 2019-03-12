// Augustus Schwab
// Hackaton - ME EN 5250
// Due: 11/4/15
// Problem 0 - N-D Box
// 
// This program contains a class for the manipulation of axis aligned
// boxes in several dimensions.

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>


class range {
private:
	// Choose your way to store the information on a range.
	// Note that you need to be able to store an empty range
	// (a range with no min nor max).
	double min;
	double max;
public:
	// Interface for the class. You need to properly implement
	// the following methods
	// Constructor: create an empty range
	// (carefully choose the representation for an empty range)
	range() {
		min = std::numeric_limits<double>::max();
		max = std::numeric_limits<double>::min();
	}
	// Constructor: range of a given size centered around 0
	range(double size) {
		min = 0 - (size / 2);
		max = 0 + (size / 2);
	}
	// Constructor from a given min and max (note that the range passed could be empty)
	range(double min, double max)
		: min(min)
		, max(max)
	{
		if (this->is_empty()) range();
	}
	// Copy constructor
	range(const range &a) : min(a.min), max(a.max) {}
	// Test if the range is empty
	// (depends on how you define an empty range)
	bool is_empty() const {
		if (max >= min) return false;
		else return true;
	}
	// Get the min of the range
	double get_min() const {
		return min;
	}
	// Get the max of the range
	double get_max() const {
		return max;
	}
	// Assignment operator
	range& operator=(const range &rhs);
	// Normalized union of ranges (normalization fills
	// a possible gap in the range)
	range operator+(const range &rhs) const;
	// Normalized difference of ranges (normalization fills
	// a possible gap in the range)
	range operator-(const range &rhs) const;
	// Normalized intersection of ranges (normalization fills
	// a possible gap in the range)
	range operator&(const range &rhs) const;
};
range& range::operator=(const range &rhs) 
{
	max = rhs.get_max();
	min = rhs.get_min();
	return *this;
}
// Normalized union of ranges (normalization fills
// a possible gap in the range)
range range::operator+(const range &rhs) const
{
	if (this->is_empty()) return range(rhs);
	if (rhs.is_empty()) return range(*this);
	return range(std::min(this->get_min(), rhs.get_min()),
		std::max(this->get_max(), rhs.get_max()));
}
range range::operator-(const range &rhs)const
{
	if (this->is_empty()) return range();
	if (rhs.is_empty()) return range(*this);
	if (rhs.get_max() > this->get_min() && rhs.get_min() <= this->get_min() && rhs.get_max() < this->get_max())
		return range(rhs.get_max(), this->get_max());
	if (rhs.get_min() < this->get_max() && rhs.get_max() >= this->get_max() && rhs.get_min() > this->get_min())
		return range(this->get_min(), rhs.get_min());
	if (rhs.get_min() > this->get_min() && rhs.get_max() < this->get_max())
		return range(*this);
	if (rhs.get_min() < this->get_min() && rhs.get_max() >= this->get_max() ||
		rhs.get_min() > this->get_min() && rhs.get_max() <= this->get_max()	||
		rhs.get_min() == this->get_min() && rhs.get_max() == this->get_max()||
		rhs.get_min() == this->get_min() && rhs.get_max() > this->get_max())
		return range();
	else return range(*this);
}

range range::operator&(const range &rhs)const
{
	if (this->is_empty()) return range();
	if (rhs.is_empty()) return range();
	if (rhs.get_max() > this->get_min() && rhs.get_min() < this->get_min() && rhs.get_max() <= this->get_max())
		return range(this->get_min(), rhs.get_max());
	if (rhs.get_min() < this->get_max() && rhs.get_max() > this->get_max() && rhs.get_min() >= this->get_min())
		return range(rhs.get_min(), this->get_max());
	if (rhs.get_min() > this->get_min() && rhs.get_max() <= this->get_max())
		return range(rhs);
	if (rhs.get_max() == this->get_min())
		return range(rhs.get_max(), this->get_min());
	if (rhs.get_min() == this->get_max())
		return range(rhs.get_min(), this->get_max());
	if (rhs.get_min() < this->get_min() && rhs.get_max() > this->get_max())
		return range(*this);
	if (rhs.get_min() == this->get_min() && rhs.get_max() == this->get_max())
		return range(*this);
	else return range();
}

class nd_box {
private:
	int dim = 0;
	range* dims = nullptr;
public:
	// Create an empty box
	nd_box() { };
	// Copy constructor
	nd_box(const nd_box &a)
		: dim(a.dim)
		, dims(new range[dim])
	{
		for (int i = 0; i < dim; ++i) {
			dims[i] = a.dims[i];
		}
	}
	// Constructor for 1D ranges
	nd_box(const range &a)
		: dim(1)
		, dims(new range[dim])
	{
		dims[0] = a;
	}
	// Constructor for rectangles
	nd_box(const range &a, const range &b)
		: dim(2)
		, dims(new range[dim])
	{
		dims[0] = a;
		dims[1] = b;
	}
	// Constructor for 3D rectangular boxes
	nd_box(const range &a, const range &b, const range &c)
		: dim(3)
		, dims(new range[dim])
	{
		dims[0] = a;
		dims[1] = b;
		dims[2] = c;
	}
	// Constructor for 4D boxes
	nd_box(const range &a, const range &b, const range &c,
		const range &d)
		: dim(4)
		, dims(new range[dim])
	{
		dims[0] = a;
		dims[1] = b;
		dims[2] = c;
		dims[3] = d;
	}
	// Destructor, should free the ranges you've allocated
	~nd_box()
	{
		delete[] dims;
	}
	bool is_empty() const 
	{
		bool result = false;
		for (int i = 0; i < dim; ++i) {
			if (dims[i].is_empty()) {
				result = true;
				break;
			}
			else result = false;
		}
		return result;
	}
	// Get the dimension of the range
	double get_dim() const {
		return dim;
	}
	// Assignment operator
	nd_box& operator=(const nd_box &rhs);
	// Normalized union of boxes
	nd_box operator+(const nd_box &rhs) const;
	// Normalized difference of boxes
	nd_box operator-(const nd_box &rhs) const;
	// Normalized intersection of boxes
	nd_box operator&(const nd_box &rhs) const;
	// Returns reference to i-th range
	const range& operator[](int i) const;
	// Returns reference to i-th range
	range& operator[](int i);
};
nd_box& nd_box::operator=(const nd_box &rhs)
{
	assert(this->dim == rhs.dim);
	for (int i = 0; i < this->dim; ++i)
		dims[i] = rhs.dims[i];
	return *this;
}
// Normalized union of ranges (normalization fills
// a possible gap in the range)
nd_box nd_box::operator+(const nd_box &rhs) const
{
	assert(this->dim == rhs.dim);
	nd_box result(rhs);
	for (int i = 0; i < this->dim; ++i)
		result.dims[i] = result.dims[i] + this->dims[i];
	return result;
}
nd_box nd_box::operator-(const nd_box &rhs) const
{
	assert(this->dim == rhs.dim);
	nd_box result(rhs);
	for (int i = 0; i < this->dim; ++i)
		result.dims[i] = this->dims[i] - result.dims[i];
	return result;
}
nd_box nd_box::operator&(const nd_box &rhs) const
{
	assert(this->dim == rhs.dim);
	nd_box result(rhs);
	for (int i = 0; i < this->dim; ++i)
		result.dims[i] = this->dims[i] & result.dims[i];
	return result;
}
const range& nd_box::operator[](int i) const
{
	//assert(this->dim <= i);
	return dims[i];
}
range& nd_box::operator[](int i)
{
	//assert(this->dim <= i);
	return dims[i];
}

std::ostream& operator<<(std::ostream& os, const range& r) 
{
	if (r.is_empty()) os << "( )";
	else os << "(" << r.get_min() << ", " << r.get_max() << ")";
	return os;
}

std::ostream& operator<<(std::ostream& os, const nd_box& b) 
{
	if (b.is_empty()) os << "[ ";
	else {
		os << "[";
		for (int i = 0; i < b.get_dim(); ++i) {
			os << b[i];
		}
	}
	os << "]";
	return os;
}

std::istream& operator>>(std::istream& is, std::vector<range>& u)
{
	int num_ranges = 0;
	is >> num_ranges;
	for (int i = 0; i < num_ranges; ++i) {
		double min = 0, max = 0;
		is >> min >> max;
		range range(min, max);
		u.push_back(range);
	}
	return is;
}

void test_range_methods(const range &r1, const range &r2) {
	std::cout << std::string(30, '*') << "\n"
		<< " r1 = " << r1 << "\n"
		<< " r2 = " << r2 << "\n"
		<< " r2 & r1 = " << (r2 & r1) << "\n"
		<< " r2 + r1 = " << (r2 + r1) << "\n"
		<< " r2 - r1 = " << (r2 - r1) << "\n"
		<< " r1 - r2 = " << (r1 - r2) << "\n";
}

void test_box_methods(const nd_box &b1, const nd_box &b2) {
	std::cout << std::string(30, '*') << "\n"
		<< " b1 = " << b1 << "\n"
		<< " b2 = " << b2 << "\n"
		<< " b2 & b1 = " << (b2 & b1) << "\n"
		<< " b2 + b1 = " << (b2 + b1) << "\n"
		<< " b2 - b1 = " << (b2 - b1) << "\n"
		<< " b1 - b2 = " << (b1 - b2) << "\n";
}

int main() 
{
	int num_cases = 0;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		std::vector<range> ranges;
		std::cin >> ranges;
		int num_ranges = ranges.size();
		test_range_methods(ranges[0], ranges[1]);
		if ((num_ranges / 2) == 1) {
			nd_box b1(ranges[0]);
			nd_box b2(ranges[1]);
			test_box_methods(b1, b2);
		}
		if ((num_ranges / 2) == 2) {
			nd_box b1(ranges[0], ranges[1]);
			nd_box b2(ranges[2], ranges[3]);
			test_box_methods(b1, b2);
		}
		if ((num_ranges / 2) == 3) {
			nd_box b1(ranges[0], ranges[1], ranges[2]);
			nd_box b2(ranges[3], ranges[4], ranges[5]);
			test_box_methods(b1, b2);
		}
		if ((num_ranges / 2) == 4) {
			nd_box b1(ranges[0], ranges[1], ranges[2], ranges[3]);
			nd_box b2(ranges[4], ranges[5], ranges[6], ranges[7]);
			test_box_methods(b1, b2);
		}
	}
	return 0;
}