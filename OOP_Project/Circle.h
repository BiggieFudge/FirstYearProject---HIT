#pragma once
#include "Shape.h"


class Circle :public Shape
{
public:
    Circle();
    Circle(POINT,POINT* ,double radius);
    ~Circle();

    //virtual functions:
    double area();
    double perimeter();
    //void print();
    string type();
    //getters/setters:
    double get_radius();
    double get_radius_real();
    void set_radious(double);
    CRect get_rekt();
    POINT get_center();
    void set_center(POINT);
private:
    double radius;//radius according to xy map
    double radiusReal;//radius according to grid map
    POINT center;//center of circle
 

    POINT* RectPoint;//edge points of rectangle outside of circle object 
};

