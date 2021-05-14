#pragma once
#include <iostream>
#include <math.h>

using namespace std;


class Point
{
public:
    Point(double a = 0, double b = 0) { x = a; y = b; }
    double get_x() { return(x); }
    void set_x(double new_x) { x = new_x; }
    double get_y() { return(y); }
    void set_y(double new_y) { y = new_y; }
    bool operator==(Point p1)
    {
        return(!(*this != p1));
    }
    bool operator!=(Point p1)
    {
        if (x == p1.x && y == p1.y)
        {
            return(false);
        }
        else
        {
            return(true);
        }
    }
    
    //from here not used in mfc right now
    void input_point()
    {
        cout << "enter x and y coordinates:" << endl;
        cin >> x >> y;
    }
    void print()
    {
        cout << "(" << x << "," << y << ")";
    }
private:
    double x;
    double y;

};