#pragma once
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;






class Shape: 
    public CObject {
     
public:

    

    //Constructors
    Shape() {}

    virtual ~Shape() {}

    virtual void Serialize(CArchive& archive){}



    //Virtual Functions
    virtual double area() = 0;

    virtual double perimeter() = 0;

    virtual string type() = 0;



    //Setters /Getters
    void set_color(int x)
    {
        
        color_index = x;
    }
    int get_color() const 
    {
        return(color_index);
    }
    void set_is_shown(bool x)
    {
        is_shown = x;
    }
    bool get_is_shown() const
    {
        return(is_shown);
    }
    
    void set_pos_type_list(int PTL) {
        PositionTypeList = PTL;
    }
    int get_pos_type_list()const {
        return PositionTypeList;
    }

    void set_pos_shape_list(int PTL) {
        Position_shape_list = PTL;
    }
    int get_pos_shape_list()const {
        return Position_shape_list;
    }
   


    
     double vector_len(POINT p1, POINT p2)
    {
        return(sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
    }
    


     //Varaibles
     int color_index=-1;//color for shapes in ShapeList
     bool is_shown = false;
     int PositionTypeList =-1;        //Poistion in the specifiec type of list
     int Position_shape_list = -1;
     
     
private:

    
    

};

