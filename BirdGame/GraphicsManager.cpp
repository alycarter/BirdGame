#include "GraphicsManager.h"

// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")


GraphicsManager::GraphicsManager()
{
}


GraphicsManager::~GraphicsManager()
{
}

void GraphicsManager::create(Window * window, unsigned int textureWidthIn, unsigned int textureHeightIn, unsigned int textureSlotsIn)
{
	//set up the directx contexts
	createDirectXContext(window);
	//create the render buffers
	createRenderTarget();
	//set up the viewport
	setUpViewPort();
}

void GraphicsManager::createDirectXContext(Window * window)
{
	//set the resolution of the window
	resolutionX = window->getWidth();
	resolutionY = window->getHeight();
	// create a struct to hold information about the swap chain
    DXGI_SWAP_CHAIN_DESC scd;
    // clear out the struct for use
    ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));
    // fill the swap chain description struct
    scd.BufferCount = 1;                                    // one back buffer
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
	scd.OutputWindow = window->getWindowHandle();           // the window to be used
    scd.SampleDesc.Count = 4;                               // how many multisamples
    scd.Windowed = TRUE;                                    // windowed/full-screen mode
    // create a device, device context and swap chain using the information in the scd struct
    D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL, D3D11_SDK_VERSION, &scd, &swapchain, &dev, NULL, &devcon);
	// select which primtive type we are using
	devcon->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

void GraphicsManager::createRenderTarget()
{
	// get the address of the back buffer
	ID3D11Texture2D *pBackBuffer;
	swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	// use the back buffer address to create the render target
	dev->CreateRenderTargetView(pBackBuffer, NULL, &backbuffer);
	pBackBuffer->Release();
	// set the render target as the back buffer
	devcon->OMSetRenderTargets(1, &backbuffer, NULL);
}

void GraphicsManager::setUpViewPort()
{
	// Set the viewport
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.Width = (float)resolutionX;
	viewport.Height = (float)resolutionY;
	viewport.MinDepth = 0;    // the closest an object can be on the depth buffer is 0.0
	viewport.MaxDepth = 1;    // the farthest an object can be on the depth buffer is 1.0
	devcon->RSSetViewports(1, &viewport);
}

void GraphicsManager::clearBuffer()
{
	//clear the depth and render buffers
	devcon->ClearRenderTargetView(backbuffer, *clearColor);
	devcon->ClearDepthStencilView(zbuffer, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void GraphicsManager::setClearColor(float r, float g, float b, float a)
{
	//set the clear colour channels
	clearColor->r = r;
	clearColor->g = g;
	clearColor->b = b;
	clearColor->a = a;
}