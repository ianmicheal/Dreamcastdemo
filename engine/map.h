#ifndef __MAP__H
#define __MAP__H 

#include <vector>

#include "entity.h"
#include "obj.h"


class Map : public Obj {
	public: 
		std::vector<Entity*> entities;
	        std::vector<Collision> testCollision(Entity* entity);
		void updateEntities(float gravity);
		void render();	

};

#endif
