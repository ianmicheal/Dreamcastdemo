#include "texture_manager.h"

using namespace std;

std::vector<Texture> textures;

Texture::Texture(string nameIn,int indexIn) {
	name  = nameIn;
	index = indexIn;
}

int TextureManager::get(string nameIn) {
	for(int t = 0; t < textures.size(); t++) {
		if(textures[t].name == nameIn) {
			return textures[t].index;
		}
	}

	int newIndex = loadBMP(nameIn.c_str());
	if(newIndex == -1) {
		return get("default.bmp");
	}
	else {
		textures.push_back(Texture(nameIn,newIndex));
		return newIndex;
	}
}
