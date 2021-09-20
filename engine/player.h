#ifndef __PLAYER__H
#define __PLAYER__H

#include "camera.h"

class Player : public Camera {
	public:
		void init();
		void display();
};

#endif
