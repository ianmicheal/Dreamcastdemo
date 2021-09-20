#include "opengl.h"
#include "system.h"


bool System::init(int width,int height){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
	glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LEQUAL);				// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
	glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();				// Reset The Projection Matrix

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,300.0f);	// Calculate The Aspect Ratio Of The Window

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	
	player.init();
}
void System::updateInputs(){

}
void System::updateView() {
  if(up) {
    player.move(0);
  }
  if(down)  {
    player.move(180);
  }
  if(right) {
    player.move(270);
  }
  if(left)  {
    player.move(90);
  }
}
void System::render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
  glLoadIdentity();				// Reset The player

  player.update();

  scene();

}

void System::scene() {

}

void System::resetInputs()  {
  up      = false;
  down    = false;
  left    = false;
  right   = false;
}

void System::loop() {
  while(1){
    updateInputs();
    updateView();
    render();
    resetInputs();
  }
}
