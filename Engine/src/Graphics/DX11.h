#pragma once
#include <d3d11.h>
#include <wrl/client.h>
#include "Shaders.h"
#include "Vertex.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ConstantBuffer.h"
#include "Camera.h"

using namespace Microsoft::WRL;

class DX11
{
public:
	bool Initialize(HWND hwnd);
	bool RenderFrame();
	DX11& Get() const { return *myInstance; };

	static ComPtr<ID3D11Device> myDevice;
	static ComPtr<ID3D11DeviceContext> myContext;
	static ComPtr<IDXGISwapChain> mySwapChain;
	
private:
	bool CreateDeviceAndSwapChain(HWND hwnd);
	bool CreateRenderTargetView();
	bool CreateDepthStencil();
	bool CreateRasterizer();
	bool CreateShaders();
	bool CreateConstantBuffers();

	bool CreateSquare();

	VertexShader myVertexShader;
	PixelShader myPixelShader;
	VertexBuffer<Vertex> myVertexBuffer;
	IndexBuffer myIndexBuffer;
	ConstantBuffer<VSMatrix> myConstantBuffer;

	ComPtr<ID3D11RenderTargetView> myRenderTargetView;
	ComPtr<ID3D11DepthStencilView> myDepthStencilView;
	ComPtr<ID3D11Texture2D> myDepthStencilBuffer;
	ComPtr<ID3D11DepthStencilState> myDepthStencilState;
	ComPtr<ID3D11RasterizerState> myRasterizerState;

	Camera myMainCamera;

	DX11* myInstance = nullptr;
};

