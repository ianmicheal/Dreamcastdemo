#include "model.h"

Model::Model() {
	#ifdef _arch_dreamcast
		directory = "/cd/";
	#else
		directory = "";
	#endif
}

void Model::render() {

}

void Model::load(std::string modelName) {

}
