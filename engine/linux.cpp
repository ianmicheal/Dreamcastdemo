#include "linux.h"

void Linux::updateInputs() {
  int MidX=320;
	int MidY=240;
	SDL_ShowCursor(SDL_DISABLE);
	int tmpx,tmpy;
	SDL_GetMouseState(&tmpx,&tmpy);
	player.yaw   += player.lookVelocity*(MidX-tmpx);
	player.pitch += player.lookVelocity*(MidY-tmpy);
	SDL_WarpMouse(MidX,MidY);

  Uint8* state=SDL_GetKeyState(NULL);
  if(state[SDLK_w]) {
    up = true;
  }
  else if(state[SDLK_s]){
    down = true;
  }
  if(state[SDLK_a])
    left = true;
  else if(state[SDLK_d])
    right = true;

}


bool Linux::init(int width,int height) {
  player.lookVelocity = 0.1;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Surface* screen=SDL_SetVideoMode(width,height,32,SDL_SWSURFACE|SDL_OPENGL);

  System::init(width,height);
}

void Linux::render() {
  System::updateView();
  System::render();
  SDL_GL_SwapBuffers();
  System:resetInputs();
}

void Linux::loop() {
  Uint32 start;

  while(1) {
    start=SDL_GetTicks();

    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_QUIT:
         exit(0);
          break;
        case SDL_MOUSEBUTTONDOWN:
          SDL_ShowCursor(SDL_DISABLE);
          break;
        case SDL_KEYDOWN:
          if(event.key.keysym.sym==SDLK_ESCAPE) {
              exit(0);
              break;
          }
      }
    }

    updateInputs();
    updateView();
    render();
    resetInputs();
    if(1000/30>(SDL_GetTicks()-start))
      SDL_Delay(1000/30-(SDL_GetTicks()-start));
  }
}
