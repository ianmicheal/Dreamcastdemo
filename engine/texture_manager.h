#ifndef TEXTURE_MANAGER__H
#define TEXTURE_MANAGER__H

#include <iostream>
#include <vector>

#include "bmp.h"

class  Texture {
	public:
		std::string name;
		int         index;
		
		Texture(std::string,int);
};

class TextureManager {
	public:
		static int get(std::string name);
};
	
#endif
