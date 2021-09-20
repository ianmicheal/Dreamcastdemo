#ifndef __COLLISION__H
#define __COLLISION__H

#include "point.h"

class Collision {
    public:
        Point3D direction;
        float   depth;
        bool    collided;
        
    Collision();
    Collision(Point3D directionIn,float depthIn);
};

#endif
