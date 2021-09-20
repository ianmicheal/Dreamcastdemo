#ifdef _arch_dreamcast

#ifndef __DREAMCAST__H
#define __DREAMCAST__H
#include <kos.h>
#include "system.h"

class Dreamcast : public System {
protected:
  maple_device_t* controller;
public:
  virtual bool init(int width,int height);
  virtual void updateInputs();
  virtual void render();
  virtual void loop();
};
#endif
#endif
