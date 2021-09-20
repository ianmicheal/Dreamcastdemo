#ifndef OBJ__H
#define OBJ__H

#include <vector>
#include <fstream>

#include "opengl.h"
#include "point.h"
#include "model.h"
#include "texture_manager.h"

class OBJTextCoord {
    public:
        float u,v;

        OBJTextCoord(float,float);
};
class OBJVertex {
    public:
        Point3D position;
};

class OBJFace {
    public:
        int vertexIndecies[3];
        int uvIndecies[3];
        int normalIndecies[3];

        OBJFace(int,int,int,
                int,int,int,
                int,int,int);
};

class OBJGroup {
    public:
        std::vector<OBJFace> faces;
        std::string          material;
};

class OBJTexture {
    public:
        std::string name;
        std::string file;
        int         textureIndex;
        OBJTexture(std::string file);
        bool load(std::string);
};

class OBJMaterial {
    public:
        std::vector<OBJTexture> textures;

};

class Obj : public Model {
    public:
        std::vector<Point3D>      verticies;
        std::vector<OBJTextCoord> uvs;
        std::vector<Point3D>      normals;
        std::vector<OBJGroup>     groups;
        OBJMaterial               material;

	Obj();
	Obj(std::string fileName);
        virtual void load(std::string filename);
        virtual void render();

};

#endif
