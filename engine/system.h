#ifndef __SYSTEM__H
#define __SYSTEM__H

#include "map.h"
#include "player.h"

class System {
  protected:
	bool up,down,left,right;

	float  gravity;
	Map    map;
	Player player;
  public:
	virtual bool init(int width,int height);
	virtual void updateInputs();
	virtual void updateView();
	virtual void resetInputs();
	virtual void render();
	virtual void loop();
	virtual void scene();
};

#ifdef _arch_dreamcast
  #include "dreamcast.h"
  #define CURRENT_SYSTEM Dreamcast
#else
  #include "linux.h"
  #define CURRENT_SYSTEM Linux
#endif

#endif
