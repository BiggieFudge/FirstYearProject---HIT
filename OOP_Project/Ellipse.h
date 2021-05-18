#pragma once
#include "Circle.h"
class ellipse :public Circle
{
public:
    ellipse(POINT p1,POINT p2,POINT* arr_p);
    ~ellipse();

    //virtual functions:
    double area();
    double perimeter();
    string type();
    //getters/setters:
    CRect get_rekt();
private:
    POINT lp;//top left point of rectangle
    POINT rp;//bottom right point of rectangle
    POINT* Rect_point;//contains the real axis points;

};

