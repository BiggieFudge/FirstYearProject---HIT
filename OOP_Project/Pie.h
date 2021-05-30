#pragma once
#include "Ellipse.h"

class pie : public Circle
{
public:
    DECLARE_SERIAL(pie);
    pie();
    //pie(POINT p1,POINT p2,POINT* arr_p,POINT p3,POINT p4,POINT* arr_a);
    pie(POINT center, POINT* rect_points, double radius, POINT p3, POINT p4, POINT* arr_a);
    ~pie();
    double area();
    double perimeter();
    string type();
    POINT* get_angle_point();
    POINT get_start_angle();
    POINT get_end_angle();
    void Serialize(CArchive& archive);
    POINT get_lp();
    POINT get_rp();

    double create_angle();
    double get_angle();

private:
    double angle;
    POINT start_angle;//start of angle
    POINT end_angle;//end of angle
    POINT* Angle_point;//contains the grid angle points;

    double b, c;//length of center to points of starting angle
};

