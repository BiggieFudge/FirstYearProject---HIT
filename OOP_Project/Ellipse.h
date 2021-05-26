#pragma once
#include "Circle.h"

class ellipse :public Circle
{
public:
    DECLARE_SERIAL(ellipse);

    ellipse();
    ellipse(POINT p1,POINT p2,POINT* arr_p);
    ellipse(const ellipse&);
    ~ellipse();

    //virtual functions:
    double area();
    double perimeter();
    string type();
    //getters/setters:
    CRect get_rekt();
    POINT get_lp();
    POINT get_rp();

    void set_rekt(CRect);
    void set_lp(long,long);
    void set_rp(long,long);

    void Serialize(CArchive& archive);
private:
    POINT lp;//top left point of rectangle
    POINT rp;//bottom right point of rectangle
    POINT* Rect_point;//contains the real axis points;
    double radius1;//created just for area and perimeter
    double radius2;//created just for area and perimeter

};

