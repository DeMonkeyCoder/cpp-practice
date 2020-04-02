#ifndef GUARD_IIIGeometry_h
#define GUARD_IIIGeometry_h

#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include"IIIGeometry.h"
#include"IIIPoint.h"
#include"IIIMatrix.h"
#include"IIIErrorHandling.h"

class Shape;
class Triangle;
class Rectangle;
class Square;
class Circle;
class Factory;

bool AreaCompare(Shape *a, Shape *b);

class Shape {
public:
	virtual void draw() = 0;
	virtual double getArea() = 0;
};

class Triangle :public Shape {
protected:
	Point leftCorner;
	Point rightCorner;
	Point upside;
	Triangle(Point l, Point r, Point u) :leftCorner(l), rightCorner(r), upside(u) {}
	friend class Factory;
public:
	void draw() {
		std::cout << "Im a Triangle :)" << std::endl
			<< "my left corner is " << leftCorner << std::endl
			<< "my right corner is " << rightCorner << std::endl
			<< "my upside is " << upside << std::endl;
	}

	double getArea() {
		double myMatrix[matrixSize][matrixSize] = { { leftCorner.x,rightCorner.x,upside.x },
		{ leftCorner.y,rightCorner.y,upside.y },
		{ 1,   1,   1 } };
		return 0.5*det(3, myMatrix, 0);
	}
};

class Rectangle :public Shape {
protected:
	Point width;
	Point height;
	Rectangle(Point w, Point h) :width(w), height(h) {}
	friend class Factory;
public:
	void draw() {
		std::cout << "Im a Rectangle :)" << std::endl
			<< "my downside left corner is " << width << std::endl
			<< "my upside right corner is " << height << std::endl;
	}

	double getArea() {
		return (height.x - width.x) * (height.y - width.y);
	}
};

class Square :public Shape {
protected:
	Point width;
	Point height;
	Square(Point w, Point h) :width(w), height(h) {}
	friend class Factory;
public:
	void draw() {
		std::cout << "Im a Square :)" << std::endl
			<< "my downside left corner is " << width << std::endl
			<< "my upside right corner is " << height << std::endl;
	}
	double getArea() {
		return (height.x - width.x) * (height.y - width.y);
	}
};

class Circle :public Shape {
protected:
	Point first;
	Point second;
	Point third;
	Circle(Point f, Point s, Point t) :first(f), second(s), third(t) {}
	friend class Factory;
public:
	void draw() {
		double matrix11[matrixSize][matrixSize] = { { first.x, first.y, 1 } ,
		{ second.x, second.y, 1 },
		{ third.x, third.y, 1 } };

		double matrix12[matrixSize][matrixSize] = { { pow(first.x,2) + pow(first.y,2), first.y, 1 } ,
		{ pow(second.x,2) + pow(second.y,2), second.y, 1 },
		{ pow(third.x,2) + pow(third.y,2), third.y, 1 } };

		double matrix13[matrixSize][matrixSize] = { { pow(first.x,2) + pow(first.y,2), first.x, 1 } ,
		{ pow(second.x,2) + pow(second.y,2), second.x, 1 },
		{ pow(third.x,2) + pow(third.y,2), third.x, 1 } };

		double matrix14[matrixSize][matrixSize] = { { pow(first.x,2) + pow(first.y,2), first.x, first.y } ,
		{ pow(second.x,2) + pow(second.y,2), second.x, second.y },
		{ pow(third.x,2) + pow(third.y,2), third.x, third.y } };

		double centerX = 0.5*det(3, matrix12, 0) / det(3, matrix11, 0);
		double centerY = -0.5*det(3, matrix13, 0) / det(3, matrix11, 0);
		double r = sqrt(pow(centerX, 2) + pow(centerY, 2) + det(3, matrix14, 0) / det(3, matrix11, 0));

		std::cout << "I am a Circle :)" << std::endl
			<< "my radious is " << r << std::endl
			<< "My center is " << Point(centerX, centerY) << std::endl;
	}

	double getArea() {
		double matrix11[matrixSize][matrixSize] = { { first.x, first.y, 1 } ,
		{ second.x, second.y, 1 },
		{ third.x, third.y, 1 } };

		double matrix12[matrixSize][matrixSize] = { { pow(first.x,2) + pow(first.y,2), first.y, 1 } ,
		{ pow(second.x,2) + pow(second.y,2), second.y, 1 },
		{ pow(third.x,2) + pow(third.y,2), third.y, 1 } };

		double matrix13[matrixSize][matrixSize] = { { pow(first.x,2) + pow(first.y,2), first.x, 1 } ,
		{ pow(second.x,2) + pow(second.y,2), second.x, 1 },
		{ pow(third.x,2) + pow(third.y,2), third.x, 1 } };

		double matrix14[matrixSize][matrixSize] = { { pow(first.x,2) + pow(first.y,2), first.x, first.y } ,
		{ pow(second.x,2) + pow(second.y,2), second.x, second.y },
		{ pow(third.x,2) + pow(third.y,2), third.x, third.y } };

		double centerX = 0.5*det(3, matrix12, 0) / det(3, matrix11, 0);
		double centerY = -0.5*det(3, matrix13, 0) / det(3, matrix11, 0);
		double r = sqrt(pow(centerX, 2) + pow(centerY, 2) + det(3, matrix14, 0) / det(3, matrix11, 0));
		return 3.14*pow(r, 2);
	}
};

class Factory {
private:
	std::map<std::string, std::vector<Shape *> > DB;
public:
	void addTriangle(Point leftCorner, Point rightCorner, Point upside) {
		if (leftCorner.x >= rightCorner.x ||
			leftCorner.y >= upside.y ||
			rightCorner.y >= upside.y) {
			NotATriangleException e;
			throw e;
		}
		DB["Triangle"].push_back(new Triangle(leftCorner, rightCorner, upside));
	}
	void addRectangle(Point width, Point height) {
		if (width.x >= height.x ||
			width.y >= height.y) {
			NotARectangleException e;
			throw e;
		}
		DB["Rectangle"].push_back(new Rectangle(width, height));
	}
	void addSquare(Point width, Point height) {
		if (width.x >= height.x ||
			width.y >= height.y ||
			height.x - width.x != height.y - width.y) {
			NotASquareException e;
			throw e;
		}
		DB["Square"].push_back(new Square(width, height));
	}
	void addCircle(Point first, Point second, Point third) {
		if ((second.y - first.y) / (second.x - first.x) == (third.y - second.y) / (third.x - second.x)) {
			NotACircleException e;
			throw e;
		}
		DB["Circle"].push_back(new Circle(first, second, third));
	}




	Shape *findTriangle(Point leftCorner, Point rightCorner, Point upside) {
		for (std::vector<Shape *>::iterator it = DB["Triangle"].begin(); it != DB["Triangle"].end(); it++) {
			if (
				((Triangle *)*it)->leftCorner == leftCorner &&
				((Triangle *)*it)->rightCorner == rightCorner &&
				((Triangle *)*it)->upside == upside
				)
				return *it;
		}
		return NULL;
	}
	Shape *findRectangle(Point width, Point height) {
		for (std::vector<Shape *>::iterator it = DB["Rectangle"].begin(); it != DB["Rectangle"].end(); it++) {
			if (
				((Rectangle *)*it)->width == width &&
				((Rectangle *)*it)->height == height
				)
				return *it;
		}
		return NULL;
	}
	Shape *findSquare(Point width, Point height) {
		for (std::vector<Shape *>::iterator it = DB["Square"].begin(); it != DB["Square"].end(); it++) {
			if (
				((Square *)*it)->width == width &&
				((Square *)*it)->height == height
				)
				return *it;
		}
		return NULL;
	}
	Shape *findCircle(Point first, Point second, Point third) {
		for (std::vector<Shape *>::iterator it = DB["Circle"].begin(); it != DB["Circle"].end(); it++) {
			if (
				((Circle *)*it)->first == first &&
				((Circle *)*it)->second == second &&
				((Circle *)*it)->third == third
				)
				return *it;
		}
		return NULL;
	}




	bool deleteTriangle(Point leftCorner, Point rightCorner, Point upside) {
		for (std::vector<Shape *>::iterator it = DB["Triangle"].begin(); it != DB["Triangle"].end(); it++) {
			if (
				((Triangle *)*it)->leftCorner == leftCorner &&
				((Triangle *)*it)->rightCorner == rightCorner &&
				((Triangle *)*it)->upside == upside
				) {
				DB["Triangle"].erase(it); // care if we don't return then cannot loop cause iterators will be destructed after erase
				return 1;
			}
		}
		return 0;
	}
	bool deleteRectangle(Point width, Point height) {
		for (std::vector<Shape *>::iterator it = DB["Rectangle"].begin(); it != DB["Rectangle"].end(); it++) {
			if (
				((Rectangle *)*it)->width == width &&
				((Rectangle *)*it)->height == height
				) {
				DB["Rectangle"].erase(it);
				return 1; // care if we don't return then cannot loop cause iterators will be destructed after erase
			}
		}
		return 0;
	}
	bool deleteSquare(Point width, Point height) {
		for (std::vector<Shape *>::iterator it = DB["Square"].begin(); it != DB["Square"].end(); it++) {
			if (
				((Square *)*it)->width == width &&
				((Square *)*it)->height == height
				) {
				DB["Square"].erase(it);
				return 1; // care if we don't return then cannot loop cause iterators will be destructed after erase
			}
		}
		return 0;
	}
	bool deleteCircle(Point first, Point second, Point third) {
		for (std::vector<Shape *>::iterator it = DB["Circle"].begin(); it != DB["Circle"].end(); it++) {
			if (
				((Circle *)*it)->first == first &&
				((Circle *)*it)->second == second &&
				((Circle *)*it)->third == third
				) {
				DB["Circle"].erase(it);
				return 1;
			}
		}
		return 0;
	}




	void sortDatabaseTriangles() {
		sort(DB["Triangle"].begin(), DB["Triangle"].end(), AreaCompare);
	}
	void sortDatabaseRectangles() {
		sort(DB["Rectangle"].begin(), DB["Rectangle"].end(), AreaCompare);
	}
	void sortDatabaseSquares() {
		sort(DB["Square"].begin(), DB["Square"].end(), AreaCompare);
	}
	void sortDatabaseCircles() {
		sort(DB["Circle"].begin(), DB["Circle"].end(), AreaCompare);
	}
	std::vector<Shape *> sortAll() {
		std::vector<Shape *> v;
		for (std::map<std::string, std::vector<Shape *> >::iterator it = DB.begin(); it != DB.end(); it++)
			v.insert(v.end(), it->second.begin(), it->second.end());
		sort(v.begin(), v.end(), AreaCompare);
		return v;
	}
};

bool AreaCompare(Shape *a, Shape *b) {
	return a->getArea() < b->getArea();
}


#endif