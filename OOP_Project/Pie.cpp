#include "pch.h"
#include "Pie.h"

Pie::Pie(POINT p1,POINT p2,POINT p3,POINT p4,POINT* arr_p,POINT* arr_a):ellipse(p1,p2,arr_p)
{
    start_angle=p3;
    end_angle = p4;
    Angle_point=new POINT[2];
    Angle_point[0].x = arr_a[0].x;
    Angle_point[0].y = arr_a[0].y;
    Angle_point[1].x = arr_a[1].x;
    Angle_point[1].y = arr_a[1].y;
}

Pie::~Pie()
{
    delete[] Angle_point;
}

double Pie::area()
{
    return(3);
}

double Pie::perimeter()
{
    return(3);
}
    
string Pie::type()
{
     return("CircleP");
}
    
POINT* Pie::get_angle_point()
{
    return(Angle_point);
}