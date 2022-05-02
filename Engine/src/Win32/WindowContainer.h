#pragma once
#include <windows.h>
#include <string>

void PrintCSBackupAPIErrorMessage(DWORD dwErr);

class WindowContainer
{
public:
	WindowContainer() = default;
	~WindowContainer() = default;
	bool Initialize(HINSTANCE ahInstance, const int& aWidth, const int& aHeight, 
		std::string aWindowTitle = "DirectX Experimental", const std::string& aWindowClass = "DirectX Experimental");
	bool ProcessMessages();
	HWND GetWindowHandle() const { return myHandle; };

private:
	HWND myHandle;
	HINSTANCE myHInstance;
	std::string myWindowTitle;
	std::wstring myWindowTitleWide;
	std::string myWindowClass;
	std::wstring myWindowClassWide;
	int myWindowWidth;
	int myWindowHeight;
};

