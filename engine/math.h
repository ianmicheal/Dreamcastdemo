#ifndef __MATH__H
#define __MATH__H

#include "point.h"
#include <stdlib.h>
float    max(float a,float b);
float    min(float a,float b);
float    length(Point3D v);
Point3D  normalize(Point3D v);
float    dot(Point3D a, Point3D b);
Point3D  cross(Point3D a, Point3D b);
Point3D  ClosestPointOnLineSegment(Point3D A,Point3D B,Point3D Point);
float    distanceBetween(Point3D a,Point3D b);
Point3D  projectPoint(Point3D origin,float yaw,float pitch,float distance);
float    angleBetween(Point2D a,Point2D b,Point2D c);
#endif
