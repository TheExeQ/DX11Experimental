#include "Win32/WindowContainer.h"
#include "Graphics/DX11.h"
#include <iostream>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	// Create Console Window
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	// Initialize Win32 Application
	int WindowWidth = 1280;
	int WindowHeight = 720;

	WindowContainer window;
	auto result = window.Initialize(hInstance, WindowWidth, WindowHeight);
	if (!result)
	{
		std::cout << "Failed to initialize Win32" << std::endl;
		std::cin.get();
		return 0;
	}

	// Initialize DirectX
	DX11 directX;
	result = directX.Initialize(window.GetWindowHandle());
	if (!result)
	{
		std::cout << "Failed to initialize DirectX" << std::endl;
		std::cin.get();
		return 0;
	}

	// Run the message loop
	while (window.ProcessMessages())
	{
		directX.RenderFrame();
	}

	return 0;
}