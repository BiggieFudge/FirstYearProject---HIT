#include "pch.h"
#include "Shape.h"

//IMPLEMENT_SERIAL_PURE_BASE(Shape, CObject, VERSIONABLE_SCHEMA | 1)

//void Shape::Serialize(CArchive& archive)
//{
//   if (archive.IsStoring()) {
       
//            archive << color_index << PositionTypeList << Position_shape_list << radius << radiusReal << center << RectPoint[0].x << RectPoint[0].y << RectPoint[1].x << RectPoint[1].y;
  
//    }

//    else {
//        RectPoint = new POINT[2];
//        archive >> color_index >> PositionTypeList >> Position_shape_list >> radius >> radiusReal >> center >> RectPoint[0].x >> RectPoint[0].y >> RectPoint[1].x >> RectPoint[1].y;
//    }
//}