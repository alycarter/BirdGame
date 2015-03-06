#pragma once
#include "Object.h"

#include <vector>
using namespace std;

#include <DirectXMath.h>
using namespace DirectX;
#include <DirectXColors.h>
using namespace DirectX::Colors;
#include <d3d11.h>

#include "GraphicsResource.h"

struct IWICImagingFactory;
class Window;
class State;
class Texture;
class Mesh;

class GraphicsManager :
	public Object
{
public:
	GraphicsManager();
	~GraphicsManager();
	void create(Window * window, unsigned int textureWidth, unsigned int textureHeight);//creates the graphics context
	void swapBuffers();//swaps the buffers in the swap buffer
	void clearBuffer();//clear the current buffer
	void setClearColor(float r, float g, float b, float a);//sets the background colour on clear
	unsigned int getGraphicsResourceID(RESOURCE_TYPE resourceType, char * resourceName);
	unsigned int getTextureID(unsigned int textureResourceID);
	void bindShader(unsigned int shaderResourceID);
	unsigned int createMeshResourceFromFile(char * resourceName, char * file, State * boundState);
	unsigned int createTextureResourceFromFile(char * resourceName, LPWSTR file, State * boundState);
	unsigned int createShaderResourceFromFile(char * resourceName, LPWSTR file, char * fileName, State * boundState);
	void setConstantBufferData(void * data, unsigned int size);
	void setInstanceBufferData(void * data, unsigned int size, unsigned int stride);
	void drawMesh(unsigned int meshResourceID, unsigned int count);
private:
	void createDirectXContext(Window * window);//sets up the directx context
	void createRenderTarget();// creates the swap chain
	void createDepthBuffer();
	void setUpViewPort();// sets up the viewport
	unsigned int getFreeGraphicsResourceSlot();
	unsigned int getFreeTextureSlot();
	void writeTexture(Texture * texture);
	void fitMeshInFreeSpace(Mesh * mesh);
	void fitMeshInVertexSpace(Mesh * mesh);
	void fitMeshInIndexSpace(Mesh * mesh);
	void resizeTextureArray();
	void resizeConstantBuffer();
	void resizeInstanceBuffer();
	void resizeVertexBuffer();
	void resizeIndexBuffer();
	vector<GraphicsResource *> graphicsResources;
	IDXGISwapChain *swapchain;// the pointer to the swap chain interface
	ID3D11Device *dev;// the pointer to the Direct3D device interface (creating things)
	ID3D11DeviceContext *devcon;// the pointer to the Direct3D device context (rendering things)
	ID3D11RenderTargetView *backBuffer;//back buffer to draw to
	ID3D11DepthStencilView *depthBuffer;// the pointer to our depth buffer
	ID3D11Buffer *vertexBuffer;// the pointer to the vertex buffer
	ID3D11Buffer *constantBuffer;// the pointer to the constant buffer
	ID3D11Buffer *indexBuffer;// the pointer to the index buffer
	ID3D11Buffer *instanceBuffer;// the pointer to the instance buffer
	ID3D11Texture2D * textureResource;//pointer to the texture data behind the shader view
	ID3D11ShaderResourceView * textureShaderView;// the pointer to the texture shader view
	IWICImagingFactory * factory;//factory for creating textures 
	XMVECTORF32 clearColor;//color to clear the screen to
	XMFLOAT2 screenResolution;
	XMFLOAT2 textureResolution;
	unsigned int textureBufferSize;
	unsigned int constantBufferSize;
	unsigned int instanceBufferSize;
	unsigned int vertexBufferSize;
	unsigned int indexBufferSize;

};

