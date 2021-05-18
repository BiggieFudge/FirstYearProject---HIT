#include "pch.h"
#include "Ellipse.h"

ellipse::ellipse(POINT p1,POINT p2,POINT* arr_p) :Circle()
{
	lp = p1;
	rp = p2;
    Rect_point = new POINT[2];
    Rect_point[0].x = arr_p[0].x;
    Rect_point[0].y = arr_p[0].y;
    Rect_point[1].x = arr_p[1].x;
    Rect_point[1].y = arr_p[1].y;
}

ellipse::~ellipse()
{
    delete[] Rect_point;
}

double ellipse::area()
{
    return(3);//temporrary      
}

double ellipse::perimeter()
{
    return(3);//temporary
}
    
string ellipse::type()
{
     return("CircleE");
}
    
CRect ellipse::get_rekt()
{
   return(CRect(this->Rect_point[0].x, this->Rect_point[0].y, this->Rect_point[1].x, this->Rect_point[1].y));
}