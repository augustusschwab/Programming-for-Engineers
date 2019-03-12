// Augustus Schwab
// HW 6 - ME EN 5250
// Due: 10/30/15
// Problem 0 - n-Dimensional Vector
// 
// This program contains a class which allows the user to work
// with vectors in c++.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class nd_vector
{
private:
	int dimension_ = 0;
	double* elements_ = nullptr;
public:
	// create a default vector
	nd_vector() { }
	// if dimension = 3 and val = 2, create the vector [2, 2, 2]
	nd_vector(int dimension, double val)
		: dimension_(dimension)
		, elements_(new double[dimension])
	{
		for (int i = 0; i < dimension_; ++i) {
			elements_[i] = val;
		}
	}
	// copy constructor, create an nd_vector from another
	nd_vector(const nd_vector& other)
		: dimension_(other.dimension_)
		, elements_(new double[other.dimension_])
	{
		for (int i = 0; i < dimension_; ++i) {
			elements_[i] = other.elements_[i];
		}
	}
	// assignment operator
	nd_vector& operator=(const nd_vector& other)
	{
		if (this != &other) {
			dimension_ = other.dimension_;
			delete[] elements_;
			elements_ = new double[dimension_];
			for (int i = 0; i < dimension_; ++i) {
				elements_[i] = other.elements_[i];
			}
		}
		return *this;
	}
	// de-allocate any allocated memory
	~nd_vector() {
		delete[] elements_;
	}
	// return the dimension of the vector
	int dimension() const { 
		return dimension_;
	}
	// return a const reference to the ith element of the vector
	const double& operator[](int i) const
	{
		assert(i >= 0 && i < dimension());
		return elements_[i];
	}
	// return a reference to the ith element of the vector
	double& operator[](int i)
	{
		assert(i >= 0 && i < dimension());
		return elements_[i];
	}
};
// return u + v
nd_vector operator+(const nd_vector& u, const nd_vector& v)
{
	assert(u.dimension() == v.dimension());
	nd_vector result(u.dimension(), 0);
	for (int i = 0; i < u.dimension(); ++i) {
		result[i] = u[i] + v[i];
	}
	return result;
}
// return u - v
nd_vector operator-(const nd_vector& u, const nd_vector& v) 
{
	assert(u.dimension() == v.dimension());
	nd_vector result(u.dimension(), 0);
	for (int i = 0; i < u.dimension(); ++i) {
		result[i] = u[i] - v[i];
	}
	return result;
}
// return u * v (element wise)
nd_vector operator*(const nd_vector& u, const nd_vector& v)
{
	assert(u.dimension() == v.dimension());
	nd_vector result(u.dimension(), 0);
	for (int i = 0; i < u.dimension(); ++i) {
		result[i] = u[i] * v[i];
	}
	return result;
}
// return u / v (element wise)
nd_vector operator/(const nd_vector& u, const nd_vector& v) 
{
	assert(u.dimension() == v.dimension());
	nd_vector result(u.dimension(), 0);
	for (int i = 0; i < u.dimension(); ++i) {
		result[i] = u[i] / v[i];
	}
	return result;
}
// return u * x
nd_vector operator*(const nd_vector& u, double x)
{
	nd_vector result(u.dimension(), 0);
	for (int i = 0; i < u.dimension(); ++i) {
		result[i] = u[i] * x;
	}
	return result;
}
// return x * u
nd_vector operator*(double x, const nd_vector& u) 
{
	nd_vector result(u.dimension(), 0);
	for (int i = 0; i < u.dimension(); ++i) {
		result[i] = x * u[i];
	}
	return result;
}
// return u / x
nd_vector operator/(const nd_vector& u, double x) 
{
	nd_vector result(u.dimension(), 0);
	for (int i = 0; i < u.dimension(); ++i) {
		result[i] = u[i] / x;
	}
	return result;
}
// u = u + v
nd_vector& operator+=(nd_vector& u, const nd_vector& v)
{
	assert(u.dimension() == v.dimension());
	for (int i = 0; i < u.dimension(); ++i) {
		u[i] += v[i];
	}
	return u;
}
// u = u - v
nd_vector& operator-=(nd_vector& u, const nd_vector& v) 
{
	assert(u.dimension() == v.dimension());
	for (int i = 0; i < u.dimension(); ++i) {
		u[i] -= v[i];
	}
	return u;
}
// u = u * v
nd_vector& operator*=(nd_vector& u, const nd_vector& v)
{
	assert(u.dimension() == v.dimension());
	for (int i = 0; i < u.dimension(); ++i) {
		u[i] *= v[i];
	}
	return u;
}
// u = u / v
nd_vector& operator/=(nd_vector& u, const nd_vector& v) 
{
	assert(u.dimension() == v.dimension());
	for (int i = 0; i < u.dimension(); ++i) {
		u[i] /= v[i];
	}
	return u;
}
// u = u * x
nd_vector& operator*=(nd_vector& u, double x)
{
	for (int i = 0; i < u.dimension(); ++i) {
		u[i] *= x;
	}
	return u;
}
// u = u / x
nd_vector& operator/=(nd_vector& u, double x) 
{
	for (int i = 0; i < u.dimension(); ++i) {
		u[i] /= x;
	}
	return u;
}
// return -u
nd_vector operator-(const nd_vector& u) { return u * -1.0; }
// return u == v
bool operator==(const nd_vector& u, const nd_vector& v) 
{	
	bool result = true;
	assert(u.dimension() == v.dimension());
	for (int i = 0; i < u.dimension(); ++i) {
		if (u[i] != v[i]) { result = false; }
	}
	return result;
}
// return u != v
bool operator!=(const nd_vector& u, const nd_vector& v) { return !(u == v); }
// dot product
double dot(const nd_vector& u, const nd_vector& v) 
{
	assert(u.dimension() == v.dimension());
	double result = 0;
	for (int i = 0; i < u.dimension(); ++i) {
		result += (u[i] * v[i]);
	}
	return result;
}
// 2-norm (e.g. norm([3, 4]) = sqrt(3 * 3 + 4 * 4))
double norm(const nd_vector& u)
{
	return sqrt(dot(u, u));
}
// return the normalized vector
nd_vector normalize(const nd_vector& u)
{
	double l = norm(u);
	return l > 0 ? (u / l) : u;
}
// if u and v are 3D vectors, return the cross product u × v
nd_vector cross(const nd_vector& u, const nd_vector& v) 
{
	assert(u.dimension() == 3 && v.dimension() == 3);
	nd_vector result(u.dimension(), 0);
	result[0] = (u[1] * v[2]) - (u[2] * v[1]);
	result[1] = (u[2] * v[0]) - (u[0] * v[2]);
	result[2] = (u[0] * v[1]) - (u[1] * v[0]);
	return result;
}
// return true if u and v are orthogonal (i.e. dot(u, v) == 0)
bool is_orthogonal(const nd_vector& u, const nd_vector& v) 
{ 
	return dot(u, v) == 0;
}
// write u to an output stream
ostream& operator<<(ostream& is, nd_vector& u) 
{ 
	is << "(";
	for (int i = 0; i < u.dimension(); ++i) {
		is << u[i] << " ";
	}
	is << ")";
	return is;
}
// read u from an input stream
istream& operator>>(istream& is, nd_vector& u)
{
	is.ignore(numeric_limits<streamsize>::max(), '(');
	vector<double> elems;
	while (is.peek() != ')') {
		double e = 0;
		is >> e;
		elems.push_back(e);
	}
	char c = static_cast<char>(is.get());
	assert(c == ')');
	u = nd_vector(static_cast<int>(elems.size()), 0);
	for (int i = 0; i < u.dimension(); ++i) {
		u[i] = elems[i];
	}
	return is;
}
int main()
{
	int num_cases = 0;
	cin >> num_cases;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = 0; i < num_cases; ++i) {
		nd_vector u, v;
		double x = 0;
		cin >> u >> v >> x;
		cout << "Case " << i << ":\n";
		cout << boolalpha;
		cout << (u == v) << " " << is_orthogonal(u, v) << "\n";
		u *= x;
		v /= x;
		u /= (v + u);
		v *= (u + v);
		u = -v * u;
		v = v / (u + v);
		u *= norm(v);
		v /= norm(u);
		if (u.dimension() == 3 && v.dimension() == 3)
			cout << cross(u, v) * dot(normalize(u), normalize(v)) << "\n";
		else
			cout << u * dot(normalize(u), normalize(v)) << "\n";
	}
	return 0;
}