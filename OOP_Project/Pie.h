#pragma once
#include "Ellipse.h"
class pie : public ellipse
{
public:
    pie(POINT p1,POINT p2,POINT* arr_p,POINT p3,POINT p4,POINT* arr_a);
    ~pie();
    double area();
    double perimeter();
    string type();
    POINT* get_angle_point();
private:
    POINT start_angle;//start of angle
    POINT end_angle;//end of angle
    POINT* Angle_point;//contains the real angle points;
};

