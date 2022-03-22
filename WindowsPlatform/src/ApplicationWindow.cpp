#include "ApplicationWindow.h"

WindowsPlatform::ApplicationWindow::ApplicationWindow(int value)
    : nCmdShow{ value }, window()
{
}

WindowsPlatform::ApplicationWindow::~ApplicationWindow()
{
	DestroyWindow(window);
}

void WindowsPlatform::ApplicationWindow::initialise(WNDCLASSEX windowClass)
{
	initialiseWindow(windowClass);
}

void WindowsPlatform::ApplicationWindow::borderless()
{
	SetWindowLongPtr(
		window,
		GWL_STYLE,
		WS_POPUPWINDOW
	);

	ShowWindow(
		window,
		nCmdShow
	);
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

void WindowsPlatform::ApplicationWindow::setResolution(Vector2 value)
{
	RECT windowRect = getWindowRectangle(value);

	if (!AdjustWindowRect(&windowRect, (DWORD)GetWindowLongPtr(window, GWL_STYLE), FALSE))
	{
		return;
	}

	if (window)
	{
		MoveWindow(
			window,
			100,
			100,
			windowRect.right - windowRect.left,
			windowRect.bottom - windowRect.top,
			true
		);
	}
}

HRESULT WindowsPlatform::ApplicationWindow::initialiseWindow(WNDCLASSEX windowClass)
{
	RECT windowRect = getWindowRectangle(Vector2());

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

RECT WindowsPlatform::ApplicationWindow::getWindowRectangle(Vector2 value)
{
	ResolutionValidator resolution;
	resolution.setResolution((int)value.x, (int)value.y);

	RECT windowRect = {
		0,
		0,
		resolution.getWidth(),
		resolution.getHeight()
	};

	return windowRect;
}
