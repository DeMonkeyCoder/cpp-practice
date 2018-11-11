#include<iostream>
#include "IIIGeometry.h"

using namespace std;

int main() {
	Factory myGeo;

	myGeo.addTriangle(Point(2, 3), Point(6, 3),Point(4,7));
	Shape *sp = myGeo.findTriangle(Point(2, 3), Point(6, 3),Point(4,7));
	sp->draw();
	cout << "my area is " << sp->getArea() << endl << endl;

	myGeo.addRectangle(Point(2, 3), Point(4, 4));
	Shape *sp1 = myGeo.findRectangle(Point(2, 3), Point(4, 4));
	sp1->draw();
	cout << "my area is " << sp1->getArea() << endl << endl;


	myGeo.addRectangle(Point(1, 2), Point(5, 3));
	Shape *sp2 = myGeo.findRectangle(Point(1, 2), Point(5, 3));
	sp2->draw();
	cout << "my area is " << sp2->getArea() << endl << endl;


	myGeo.sortDatabaseRectangles();


	myGeo.deleteRectangle(Point(1, 2), Point(5, 3));


	myGeo.addSquare(Point(2, 2), Point(4, 4));
	Shape *sp3 = myGeo.findSquare(Point(2, 2), Point(4, 4));
	sp3->draw();
	cout << "my area is " << sp3->getArea() << endl << endl;

	myGeo.addCircle(Point(1, 2), Point(3, 4), Point(-1, 6));
	Shape *sp4 = myGeo.findCircle(Point(1, 2), Point(3, 4), Point(-1, 6));
	sp4->draw();
	cout << "my area is " << sp4->getArea() << endl << endl;

	
	try {
		myGeo.addCircle(Point(1, 2), Point(3, 4), Point(5, 6));
	}catch(NotACircleException e){
		cout << e.what() << endl;
	}

	cout << "Sorted area of whole remained shapes" << endl;
	vector<Shape *> allGeo = myGeo.sortAll();
	for (vector<Shape *>::const_iterator it = allGeo.begin(); it != allGeo.end(); it++)
		cout << (*it)->getArea() << " ";
	cout << endl;

	return 0;
}