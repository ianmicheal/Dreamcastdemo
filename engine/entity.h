#ifndef __ENTITY__H
#define __ENTITY__H

#include <iostream>
#include <vector>

#include "point.h"
#include "sphere.h"
#include "model.h"

class Map;
class Player;

class Entity {
	public:
		float yaw,pitch;
		float vision; 
		float FOV;

		Model*   model;
		Sphere  boundingSphere;
					
		Entity();
		Entity(std::string,Sphere sphereIn);
		bool canSee(Entity* other,Map* mapIn);
		void approachTarget(Entity* other);
		
		void         processCollisions(std::vector<Collision> collisions);		
		virtual void update(std::vector<Collision> collisions,float);
		virtual void display();
		virtual void init();
};

#endif
