#include "pch.h"
#include "Circle.h"


Circle::Circle()
{
   radius=NULL;
   radiusReal=NULL;
   center.x=NULL;
   center.y = NULL;
   RectPoint=NULL;
}

Circle::Circle(POINT p,POINT* p_c,double r)
{
    //cout << "enter radious of circle:" << endl;
    //cin >> radious;
    //while (radious < 0)
    //{
    //    cout << "enter only non negetive values into radious:" << endl;
    //    cout << "enter radious of circle:" << endl;
    //    cin >> radious;
    //}
    //cout << "enter center of circle:" << endl;
    //center.input_point();
    center.x = p.x;
    center.y = p.y;
    RectPoint = new POINT[2];
    RectPoint[0].x = p_c[0].x;
    RectPoint[0].y = p_c[0].y;
    RectPoint[1].x = p_c[1].x;
    RectPoint[1].y = p_c[1].y;
    radius = r;
    radiusReal = r * 40;   //Change if change SquareSide
}

Circle::~Circle()
{
    delete[] RectPoint;
}

double Circle::area()
{
    return(3.1415 * radius * radius);
}

double Circle::perimeter()
{
    return(3.1415 * radius * 2);
}

//void Circle::print()
//{
//    cout << "center point is:";
//    center.print();
//    cout << endl;
//    cout << "radious is:" << radius << endl;
//}

string Circle::type()
{
    return("CircleC");
}
//getters and setters

double Circle::get_radius()
{
    return(radius);
}

double Circle::get_radius_real()
{
    return radiusReal;
}

void Circle::set_radious(double r)
{
    if (r >= 0)
    {
        radius = r;
    }
    else
    {
        cout << "radious can only be non negetive value!" << endl;//need to change to message
    }
}

CRect Circle::get_rekt()
{
    
    return(CRect(this->RectPoint[0].x, this->RectPoint[0].y, this->RectPoint[1].x, this->RectPoint[1].y));
}

POINT Circle::get_center()
{
    return(center);
}

void Circle::set_center(POINT p)
{
    center.x = p.x;
    center.y = p.y;
}