#include "pch.h"
#include "Pie.h"


IMPLEMENT_SERIAL(pie, Circle, 1)

//pie::pie(POINT p1,POINT p2,POINT* arr_p,POINT p3,POINT p4,POINT* arr_a):ellipse(p1,p2,arr_p)
//{
//    start_angle=p3;
//    end_angle = p4;
//    Angle_point=new POINT[2];
//    Angle_point[0].x = arr_a[0].x;
//    Angle_point[0].y = arr_a[0].y;
//    Angle_point[1].x = arr_a[1].x;
//    Angle_point[1].y = arr_a[1].y;
//}
pie::pie(POINT center,POINT* rect_points,double radius,POINT p3,POINT p4,POINT* arr_a): Circle(center,rect_points,radius)
{
      start_angle=p3;
      end_angle = p4;
      Angle_point=new POINT[2];
      Angle_point[0].x = arr_a[0].x;
      Angle_point[0].y = arr_a[0].y;
      Angle_point[1].x = arr_a[1].x;
      Angle_point[1].y = arr_a[1].y;

      angle = create_angle();
}

pie::pie()
{
   
}


pie::~pie()
{
    delete[] Angle_point;
}

double pie::create_angle()
{
    
    b = vector_len(this->get_center(), end_angle)/10;
    c = vector_len(this->get_center(), start_angle)/10;
    if (b == 0 || c == 0)
    {
        return(0);
    }

    else {
       // angle = acos((((((get_center().x / 10-start_angle.x / 10 ) * (get_center().x/10 - end_angle.x / 10))) + ((get_center().y / 10-start_angle.y / 10 ) * (get_center().y/10 - end_angle.y / 10))) / (b * c))) * 180 / PI;
        angle = atan2(get_center().y -start_angle.y, get_center().x -start_angle.x) - atan2(get_center().y-end_angle.y, get_center().x- end_angle.x);
        if (angle < 0) {
            angle += 2 * PI;
       }
        angle = 360-(angle * 180 / PI);
      

        return(angle);
    }

}

 double pie::get_angle() const
 {
     return(angle);
 }

double pie::area()
{
   
  
   
   if(angle==0)
       return (Circle::area());


    double area = ( (angle)/360 * Circle::area());
    return(area);
}

double pie::perimeter()
{
    if(angle==0)
    {
        return(Circle::perimeter() + get_radius());
    }
    double per = ( (angle)/360 * Circle::perimeter())+ Circle::get_radius()*2;
    return(per);
}
    
string pie::type()
{
     return("CircleP");
}
    
POINT* pie::get_angle_point() const
{
    return(Angle_point);
}

POINT pie::get_start_angle() const
{
    return start_angle;
}

POINT pie::get_end_angle() const
{
    return end_angle;
}

void pie::Serialize(CArchive& archive) {

    
    if (archive.IsStoring()) {

        archive << color_index << PositionTypeList << Position_shape_list;//shape class objects
        
        archive <<  this->get_radius()  << this->get_center() << this->get_rekt().TopLeft().x<<this->get_rekt().TopLeft().y<<this->get_rekt().BottomRight().x<<this->get_rekt().BottomRight().y;  ///parameter of circle

        archive << start_angle.x << start_angle.y << end_angle.x << end_angle.y << Angle_point[0].x << Angle_point[0].y << Angle_point[1].x << Angle_point[1].y <<angle;
    }
    else {
         Angle_point = new POINT[2];
         archive >> color_index >> PositionTypeList >> Position_shape_list;
         
         double x;
         POINT p;
         long x1, y1, x2, y2;
         archive >> x >> p >> x1 >> y1 >> x2 >> y2;
         this->set_rekt(CRect(x1,y1,x2,y2));
         this->set_radious(x);
         this->set_center(p);
    

         archive >> start_angle.x >> start_angle.y >> end_angle.x >>end_angle.y >> Angle_point[0].x >> Angle_point[0].y >> Angle_point[1].x >> Angle_point[1].y >>angle;
    }
}
