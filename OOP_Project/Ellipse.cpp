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
   
   int  x1 = lp.x  ;
   int  y1 = lp.y ;    // First diagonal point
   int  x2 = rp.x ;
   int  y2 = rp.y ;    // Second diagonal point

   int  xc = (x1 + x2)/2; 
   int  yc = (y1 + y2)/2;    // Center point
   int  xd = (x1 - x2)/2; 
   int  yd = (y1 - y2)/2;    // Half-diagonal

   int  x3 = xc - yd; 
   int  y3 = yc + xd;    // Third corner
   int  x4 = xc + yd; 
   int  y4 = yc - xd;    // Fourth corner

   POINT p1, p2;
   p1.x = x3;
   p1.y = y3;
   p2.x = x4;
   p2.y = y4;

   //return(vector_len())
   return(3);

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

POINT ellipse::get_lp()
{
    return lp;
}

POINT ellipse::get_rp()
{
    return rp;
}
