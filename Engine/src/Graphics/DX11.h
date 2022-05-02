#pragma once
#include <d3d11.h>
#include <wrl/client.h>

using namespace Microsoft::WRL;

class DX11
{
public:
	static bool Initialize(HWND hwnd);
	static bool RenderFrame();

	static ComPtr<ID3D11Device> myDevice;
	static ComPtr<ID3D11DeviceContext> myContext;
	static ComPtr<IDXGISwapChain> mySwapChain;
	static ComPtr<ID3D11RenderTargetView> myRenderTargetView;
};

