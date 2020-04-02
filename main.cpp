#include <iostream>
#include "string"
#include "vector"
#include "math.h"
using namespace std;
class Shape;
class rect;
class Right_triangle;
class circle;
class square;
class  Shape{
public:
    virtual double surface()=0;
    virtual  void draw()=0;
};

class ListShape{
protected:

    vector<Shape*>list_of_shape;
public:
    ListShape(){}
    Shape* find(double S){
        for (auto i=list_of_shape.begin(); i <list_of_shape.end() ; i++) {
            if ((*i)->surface()==S) {
                return *i;
            }
        }
        cout<<"Not Found."<<endl;
        return nullptr;
    }
    void add(Shape& a){
        list_of_shape.push_back(&a);

    }
       void remove(Shape* a){
           for (auto i=list_of_shape.begin(); i <list_of_shape.end() ; i++) {
               if ((*i)==a) {
                   list_of_shape.erase(i);
               }}


    }
    Shape* find(Shape* a){
        for (auto i=list_of_shape.begin(); i <list_of_shape.end() ; i++) {
            if ((*i)==a) {
                return *i;
            }
        }
        cout<<"Not Found."<<endl;
        return nullptr;
    }
   void print(){
       for (auto i=list_of_shape.begin(); i <list_of_shape.end() ; i++) {
           (*i)->draw();
                   cout<<endl;
           }

    }
  void sort(){
      for (auto i=list_of_shape.begin(); i <list_of_shape.end() ; i++) {
          for (auto j=i+1 ;  j< list_of_shape.end(); j++) {
              if ((*i)->surface()>(*j)->surface()) {
                  Shape* temp=*i;
                  *i=*j;
                  *j=temp;

          }

          }
      }
    }
};

class rect:public  Shape,public ListShape{
    int x,y,s;
public:
    void draw(){
        cout<<"I am a rectangle with leghnt and  width ("<<x<<","<<y<<") "<< "with surface "<< s<<endl;
    }
    rect(int X,int Y){x=X;
    y=Y;
    s=X*Y;}


    double surface(){
        return s;

    }


};
class Right_triangle:public Shape,public ListShape{
    int a,b;
    double s;
public:
    void draw(){
        cout<<"I am a Right triangle with leghnt and height "<<"("<<a<<","<<b <<") "<< "with surface "<< s<<endl;
    }


    Right_triangle(int aa,int bb){a=aa;
    b=bb;
    s=(double)a*b/2;}
    double surface() {
        return s;
    }};
class square:public Shape,public ListShape{
    int a,s;
public:
    void draw(){
        cout<<"I am a square with leghnt "<<a<< " "<< "with surface "<< s<<endl;
    }


    square(int A){a=A;s=A*A;}
    double surface(){
        return s;}
};
class circle:public Shape,public ListShape{
    int r;
    double s;
public:
    void draw(){
        cout<<"I am a circle with radius "<<r<< " "<< "with surface "<< s<<endl;
    }


    circle(int R){r=R;s=((R)*R)*(3.14);}
    double surface(){
     //   s=((r)^2)*M_PI;
        return s;
}

};

int main() {
ListShape l;
circle b(3);
Right_triangle c(3,4);
square d(4);
rect a(3,4);
l.add(b);
l.add(a);
l.add(c);
l.add(d);
l.find(6)->draw();
l.remove(&d);
l.find(16);
cout<<b.surface();
cout<<a.surface()<<endl;
cout<<l.find(&a)->surface()<<endl;
//l.print();
l.sort();
//l.print();

    return 0;
}
