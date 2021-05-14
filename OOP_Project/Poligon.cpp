#include "pch.h"
#include "Poligon.h"
//
//Poligon::Poligon(double* x_arr,double* y_arr, int x) :amount_edge(x)
////{
////    int i;
////    arr_edge = new Point[amount_edge];
////    for (i = 0; i < amount_edge; i++)
////    {
////        cout << "point number " << i + 1 << endl;
////        arr_edge[i].input_point();
////    }
////    amount_tzela = check_tzela();
//{
//    int i;
//    arr_edge = new Point[amount_edge];
//    for (i = 0; i < amount_edge; i++)
//    {
//        arr_edge[i].set_x(x_arr[i]);
//        arr_edge[i].set_y(y_arr[i]);
//    }
//    amount_tzela = check_tzela();//?
//    
//    
//}

Poligon::Poligon(POINT* PointArray,int x) :amount_edge(x) {

    
    int i;
    arr_edge = new POINT[amount_edge];
    for (i = 0; i < amount_edge; i++)
    {
        arr_edge[i].x = PointArray[i].x;
        arr_edge[i].y = PointArray[i].y;
    }
    //amount_tzela = check_tzela();//?
}


Poligon::~Poligon()
{
    delete[] arr_edge;
}

double Poligon::area()
{
    int i;
    double sum = 0;
    for (i = 0; i < amount_edge; i++)
    {
        if (i == amount_edge - 1)
        {
            sum += arr_edge[i].x * arr_edge[0].y - arr_edge[i].y * arr_edge[0].x;

        }
        else
        {
            sum += arr_edge[i].x * arr_edge[i + 1].y - arr_edge[i].y * arr_edge[i + 1].x;
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
            sum += vector_len(arr_edge[i], arr_edge[0]);
            //fixing perimeter for vectors bigger than 2 points
            if (i > 2)
                tmp_slope = check_slope(arr_edge[i], arr_edge[0]);

            if (tmp_slope != slope)
            {
                tf_slope = false;
            }

        }
        else
        {
            sum += vector_len(arr_edge[i], arr_edge[i + 1]);
            //fixing perimeter for vectors bigger than 2 points
            tmp_slope = check_slope(arr_edge[i], arr_edge[i + 1]);
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
        rt = "polygon";
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