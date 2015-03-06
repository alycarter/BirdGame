#include "Mesh.h"


Mesh::Mesh()
{
	setType(RESOURCE_TYPE_MESH);
	vertexOffset = 0;
	indexOffset = 0;
	vertexCount = 0;
	indexCount = 0;
}

Mesh::~Mesh()
{

}

unsigned int Mesh::getVertexCount()
{
	return vertexCount;
}

unsigned int Mesh::getVertexOffset()
{
	return vertexOffset;
}

unsigned int Mesh::getIndexCount()
{
	return indexCount;
}

unsigned int Mesh::getIndexOffset()
{
	return indexOffset;
}

void Mesh::set(unsigned int vertexOffsetIn, unsigned int vertexCountIn, unsigned int indexOffsetIn, unsigned int indexCountIn)
{
	setIndexCount(indexCountIn);
	setIndexOffset(indexOffsetIn);
	setVertexCount(vertexCountIn);
	setVertexOffset(vertexOffsetIn);
}

void Mesh::setVertexOffset(unsigned int vertexOffsetIn)
{
	vertexOffset = vertexOffsetIn;
}

void Mesh::setVertexCount(unsigned int vertexCountIn)
{
	vertexCount = vertexCountIn;
}

void Mesh::setIndexOffset(unsigned int indexOffsetIn)
{
	indexOffset = indexOffsetIn;
}

void Mesh::setIndexCount(unsigned int indexCountIn)
{
	indexCount = indexCountIn;
}