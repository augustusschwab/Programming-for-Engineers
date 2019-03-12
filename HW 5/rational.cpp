// Augustus Schwab
// HW 5 - ME EN 5250
// Due: 10/21/15
// Problem 3 - Rational
// 
// This program will read in 4 integers from a standard input.
// The four numbers denote 2 rational numbers. It will then output
// the result of assing, subtracting, multiplying, dividing, and whether 
// the first number is less than the second one; this will occur on the first
// line. On the second line the two numbers will be printed in decimal format.

#include <iostream>
#include <exception>

class Rational
{
public:
	Rational() { };
	Rational(int n, int d) { 
		
		num = n;
		denom = d;
		if (denom == 0) {
			throw std::exception();	
		}
	}

	Rational(int n) {
		num = n;
	}

	int get_numerator() const;
	int get_denominator() const;

	void normalize();

	Rational operator+(Rational b) const;
	Rational operator-(Rational b) const;
	Rational operator*(Rational b) const;
	Rational operator/(Rational b) const;

	bool operator==(Rational b) const;
	bool operator<(Rational b) const;

	double toDecimal() const;

private:
	int num = 0; // default value is 0
	int denom = 1; // default value is 1
};

std::ostream& operator<<(std::ostream& output, Rational a) { 
	output << a.get_numerator() << "/" << a.get_denominator() << " ";
	return output;
}

int Rational::get_numerator() const {
	return num;
}

int Rational::get_denominator() const {
	return denom;
}

int GCD(int x, int y) {
	int a = x;
	int b = y;
	int old_b = 0;
	int old_a = 0;

	if (a < b) {
		old_a = a;
		a = b;
		b = old_a;
	}
	if (b != 0) {
		old_b = b;
		b = a % b;
		a = old_b;
	}

	if (b == 0) {
		return a;
	}
	else {
		return GCD(a, b);
	}
}
void Rational::normalize() {
	int norm = 1;
	if (denom < 0) {
		norm = -norm;
		denom = -denom;
	}
	if (num < 0) {
		norm = -norm;
		num = -num;
	}

	int gcd = GCD(num, denom);

	num = norm * (num / gcd);
	denom = denom / gcd;

}



Rational Rational::operator+(Rational b) const {
	Rational result;
	
	result.num = (num * b.denom) + (b.num * denom);
	result.denom = denom * b.denom;
	result.normalize();

	return result;
}

Rational Rational::operator-(Rational b) const {
	Rational result;

	result.num = (num * b.denom) - (b.num * denom);
	result.denom = denom * b.denom;
	result.normalize();

	return result;
}

Rational Rational::operator*(Rational b) const {
	Rational result;

	result.num = num * b.num;
	result.denom = denom * b.denom;
	result.normalize();

	return result;
}

Rational Rational::operator/(Rational b) const {
	Rational result;

	result.num = num * b.denom;
	result.denom = denom * b.num;
	result.normalize();
	if (result.denom == 0) {
		throw std::exception();
	}

	return result;
}

bool Rational::operator==(Rational b) const {
	if (denom == b.denom && num == b.num) {
		return true;
	}
	else {
		return false;
	}
}

bool Rational::operator<(Rational b) const {
	int result;

	result = num * b.denom - denom * b.num;
	if (result < 0)
		return true;
	else
		return false;
	
}

double Rational::toDecimal() const {
	
	double result = static_cast <double>(num) / static_cast <double>(denom);

	return result;

}

int main() {
	int num_cases = 0;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
		'\n');


	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		int numA = 0;
		int denomA = 0;
		std::cin >> numA >> denomA;
		int numB = 0;
		int denomB = 0;
		std::cin >> numB >> denomB;
		
		try {
			Rational ratA(numA, denomA);
			ratA.normalize();
			Rational ratB(numB, denomB);
			ratB.normalize();

			std::cout << ratA + ratB << " " << ratA - ratB << " "
				<< ratA * ratB << " " << ratA / ratB << " " << std::boolalpha << ratA.operator<(ratB) << "\n";
			std::cout << ratA.toDecimal() << " " << ratB.toDecimal() << "\n";
		}
		
		catch (const std::exception& e) {
			std::cout << "Division by zero" << "\n";
		}
	}
	return 0;
}