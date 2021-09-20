#define WIDTH  640
#define HEIGHT 480

#include "opengl.h"
#include "system.h"
#include "map.h"
#include "player.h"

using namespace std;



class Game : public CURRENT_SYSTEM {

  public:
    	bool init(int width,int height) {
      		CURRENT_SYSTEM::init(width,height);
      		map.load("level_1.obj");
                map.entities.push_back(new Entity("box.obj",Sphere(Point3D(15,0,0),1.8)));
      		map.entities.push_back(&player);
      		gravity = -0.2;

    	}
    	void scene(){
    		map.updateEntities(gravity);
    		map.render();
    	}

};


int main(int argc, char **argv)
{
    Game game;
    game.init(640,480);
    game.loop();
    return 0;
}
