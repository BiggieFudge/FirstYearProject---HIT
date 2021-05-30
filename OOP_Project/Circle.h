#pragma once

#include "Shape.h"

#define PI 3.1415

class Circle 
    :public Shape{
    
public:
    DECLARE_SERIAL(Circle);

    //Constrctor
    Circle();
    Circle(POINT,POINT* ,double radius);
    Circle(const Circle&);
    ~Circle();
    void Serialize(CArchive& archive);


    //virtual functions:
    double area();

    double perimeter();

    string type();


    //getters/setters:
    double get_radius();
    double get_radius_real();
    CRect get_rekt();
    POINT get_center();

    void set_center(POINT);

    void set_rekt(CRect);

    void set_radious(double);



 
private:

    double radius;//radius according to xy map

    double radiusReal;//radius according to grid map

    POINT center;//center of circle

    POINT* RectPoint;//edge points of rectangle outside of circle object 


  
    
};


