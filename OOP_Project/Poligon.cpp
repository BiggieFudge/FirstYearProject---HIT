#include "pch.h"
#include "Poligon.h"


IMPLEMENT_SERIAL(Poligon, CObject, 1);



Poligon::Poligon(POINT* PointArray, POINT* RealPoint, int x = 1) :amount_edge(x) {


    Real_Coor = new POINT[amount_edge];//for painting the poly

    int i;
    On_Screen_Coor = new POINT[amount_edge];
    for (i = 0; i < amount_edge; i++)
    {
        On_Screen_Coor[i].x = PointArray[i].x;
        On_Screen_Coor[i].y = PointArray[i].y;
        Real_Coor[i].x = RealPoint[i].x;
        Real_Coor[i].y = RealPoint[i].y;
    }
    

}

Poligon::Poligon()  //Default constrctur for serialization
{
   
}


   


Poligon::~Poligon()
{
    delete[] On_Screen_Coor;
    delete[] Real_Coor;
}

double Poligon::area()
{
    int i;
    double sum = 0;
    for (i = 0; i < amount_edge; i++)
    {
        if (i == amount_edge - 1)
        {
            sum += (Real_Coor[i].x/10) * (Real_Coor[0].y/10) - (Real_Coor[i].y/10) * (Real_Coor[0].x/10);

        }
        else
        {
            sum += (Real_Coor[i].x/10) * (Real_Coor[i + 1].y/10) - (Real_Coor[i].y/10) * (Real_Coor[i + 1].x/10);
        }

    }
    return(abs(sum / 2));
}

double Poligon::perimeter()
{
    
    int i;
    double sum=0;
    for (i = 0; i < amount_edge; i++)
    {
        if (i == amount_edge - 1)
        {
            sum += (vector_len(Real_Coor[i], Real_Coor[0])/10);
            //fixing perimeter for vectors bigger than 2 points
          

        }
        else
        {
            sum += (vector_len(Real_Coor[i], Real_Coor[i + 1])/10);
            //fixing perimeter for vectors bigger than 2 points
           
        }

    }
    if(area()==0)
    {
        return(sum / 2);
    }
    else
    {
        return(sum);
    }
    
}



string Poligon::type()
{
    
    return "Polygon";
    

}



string Poligon::PrintType() {

    if (get_amount_edge() == 1) { 
        return "Point"; }


    double Spacing = check_slope(get_fake_arr()[0], get_fake_arr()[1]);
    int SideAmount = 1;

    for (int i = 2; i <= get_amount_edge(); i++) {

        if (check_slope(get_fake_arr()[i-1], get_fake_arr()[i]) != Spacing) {

            SideAmount++;

        }
        Spacing = check_slope(get_fake_arr()[i - 1], get_fake_arr()[i]);
    }

    switch (SideAmount) {
    case 1:
        return "Vector";
        break;
    case 2:
        return "Triangle";
        break;
    case 3:
        return "Square";
        break;
    case 4:
        return "Poly 5Points";
        break;
    case 5:
        return "Poly 6Points";
        break;
    case 6:
        return "Poly 7Points";
        break;
    case 7:
        return "Poly 8Points";
        break;

    }



}

//extra functions:
double Poligon::check_slope(POINT p1, POINT p2)
{
    if ( (p1.x / 10 - p2.x / 10) != 0)
    {
        return(p1.y/10 - p2.y/10) / (p1.x/10 - p2.x/10);
    }
    else//makbil to y axis
    {
        
        return(999);
    }
}


POINT* Poligon::GetArr()
{
   
        return On_Screen_Coor;
    
}
 int Poligon::get_amount_edge()
 {
     return(amount_edge);
 }

 POINT* Poligon::get_fake_arr()
 {
     return(Real_Coor);
 }

 void Poligon::Serialize(CArchive& archive){
    
     CObject::Serialize(archive);

     if (archive.IsStoring()) {
         archive << color_index << PositionTypeList << Position_shape_list << amount_edge;//shape variables except for amount edge
         
         int i;
         for (i = 0; i < amount_edge; i++) {
             archive << Real_Coor[i].x << Real_Coor[i].y;
         }
         
         for (i = 0; i < amount_edge; i++) {
             archive << On_Screen_Coor[i].x << On_Screen_Coor[i].y;
         }
     }
    
     else {
   
         
         Real_Coor = new POINT[8];
         On_Screen_Coor = new POINT[8];
         archive >> color_index >> PositionTypeList >> Position_shape_list >> amount_edge; //shape variables except for amount edge
         int i;
         for (i = 0; i < amount_edge; i++) {
             archive >> Real_Coor[i].x >> Real_Coor[i].y;
         }
         
         for (i = 0; i < amount_edge; i++) {
             archive >> On_Screen_Coor[i].x >> On_Screen_Coor[i].y;
         }
             
     }




 }

