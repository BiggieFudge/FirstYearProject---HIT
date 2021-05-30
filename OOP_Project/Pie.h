#pragma once
#include "Ellipse.h"

class pie : public Circle
{
public:
    DECLARE_SERIAL(pie);
    
    //Constctor
    pie();
    pie(POINT center, POINT* rect_points, double radius, POINT p3, POINT p4, POINT* arr_a);
    ~pie();
    void Serialize(CArchive& archive);


    //Virtual functions
    double area();
    double perimeter();
    string type();

    //Getters / Setters
    POINT* get_angle_point();
    POINT get_start_angle();
    POINT get_end_angle();
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

