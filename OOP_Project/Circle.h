#pragma once
#include "Shape.h"

class Circle :public Shape
{
public:
    Circle();
    ~Circle();

    //virtual functions:
    double area();
    double perimeter();
    void print();
    string type();
    //getters/setters:
    double get_radious();
    void set_radious(double);
    Point get_center();
    void set_center(Point);
private:
    double radious;
    Point center;
};


