#ifndef GUARD_IIIPoint_h
#define GUARD_IIIPoint_h

#include<iostream>

class Point {
public:
	double x;
	double y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}

	friend std::ostream& operator <<(std::ostream& sout, Point p);
	bool operator ==(Point s) {
		return (x == s.x&&y == s.y);
	}
};

std::ostream& operator <<(std::ostream& sout, Point p) {
	sout << "(" << p.x << ", " << p.y << ")";
	return sout;
}

#endif