#include <iostream>

#include "opengl.h"
#include "camera.h"

using namespace std;

Camera::Camera() {
  moveVelocity  = 0.5;
  lookVelocity  = 0.01;
  yaw           = 0.0f;
  pitch         = 0.0f;
}

void Camera::move(float direction) {
  float oldY = boundingSphere.center.y;
  boundingSphere.center   = projectPoint(boundingSphere.center, direction + yaw,pitch,moveVelocity);
  boundingSphere.center.y = oldY;
}
void Camera::update(){
  if(pitch>90)
        pitch=90;
    if(pitch<-90)
        pitch=-90;
    if(yaw<0.0)
        yaw+=360.0;
    if(yaw>360.0)
        yaw-=360;


  glRotatef(-pitch,1,0,0);
  glRotatef(-yaw,0,1,0);
  glTranslatef(-boundingSphere.center.x,-boundingSphere.center.y - (boundingSphere.radius*2),-boundingSphere.center.z);
}
