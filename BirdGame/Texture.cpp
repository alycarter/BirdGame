#include "Texture.h"

Texture::Texture()
{
	setType(RESOURCE_TYPE_TEXTURE);
	textureIndex = 0;
}

Texture::~Texture()
{
}

void Texture::setTexture(unsigned int textureIndexIn, char * data)
{
	textureIndex = textureIndexIn;
	textureData = data;
}

char * Texture::getTextureData()
{
	return textureData;
}

unsigned int Texture::getTextureIndex()
{
	return textureIndex;
}