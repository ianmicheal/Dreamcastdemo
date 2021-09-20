#ifndef __LINUX__H
#define __LINUX__H

#include "opengl.h"
#include "system.h"
#include <SDL/SDL.h>

class Linux : public System {
public:
  virtual bool init(int width,int height);
  virtual void updateInputs();
  virtual void render();
  virtual void loop();
};

#endif
