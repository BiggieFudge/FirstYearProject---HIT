#include "pch.h"
#include "Poligon.h"
#include <string.h>

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
    //amount_tzela = check_tzela();//?

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
            sum += Real_Coor[i].x * Real_Coor[0].y - Real_Coor[i].y * Real_Coor[0].x;

        }
        else
        {
            sum += Real_Coor[i].x * Real_Coor[i + 1].y - Real_Coor[i].y * Real_Coor[i + 1].x;
        }

    }
    return(abs(sum / 2));
}

double Poligon::perimeter()
{
    int i;
    double sum = 0, slope = 0, tmp_slope = 0;
    bool tf_slope = true;
    for (i = 0; i < amount_edge; i++)
    {
        if (i == amount_edge - 1)
        {
            sum += vector_len(Real_Coor[i], Real_Coor[0]);
            //fixing perimeter for vectors bigger than 2 points
            if (i > 2)
                tmp_slope = check_slope(Real_Coor[i], Real_Coor[0]);

            if (tmp_slope != slope)
            {
                tf_slope = false;
            }

        }
        else
        {
            sum += vector_len(Real_Coor[i], Real_Coor[i + 1]);
            //fixing perimeter for vectors bigger than 2 points
            tmp_slope = check_slope(Real_Coor[i], Real_Coor[i + 1]);
            if (i == 0)
            {
                slope = tmp_slope;
            }
            else
            {
                if (tmp_slope != slope)
                {
                    tf_slope = false;
                }
            }
        }

    }
    if (tf_slope == false)
    {
        return(sum);
    }
    else
    {
        return(sum / 2);
    }
}

//not used right now by mfc
//void Poligon::print()
//{
//    int i;
//    for (i = 0; i < amount_edge; i++)
//    {
//        cout << "point " << i + 1 << " is: ";
//        arr_edge[i].print();
//        cout << endl;
//    }
//}

string Poligon::type()
{
    int tmp = amount_edge;
    switch (amount_edge)
    {
    //case 1:
    //    return("single point");
    //case 2:
    //    return("vector");
    //case 3:
    //    return("triangle");
    //case 4:
    //    return("rectangle");
    default:
        string rt;
        rt = "Poly";
        //rt += tmp + '0';
        //rt += " number of edges";
        return(rt);
    }

}

//extra functions:
double Poligon::check_slope(POINT p1, POINT p2)
{
    if (p1.x != p2.x)
    {
        return(p1.y - p2.y) / (p1.x - p2.x);
    }
    else//makbil to y axis
    {
        return(0);
    }
}

POINT* Poligon::GetArr()
{
   
        return On_Screen_Coor;
    
}
 const int Poligon::get_amount_edge()
 {
     return(amount_edge);
 }

 POINT* Poligon::get_fake_arr()
 {
     return(Real_Coor);
 }

//int Poligon::check_tzela()//doesnt work well,check how to recognize the two slopes that result in zero,makbilim to the axis's.
//{

//    if (amount_edge == 1)
//    {
//        return(0);
//    }
//    else if (amount_edge == 2)
//    {
//        if (arr_edge[0] == arr_edge[1])
//        {
//            return(0);
//        }
//        else
//        {
//            return(1);
//        }
//    }
//    else
//    {
//        int sum = 0, i;
//        Point p;
//        double  slope, tmp_slope;
//        for (i = 0; i < amount_edge; i++)
//        {
//            if (i == amount_edge - 1)
//            {
//                tmp_slope = check_slope(arr_edge[i], arr_edge[0]);
//                p = arr_edge[i];
//                if (arr_edge[0] != p && slope != tmp_slope)
//                {
//                    sum++;
//                }
//            }
//            else
//            {

//                tmp_slope = check_slope(arr_edge[i], arr_edge[i + 1]);
//                p = arr_edge[i];
//                if (i == 0)
//                {

//                    slope = tmp_slope;
//                    if (arr_edge[i + 1] != p)
//                    {
//                        sum++;
//                    }
//                }
//                else
//                {
//                    if (arr_edge[i + 1] != p && slope != tmp_slope)
//                    {
//                        sum++;
//                        slope = tmp_slope;
//                    }
//                }
//            }

//        }
//        return(sum);
//    }





//}

////getters setters
//int Poligon::get_tzela()
//{
//    return(amount_tzela);
//}