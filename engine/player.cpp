#include "player.h"
#include "obj.h"

void Player::init() {
	model          = new Obj("v_wrench.obj");
	boundingSphere = Sphere(/* position */ Point3D(2.0,-4.0,0.0), /* radius */ 2);
}

void Player::display() {
	glClear(GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if(model != NULL)
		model->render();
}
