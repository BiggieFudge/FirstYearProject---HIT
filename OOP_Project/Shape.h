#pragma once
#include <iostream>
#include <math.h>
#include "Point.h"
#include <string.h>

using namespace std;

class Shape
{
public:
    //Shape(int x):amount_edge(x) {}
    Shape() {}
    virtual ~Shape() {}
    virtual double area() = 0;
    virtual double perimeter() = 0;
    //virtual void print() = 0;
    virtual string type() = 0;
    void set_color(int x)
    {
        color_index = x;
    }
    int get_color()
    {
        return(color_index);
    }

    //old

    //double vector_len(Point p1, Point p2)
    //{
    //    return(sqrt(pow(p1.get_x() - p2.get_x(), 2) + pow(p1.get_y() - p2.get_y(), 2)));
    //}


    //fixed
     double vector_len(POINT p1, POINT p2)
    {
        return(sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
    }
    /*const int amount_edge;
    Point* arr_edge;*/

     int color_index=-1;//color for shapes in ShapeArr
private:

};

