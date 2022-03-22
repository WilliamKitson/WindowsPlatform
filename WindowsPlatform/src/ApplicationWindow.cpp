#include "ApplicationWindow.h"

WindowsPlatform::ApplicationWindow::ApplicationWindow(int value)
    : nCmdShow{ value }, window()
{
}

WindowsPlatform::ApplicationWindow::~ApplicationWindow()
{
}

void WindowsPlatform::ApplicationWindow::initialise(WNDCLASSEX windowClass)
{
	initialiseWindow(windowClass);
}

HWND WindowsPlatform::ApplicationWindow::getWindow()
{
    return window;
}

void WindowsPlatform::ApplicationWindow::setTag(std::string value)
{
	SetWindowTextA(
		window,
		value.c_str()
	);
}

HRESULT WindowsPlatform::ApplicationWindow::initialiseWindow(WNDCLASSEX windowClass)
{
	RECT windowRect{
		0,
		0,
		500,
		500
	};

	if (!AdjustWindowRect(&windowRect, getWindowed(), FALSE))
	{
		return E_FAIL;
	}

	window = CreateWindow(
		getTag(windowClass).c_str(),
		getTag(windowClass).c_str(),
		getWindowed(),
		100,
		100,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		NULL,
		NULL,
		windowClass.hInstance,
		NULL
	);

	if (!window)
	{
		return E_FAIL;
	}

	if (ShowWindow(window, nCmdShow))
	{
		return E_FAIL;
	}

	return S_OK;
}

DWORD WindowsPlatform::ApplicationWindow::getWindowed()
{
	return WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION;
}

std::wstring WindowsPlatform::ApplicationWindow::getTag(WNDCLASSEX windowClass)
{
	return windowClass.lpszClassName;
}
