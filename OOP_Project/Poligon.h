#pragma once


#include "Shape.h"


class Poligon :public Shape
{
public:
    DECLARE_SERIAL(Poligon);

    Poligon();
    Poligon(POINT* ,POINT* ,int);
    ~Poligon();
    //virtual functions:
    double area();
    double perimeter();
    //void print();
    string type();
    //extra functions:
    double check_slope(POINT, POINT);
    //int check_tzela();
    //getters setters
    //int get_tzela();
    const int get_amount_edge();
    POINT* GetArr();//returns the on screen points
    POINT* get_fake_arr();//returns the x,y points
   // bool Is_Vector();

    void Serialize(CArchive& archive);

private:
    const int amount_edge;
    POINT* Real_Coor;
    POINT* On_Screen_Coor;//for painting the poly
    int amount_tzela;

};



