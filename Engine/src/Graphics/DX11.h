#pragma once
#include <d3d11.h>
#include <wrl/client.h>
#include "Shaders.h"
#include "Vertex.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

using namespace Microsoft::WRL;

class DX11
{
public:
	static bool Initialize(HWND hwnd);
	static bool RenderFrame();

	static ComPtr<ID3D11Device> myDevice;
	static ComPtr<ID3D11DeviceContext> myContext;
	static ComPtr<IDXGISwapChain> mySwapChain;
	
private:
	static bool CreateDeviceAndSwapChain(HWND hwnd);
	static bool CreateRenderTargetView();
	static bool CreateDepthStencil();
	static bool CreateRasterizer();
	static bool CreateShaders();

	static bool CreateTriangle();

	static VertexShader myVertexShader;
	static PixelShader myPixelShader;
	static VertexBuffer<Vertex> myVertexBuffer;
	static IndexBuffer myIndexBuffer;

	static ComPtr<ID3D11RenderTargetView> myRenderTargetView;
	static ComPtr<ID3D11DepthStencilView> myDepthStencilView;
	static ComPtr<ID3D11Texture2D> myDepthStencilBuffer;
	static ComPtr<ID3D11DepthStencilState> myDepthStencilState;
	static ComPtr<ID3D11RasterizerState> myRasterizerState;
};

