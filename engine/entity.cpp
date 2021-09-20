#include "map.h"

using namespace std;

Entity::Entity() {

}

Entity::Entity(std::string modelName,Sphere sphereIn) {
	yaw    = 0.0f;
	pitch  = 0.0f;
	vision = 5.0f;
	FOV    = 100.0f;

	boundingSphere = sphereIn;
	if (modelName.find(".obj") != std::string::npos) {
    		model = new Obj();
		model->load(modelName);
	}
}

void Entity::approachTarget(Entity* other) {
	Point2D a      = other->boundingSphere.center.toPoint2D();
	Point2D b      = boundingSphere.center.toPoint2D();
	Point2D c      = projectPoint(boundingSphere.center,yaw,pitch,vision).toPoint2D();
	float   angle  = angleBetween(a,b,c);
	float distance = distanceBetween(other->boundingSphere.center, boundingSphere.center);
	if(angle != yaw)
		yaw = yaw + (angle * 0.1);
	if(distance > 12)
		boundingSphere.center = projectPoint(boundingSphere.center,yaw,pitch,0.5);

}

void Entity::init() {

}

void Entity::processCollisions(std::vector<Collision> collisions) {
	for(int c = 0; c < collisions.size(); c++) {
		float x = collisions[c].direction.x * collisions[c].depth ;
		float y = collisions[c].direction.y * collisions[c].depth;
		float z = collisions[c].direction.z * collisions[c].depth ;
		boundingSphere.center.x = boundingSphere.center.x + x;
		boundingSphere.center.y = boundingSphere.center.y + y;
		boundingSphere.center.z = boundingSphere.center.z + z;
	}
}

void Entity::update(std::vector<Collision> collisions,float gravity) {
	/*if(this != (Entity*)player) {
		if(canSee((Entity*)player,NULL))
			approachTarget((Entity*)player);
	}*/

	processCollisions(collisions);
	boundingSphere.center.y = boundingSphere.center.y + gravity;
}

void Entity::display() {
	glPushMatrix();
	glTranslatef(boundingSphere.center.x,boundingSphere.center.y,boundingSphere.center.z);
	glRotatef(pitch,1.0,0.0,0.0);
	glRotatef(yaw,0.0,1.0,0.0);

	if(model != NULL)
		model->render();

	glPopMatrix();

}

bool Entity::canSee(Entity* other, Map* map) {
	if(distanceBetween(other->boundingSphere.center, boundingSphere.center) < vision) {
		Point2D a      = other->boundingSphere.center.toPoint2D();
		Point2D b      = boundingSphere.center.toPoint2D();
		Point2D c      = projectPoint(boundingSphere.center,yaw,pitch,vision).toPoint2D();
		float   angle  = angleBetween(a,b,c);
		if(abs(angle) < (FOV/2))
			return true;
	}
	return false;
}
