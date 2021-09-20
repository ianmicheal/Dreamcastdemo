#ifndef __MD5__H
#define __MD5__H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#include <SDL/SDL.h>

#include "quaternion.h"
#include "point.h"
#include "texture_manager.h"
#include "model.h"

class MD5Joint {
public:
	std::string name;
	int         parent; 

	Point3D     position;
	Quaternion  orientation;
    MD5Joint(std::string,int,Point3D,Quaternion);
};

class MD5Vertex {
public:
	Point2D     st; 
	
	int         start;
	int         count;
};

class MD5Triangle {
public:
	int         index[3];
};

class MD5Weight {
public:
	int         joint;
	float       bias;

	Point3D     position;
};

class MD5BoundingBox {
public:
	Point3D     min;
	Point3D     max;	
};

class MD5Mesh {
public:
	std::vector<MD5Vertex>     verticies;
	std::vector<MD5Triangle>   triangles;
	std::vector<MD5Weight>     weights;
	
	std::string             shader;
    int                     textureIndex;
};

class MD5Model : public Model {
public:
	std::vector<MD5Joint>      skeleton;
	std::vector<MD5Mesh>       meshes;
	bool                       loaded;

	void  render();
	void  load(std::string);

	MD5Model();
	MD5Model(std::string);
	
};

class Animation {
public:
	std::vector<MD5Joint>         frames;
	std::vector<MD5BoundingBox>   bounding_boxes;
};

class AnimationInfo {
public:  
	int     current_frame;
	int     next_frame;

	double  last_time;
	double  max_time;
};

#endif