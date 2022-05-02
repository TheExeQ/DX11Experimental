#include "Win32/WindowContainer.h"
#include "Graphics/DX11.h"

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
	window.Initialize(hInstance, WindowWidth, WindowHeight);

	// Initialize DirectX
	DX11::Initialize(window.GetWindowHandle());

	// Run the message loop
	while (window.ProcessMessages())
	{
		DX11::RenderFrame();
	}

	return 0;
}