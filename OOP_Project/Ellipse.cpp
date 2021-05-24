#include "pch.h"
#include "Ellipse.h"
IMPLEMENT_SERIAL(ellipse, Circle, 1)
ellipse::ellipse(POINT p1,POINT p2,POINT* arr_p) :Circle()
{
	lp = p1;
	rp = p2;
    Rect_point = new POINT[2];
    Rect_point[0].x = arr_p[0].x;
    Rect_point[0].y = arr_p[0].y;
    Rect_point[1].x = arr_p[1].x;
    Rect_point[1].y = arr_p[1].y;
    radius1 = (double)((rp.y - lp.y)/2)/10;
    radius2 = (double)((rp.x - lp.x)/2)/10;
}
ellipse::ellipse()
{
   
}

ellipse::~ellipse()
{
    delete[] Rect_point;
}

double ellipse::area()
{
   return((radius1*radius2* PI));

}

double ellipse::perimeter()
{
    
   
    return(PI * ( 3*(radius1+radius2)-   sqrt((3*radius1+radius2)*(3*radius2+radius1))    )  );
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
void ellipse::Serialize(CArchive& archive)
{

    Circle::Serialize(archive);

   if (archive.IsStoring()) {
        archive << lp << rp  << Rect_point[0] << Rect_point[1]<<radius1<<radius2;
    }

    else {
        archive >> lp >> rp >> Rect_point[0] >> Rect_point[1]>>radius1>>radius2;
    }

   

}
