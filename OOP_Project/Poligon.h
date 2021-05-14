#pragma once
#include "Shape.h"

class Poligon :public Shape
{
public:
    Poligon(POINT* PointArray,int x = 1);
    ~Poligon();
    //virtual functions:
    double area();
    double perimeter();
    //void print();
    string type();
    //extra functions:
    double check_slope(POINT, POINT);
    int check_tzela();
    //getters setters
    int get_tzela();

private:
    const int amount_edge;
    POINT* arr_edge;
    int amount_tzela;
};



