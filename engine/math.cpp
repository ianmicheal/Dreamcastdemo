#include <iostream>
#include "math.h"

using namespace std;

float max(float a,float b) {
    if(a > b)
        return a;
    else
        return b;
}

float min(float a,float b) {
    if(a < b)
        return a;
    else
        return b;
}

float length(Point3D v) {
	return sqrt (v.x * v.x + v.y * v.y + v.z * v.z);
}

Point3D normalize(Point3D v) {
	Point3D vb;
	float l = length(v);
	if(0.0f == l) {
		return Point3D(0.0f, 0.0f, 0.0f);
	}
	vb.x = v.x / l;
	vb.y = v.y / l;
	vb.z = v.z / l;
	return vb;
}

float dot(Point3D a, Point3D b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross(Point3D a, Point3D b) {
	float x = a.y * b.z - a.z * b.y;
	float y = a.z * b.x - a.x * b.z;
	float z = a.x * b.y - a.y * b.x;
	return Point3D(x, y, z);
}



Point3D ClosestPointOnLineSegment(Point3D A,Point3D B,Point3D Point)
{
    B = normalize(B);//this needs to be a unit vector
    Point3D v = Point - A;
    float d    = dot(v, B);
    return A + B * d;
}

float distanceBetween(Point3D a,Point3D b) {
	float A = pow(b.x - a.x,2);
	float B = pow(b.y - a.y,2);
	float C = pow(b.z - a.z,2);
	return sqrt(A + B +C);
}

Point3D  projectPoint(Point3D origin,float yaw,float pitch,float distance) {
	float rad   = yaw*M_PI/180.0;	
	 origin.x  -= sin(rad)*distance;	
	 origin.z  -= cos(rad)*distance;
              rad   = pitch*M_PI/180.0;
	 origin.y  += sin(rad)*distance;
	return origin;
}
float toDegrees(float radians) {
	return radians * (180.0/M_PI);
}
float angleBetween(Point2D a, Point2D b, Point2D c )
{
    Point2D ab(b.x - a.x, b.y - a.y);
    Point2D cb(b.x - c.x, b.y - c.y);

    float dot = (ab.x * cb.x + ab.y * cb.y); // dot product
    float cross = (ab.x * cb.y - ab.y * cb.x); // cross product

    float alpha = atan2(cross, dot);

    return floor(alpha * 180.0f / M_PI + 0.5);
}
