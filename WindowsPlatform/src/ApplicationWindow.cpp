#include "ApplicationWindow.h"

windowsPlatform::ApplicationWindow::ApplicationWindow(int value)
    : nCmdShow{ value }, window()
{
}

windowsPlatform::ApplicationWindow::~ApplicationWindow()
{
	DestroyWindow(window);
}

void windowsPlatform::ApplicationWindow::initialise(WNDCLASSEX windowClass)
{
	RECT windowRect = getWindowRectangle(Vector2());

	if (!AdjustWindowRect(&windowRect, getWindowed(), FALSE))
	{
		return;
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
		return;
	}

	if (ShowWindow(window, nCmdShow))
	{
		return;
	}

	return;
}

void windowsPlatform::ApplicationWindow::borderless()
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

void windowsPlatform::ApplicationWindow::windowed()
{
	SetWindowLongPtr(
		window,
		GWL_STYLE,
		getWindowed()
	);

	ShowWindow(
		window,
		nCmdShow
	);
}

HWND windowsPlatform::ApplicationWindow::getWindow()
{
    return window;
}

void windowsPlatform::ApplicationWindow::setTag(std::string value)
{
	SetWindowTextA(
		window,
		value.c_str()
	);
}

void windowsPlatform::ApplicationWindow::setResolution(Vector2 value)
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

DWORD windowsPlatform::ApplicationWindow::getWindowed()
{
	return WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION;
}

std::wstring windowsPlatform::ApplicationWindow::getTag(WNDCLASSEX windowClass)
{
	return windowClass.lpszClassName;
}

RECT windowsPlatform::ApplicationWindow::getWindowRectangle(Vector2 value)
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
