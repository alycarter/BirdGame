#pragma once
#include "Object.h"

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>

class Window;

class GraphicsManager :
	public Object
{
public:
	GraphicsManager();
	~GraphicsManager();
	void create(Window * window, unsigned int textureWidth, unsigned int textureHeight, unsigned int textureSlots);//creates the graphics context
	void swapBuffers();//swaps the buffers in the swap buffer
	void clearBuffer();//clear the current buffer
	void setClearColor(float r, float g, float b, float a);//sets the background colour on clear
private:
	void createDirectXContext(Window * window);//sets up the directx context
	void createRenderTarget();// creates the swap chain
	void setUpViewPort();// sets up the viewport
	IDXGISwapChain *swapchain;// the pointer to the swap chain interface
	ID3D11Device *dev;// the pointer to the Direct3D device interface (creating things)
	ID3D11DeviceContext *devcon;// the pointer to the Direct3D device context (rendering things)
	ID3D11RenderTargetView *backbuffer;// global declaration
	D3DXCOLOR * clearColor;//color to clear the screen to

};

