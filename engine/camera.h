#ifndef __CAMERA__H
#define __CAMERA__H

#include "math.h"
#include "entity.h"

class Camera : public Entity {
  public:
    float   yaw,pitch;
    float   moveVelocity;
    float   lookVelocity;

    Camera();
    void move(float direction);
    void update();
};

#endif
