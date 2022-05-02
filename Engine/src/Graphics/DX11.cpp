#include "DX11.h"
#include <iostream>

ComPtr<ID3D11Device> DX11::myDevice = nullptr;
ComPtr<ID3D11DeviceContext> DX11::myContext = nullptr;
ComPtr<IDXGISwapChain> DX11::mySwapChain = nullptr;
ComPtr<ID3D11RenderTargetView> DX11::myRenderTargetView = nullptr;

bool DX11::Initialize(HWND hwnd)
{
	// Settings for SwapChain
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = 1280;
	swapChainDesc.BufferDesc.Height = 720;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hwnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.Windowed = TRUE;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	
	// Create the SwapChain
	HRESULT result = 
	D3D11CreateDeviceAndSwapChain(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		D3D11_CREATE_DEVICE_DEBUG,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&swapChainDesc,
		&mySwapChain,
		&myDevice,
		NULL,
		&myContext
	);

	if (FAILED(result))
	{
		std::cout << "Failed to create device and swap chain" << std::endl;
		return false;
	}

	// Get the back buffer from the swap chain
	ID3D11Texture2D* backBuffer;
	result = mySwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
	if (FAILED(result))
	{
		std::cout << "Failed to get back buffer" << std::endl;
		return false;
	}
	
	// Create the render target view with the back buffer
	D3D11_RENDER_TARGET_VIEW_DESC rtvd;
	ZeroMemory(&rtvd, sizeof(rtvd));
	rtvd.Format = swapChainDesc.BufferDesc.Format;
	rtvd.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	rtvd.Texture2D.MipSlice = 0;

	result = myDevice->CreateRenderTargetView(backBuffer, &rtvd, myRenderTargetView.GetAddressOf());
	if (FAILED(result))
	{
		std::cout << "Failed to create render target view" << std::endl;
		return false;
	}

	backBuffer->Release();

	std::cout << "Successfully initialized DirectX!" << std::endl;
	return true;
}

bool DX11::RenderFrame()
{
	const float clearColor[4] = { 0.8f, 0.8f, 0.8f, 1.0f };

	myContext->OMSetRenderTargets(1, myRenderTargetView.GetAddressOf(), NULL);
	myContext->ClearRenderTargetView(myRenderTargetView.Get(), clearColor);

	mySwapChain->Present(1, NULL);
	return true;
}
