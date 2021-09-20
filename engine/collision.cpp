#include "collision.h"

Collision::Collision() {
    collided  = false;
    depth     = 0;
    direction = Point3D(0.0f,0.0f,0.0f);
}
Collision::Collision(Point3D directionIn,float depthIn) {
    collided  = true;
    depth     = depthIn;
    direction = directionIn;
}
