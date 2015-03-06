#pragma once
#include "GraphicsResource.h"

class Mesh :
	public GraphicsResource
{
public:
	Mesh();
	~Mesh();
	unsigned int getVertexCount();
	unsigned int getVertexOffset();
	unsigned int getIndexCount();
	unsigned int getIndexOffset();
	void set(unsigned int vertexOffsetIn, unsigned int vertexCountIn, unsigned int indexOffsetIn, unsigned int indexCountIn);
	void setVertexOffset(unsigned int vertexOffsetIn);
	void setVertexCount(unsigned int vertexCountIn);
	void setIndexOffset(unsigned int indexOffsetIn);
	void setIndexCount(unsigned int indexCountIn);
private:
	unsigned int vertexOffset;
	unsigned int indexOffset;
	unsigned int vertexCount;
	unsigned int indexCount;
};

