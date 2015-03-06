#pragma once
#include "GraphicsResource.h"
class Texture :
	public GraphicsResource
{
public:
	Texture();
	~Texture();
	void setTexture(unsigned int textureIndexIn, char * data);
	unsigned int getTextureIndex();
	char * getTextureData();
private:
	unsigned int textureIndex;
	char * textureData;
};

