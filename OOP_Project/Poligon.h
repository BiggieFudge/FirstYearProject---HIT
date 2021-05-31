#pragma once


#include "Shape.h"


class Poligon 
    :public Shape {
public:
    DECLARE_SERIAL(Poligon);

    //Constructors
    Poligon();
    Poligon(POINT* ,POINT* ,int);
    ~Poligon();

    void Serialize(CArchive& archive);

    //Get/Set
    int get_amount_edge() const; //return number of points;

    POINT* GetArr() const;//returns the on screen points

    POINT* get_fake_arr() const;//returns the x,y points



    //virtual functions:
    double area();

    double perimeter();

    string type();



    //extra functions:
    double check_slope(POINT, POINT);

    string PrintType();
   
 

    
    
private:

    int amount_edge; //number of points

    POINT* Real_Coor; //Coordination for information(user enter points)

    POINT* On_Screen_Coor;//for painting the poly
    

};



