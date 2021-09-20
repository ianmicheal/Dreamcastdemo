#include "map.h"

using namespace std;


void Map::updateEntities(float gravity) {

	for(int e = 0; e < entities.size(); e++) {
		vector<Collision> collisions = testCollision(entities[e]);
		entities[e]->update(collisions,gravity);
	}
}

void Map::render() {
	Obj::render();
	for(int e = 0; e < entities.size(); e++) {
		entities[e]->display();
	}
}

vector<Collision> Map::testCollision(Entity* entity) {
	vector<Collision> out;
	for(int g = 0; g < groups.size(); g++) {
			for(int f = 0; f < groups[g].faces.size(); f++) {
			    OBJFace      face  = groups[g].faces[f];
			    Point3D        a   = verticies[face.vertexIndecies[0]-1];
			    Point3D        b   = verticies[face.vertexIndecies[1]-1];
			    Point3D        c   = verticies[face.vertexIndecies[2]-1];
			    Collision     hit   = entity->boundingSphere.testCollision(a,b,c);
			    if(hit.collided) {
				out.push_back(hit);
			}  
		}
	}

	for(int e = 0; e < entities.size(); e++) {
		if(entities[e] != entity) {
			Collision hit = entity->boundingSphere.testCollision(entities[e]->boundingSphere);
			if(hit.collided)
				out.push_back(hit);
		}
	}


    return out;
}
