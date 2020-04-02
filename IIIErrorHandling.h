#ifndef GUARD_IIIErrorHandling_h
#define GUARD_IIIErrorHandling_h

#include<string>
#include"IIIErrorHandling.h"

class NotATriangleException {
public:
	const std::string what()const throw() {
		return "Error: not a Triangle, double check\n"
			"leftCornerX<rightCornerX &&\n"
			"leftCornerY<upsideY &&\n"
			"rightCornerY<upsideY\n";
	}
};
class NotARectangleException {
public:
	const std::string what()const throw() {
		return "Error: not a Rectangle, double check\n"
			"downsideLeftCornerX<upsideRightCornerX &&\n"
			"downsideLeftCornerY<upsideRighCornerY\n";
	}
};
class NotASquareException {
public:
	const std::string what()const throw() {
		return "Error: not a Square, double check\n"
			"downsideLeftCornerX<upsideRightCornerX &&\n"
			"downsideLeftCornerY<upsideRighCornerY &&\n"
			"upsideRightCornerX-downsideLeftCornerX=upsideLeftCornerY-downsideLeftCornery\n";
	}
};
class NotACircleException {
public:
	const std::string what()const throw() {
		return "Error: not a Circle, double check "
			"whole three points are not in a line\n";
	}
};

#endif