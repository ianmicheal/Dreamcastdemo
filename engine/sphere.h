#ifndef __SPHERE__H
#define __SPHERE__H

#include "point.h"
#include "math.h"
#include "collision.h"

class Sphere  {
	public:
	Point3D center;
	float   radius;
	Sphere();
	Sphere(Point3D,float);
        bool isPointInside(Point3D b);
	Collision testCollision(Point3D a,Point3D b,Point3D c);
	Collision testCollision(Sphere b);
		
};

#endif
