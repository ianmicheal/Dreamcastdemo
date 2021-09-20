#ifndef __MODEL__H
#define __MODEL__H

#include <iostream>

class Model {
	public:
		std::string  directory;
		Model();	
		virtual void render();
		virtual void load(std::string modelName);
		
};

#endif
