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
    radius1 = (double)(abs(rp.y - lp.y)/2)/10;
    radius2 = (double)(abs(rp.x - lp.x)/2)/10;
}
ellipse::ellipse()
{
   
}
ellipse::ellipse(const ellipse& e1) :Circle()
{
    lp = e1.lp;//top left point of rectangle
    rp = e1.rp;//bottom right point of rectangle
    Rect_point = new POINT[2];
    Rect_point[0] = e1.Rect_point[0];//contains the real axis points;
    Rect_point[1] = e1.Rect_point[1];
    radius1 = e1.radius1;//created just for area and perimeter
    radius2 = e1.radius2;//created just for area and perimeter
}
ellipse::~ellipse()
{
    delete[] Rect_point;
}

double ellipse::area()
{
    radius1 = (double)(abs(rp.y - lp.y) / 2) / 10;
    radius2 = (double)(abs(rp.x - lp.x) / 2) / 10;
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

void ellipse::set_rekt(CRect r)
{
    if(Rect_point==NULL)
    {
         Rect_point = new POINT[2];
    }
    Rect_point[0].x = r.TopLeft().x;
    Rect_point[0].y = r.TopLeft().y;
    Rect_point[1].x =r.BottomRight().x;
    Rect_point[1].y = r.BottomRight().y;
    
}


void ellipse::set_lp(long x1,long y1)
{
    lp.x = x1;
    lp.y = y1;
}

void ellipse::set_rp(long x1,long y1)
{
    rp.x = x1;
    rp.y = y1;
}

void ellipse::Serialize(CArchive& archive)
{

    

    if (archive.IsStoring()) {
        archive << color_index << PositionTypeList << Position_shape_list;
        archive << lp.x << lp.y << rp.x <<rp.y  << Rect_point[0].x << Rect_point[0].y << Rect_point[1].x << Rect_point[1].y << radius1<<radius2;
    }

    else {
        Rect_point = new POINT[2];
        archive >> color_index >> PositionTypeList >> Position_shape_list;
       archive >> lp.x >>lp.y >> rp.x >> rp.y >> Rect_point[0].x >> Rect_point[0].y >> Rect_point[1].x >> Rect_point[1].y>> radius1 >> radius2;
    }

   

}
