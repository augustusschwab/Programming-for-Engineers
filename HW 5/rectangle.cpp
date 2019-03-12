// Augustus Schwab
// HW 5 - ME EN 5250
// Due: 10/21/15
// Problem 1 - Rectangle
// 
// This program will simplify working with 2D rectangles through the implementation of 
// a class. The program will work with axis-aligned rectangles. It will also build upon
// a program called point since each point of the rectangle has two coordinates both 
// x and y. The x axis goes from left to right and the y axis goes from top to bottom.

#include <iostream>

struct Point
{	
	Point() {};
	Point(double x_, double y_) { 
		 x = x_;
		 y = y_;
	}
	double x;
	double y;
	
};
std::istream& operator>>(std::istream& input, Point& p)
{
	input >> p.x >> p.y;
	return input;
}
std::ostream& operator<<(std::ostream& output, Point p)
{
	output << p.x << " " << p.y;
	return output;
}


struct Rectangle
{
	// construct a default rectangle
	Rectangle() {};
	// construct a rectangle from its top-left and bottom-right points
	Rectangle(Point a, Point b) {
		TopLeft = a;
		BotRight = b;
	}

	Point p1() const; // return the top-left point
	Point p2() const; // return the bottom-right point
	double width() const; // return the width
	double height() const; // return the height
						   // return a rectangle obtained by rotating the current one
						   // 90 degrees around its center
	Rectangle rotate_90_center() const;
	// return true if p is inside the rectangle
	bool contains(Point p) const;
	//// return true if the rectangle "other" overlaps with this one
	bool overlap(Rectangle other) const;

	Point TopLeft;
	Point BotRight;
};
std::istream& operator>>(std::istream& input, Rectangle& rect) { 
	input >> rect.TopLeft >> rect.BotRight;
	return input;
}
std::ostream& operator<<(std::ostream& output, Rectangle p) { 
	output << p.TopLeft << " " << p.BotRight;
	return output;
}
//// return a tight bounding box for the two given rectangles
Rectangle bounding_box(Rectangle a, Rectangle b) {
	Rectangle BoundRect;
	BoundRect = b;
	if (a.TopLeft.x < b.TopLeft.x) {
		BoundRect.TopLeft.x = a.TopLeft.x;
	}
	if (a.BotRight.x > b.BotRight.x) {
		BoundRect.BotRight.x = a.BotRight.x;
	}
	if (a.TopLeft.y < b.TopLeft.y) {
		BoundRect.TopLeft.y = a.TopLeft.y;
	}
	if (a.BotRight.y > b.BotRight.y) {
		BoundRect.BotRight.y = a.BotRight.y;
	}

	return BoundRect;
}

Point Rectangle::p1() const {
	return TopLeft;
}

Point Rectangle::p2() const {
	return BotRight;
}

double Rectangle::width() const {
	double width = abs(BotRight.x - TopLeft.x);
	return width;
}

double Rectangle::height() const {
	double height = abs(BotRight.y - TopLeft.y);
	return height;
}

Rectangle Rectangle::rotate_90_center() const {
	Point cpt;
	cpt.x = TopLeft.x + (width() / 2);
	cpt.y = TopLeft.y + (height() / 2);

	Point TopLeft90((cpt.x - height() / 2), (cpt.y - width() / 2));
	Point BotRight90((cpt.x + height() / 2), (cpt.y + width() / 2));

	Rectangle Rect90( TopLeft90 , BotRight90 );
	return Rect90;
}

bool Rectangle::contains(Point p) const {
	if (p.x <= BotRight.x && p.x >= TopLeft.x
		&& p.y <= BotRight.y && p.y >= TopLeft.y) 
	{
		return true;
	}
	
	return false;
}

bool Rectangle::overlap(Rectangle other) const {
	if (contains(other.TopLeft) || contains(other.BotRight)) {
		return true;
	}
	if (other.contains(BotRight) || other.contains(TopLeft)) {
		return true;
	}
	return false;
}

int main() {
	int num_cases = 0;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
		'\n');

	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		Point TopLeftA;
		Point BotRightA;
		std::cin >> TopLeftA.x >> TopLeftA.y;
		std::cin >> BotRightA.x >> BotRightA.y;
		Point InsidePtA;
		std::cin >> InsidePtA.x >> InsidePtA.y;
		Rectangle RectA(TopLeftA, BotRightA);

		Point TopLeftB;
		Point BotRightB;
		std::cin >> TopLeftB.x >> TopLeftB.y;
		std::cin >> BotRightB.x >> BotRightB.y;
		Point InsidePtB;
		std::cin >> InsidePtB.x >> InsidePtB.y;
		Rectangle RectB(TopLeftB, BotRightB);

		std::cout << RectA.rotate_90_center() << " "
			<< std::boolalpha << RectA.contains(InsidePtA) << "\n";
		std::cout << RectB.rotate_90_center() << " "
			<< std::boolalpha << RectB.contains(InsidePtB) << "\n";
		std::cout << RectA.overlap(RectB) << " " 
			<< bounding_box(RectA, RectB) << "\n";

	}
	return 0;
}