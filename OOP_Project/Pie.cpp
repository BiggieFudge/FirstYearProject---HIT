#include "pch.h"
#include "Pie.h"


IMPLEMENT_SERIAL(pie, ellipse, 1)

pie::pie(POINT p1,POINT p2,POINT* arr_p,POINT p3,POINT p4,POINT* arr_a):ellipse(p1,p2,arr_p)
{
    start_angle=p3;
    end_angle = p4;
    Angle_point=new POINT[2];
    Angle_point[0].x = arr_a[0].x;
    Angle_point[0].y = arr_a[0].y;
    Angle_point[1].x = arr_a[1].x;
    Angle_point[1].y = arr_a[1].y;
}

pie::pie()
{
    
}


pie::~pie()
{
    delete[] Angle_point;
}

double pie::area()
{
   
    double centerx = (get_rp().x/10 + get_lp().x/10) / 2;
    double centery = (get_rp().y/10 + get_lp().y/10) /2;

   
    double b = sqrt(abs(pow((centerx - end_angle.x / 10), 2) + pow((centery - end_angle.y / 10), 2)));
    double c = sqrt(abs(pow((start_angle.x / 10 - centerx), 2) + pow((start_angle.y / 10 - centery), 2)));

    double angle = acos(((start_angle.x* end_angle.x)+(start_angle.y * end_angle.y)) /(b*c)) * 180 / PI;
    if (isnan(angle)) {
        angle = 180;
    }
    else if ((start_angle.x>= end_angle.x)&&(start_angle.y <= end_angle.y)) {
        angle = 360- angle;
    }

    double area = ellipse::area()-( (angle)/360 * ellipse::area());
    return(area);
}

double pie::perimeter()
{
    return(3);
}
    
string pie::type()
{
     return("CircleP");
}
    
POINT* pie::get_angle_point()
{
    return(Angle_point);
}

POINT pie::get_start_angle()
{
    return start_angle;
}

POINT pie::get_end_angle()
{
    return end_angle;
}

void pie::Serialize(CArchive& archive) {

    
    if (archive.IsStoring()) {

        archive << color_index << PositionTypeList << Position_shape_list;//shape class objects

        archive << this->get_lp().x<<this->get_lp().y << this->get_rp().x<< this->get_rp().y <<this->get_rekt().TopLeft().x<<this->get_rekt().TopLeft().y<<this->get_rekt().BottomRight().x<<this->get_rekt().BottomRight().y;
        


        archive << start_angle.x << start_angle.y << end_angle.x << end_angle.y << Angle_point[0].x << Angle_point[0].y << Angle_point[1].x << Angle_point[1].y;
    }
    else {
        Angle_point = new POINT[2];
         archive >> color_index >> PositionTypeList >> Position_shape_list;
         POINT lp;
         archive >> lp.x >> lp.y;
         this->set_lp(lp.x,lp.y);

         POINT rp;
         archive >> rp.x >> rp.y;
         this->set_rp(rp.x, rp.y);

         long x1, y1, x2, y2;
         archive >> x1 >> y1 >> x2>> y2;
         this->set_rekt(CRect(x1,y1,x2,y2));
         

         archive >> start_angle.x >> start_angle.y >> end_angle.x >>end_angle.y >> Angle_point[0].x >> Angle_point[0].y >> Angle_point[1].x >> Angle_point[1].y;
    }
}
