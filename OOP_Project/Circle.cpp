#include "pch.h"
#include "Circle.h"

Circle::Circle()
{
    cout << "enter radious of circle:" << endl;
    cin >> radious;
    while (radious < 0)
    {
        cout << "enter only non negetive values into radious:" << endl;
        cout << "enter radious of circle:" << endl;
        cin >> radious;
    }
    cout << "enter center of circle:" << endl;
    center.input_point();
}

Circle::~Circle()
{

}

double Circle::area()
{
    return(3.1415 * radious * radious);
}

double Circle::perimeter()
{
    return(3.1415 * radious * 2);
}

void Circle::print()
{
    cout << "center point is:";
    center.print();
    cout << endl;
    cout << "radious is:" << radious << endl;
}

string Circle::type()
{
    return("circle");
}
//getters and setters

double Circle::get_radious()
{
    return(radious);
}

void Circle::set_radious(double r)
{
    if (r >= 0)
    {
        radious = r;
    }
    else
    {
        cout << "radious can only be non negetive value!" << endl;
    }
}

Point Circle::get_center()
{
    return(center);
}

void Circle::set_center(Point p)
{
    center = p;
}