#ifdef _arch_dreamcast
#include "opengl.h"

#include "dreamcast.h"


bool Dreamcast::init(int width,int height) {
  glKosInit();
  glEnable(GL_TEXTURE_2D);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // This Will Clear The Background Color To Black
  glClearDepth(1.0);                    // Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);                 // The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);              // Enables Depth Testing
  glShadeModel(GL_SMOOTH);              // Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); // Reset The Projection Matrix

  gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 300.0f); // Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);
  controller = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);
  player.init();
}
void Dreamcast::updateInputs() {
  cont_state_t* controllerState = (cont_state_t*) maple_dev_status(controller);
  player.yaw -= controllerState->joyx * player.lookVelocity;
  player.pitch += controllerState->joyy * player.lookVelocity;

  if (controllerState->buttons & CONT_Y){
    player.move(0);
  }
  if (controllerState->buttons & CONT_A){
    player.move(180);
  }
  if (controllerState->buttons & CONT_B){
    player.move(270);
  }
  if (controllerState->buttons & CONT_X){
    player.move(90);
  }
}
void Dreamcast::render() {

  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);


  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glClearColor(0.5, 0.5, 0.5, 1.0);
  player.update();

  scene();

  glKosSwapBuffers();
}


void Dreamcast::loop() {
  while(1){
    updateInputs();
    render();
  }
}
#endif
