#include "WindowResolutionDefaultTest.h"

WindowResolutionDefaultTest::WindowResolutionDefaultTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, windowClass()
{
	initialiseWindowClass();
}

WindowResolutionDefaultTest::~WindowResolutionDefaultTest()
{
}

std::string WindowResolutionDefaultTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		nCmdShow
	};

	unit.initialise(windowClass);
	WindowsPlatform::Vector2 window = windowResolution(unit.getWindow());

	WindowsPlatform::Vector2 resolution{
		960.0f,
		540.0f
	};

	if (window == resolution)
	{
		return std::string();
	}

	return "window resolution default test failed\n";
}

HRESULT WindowResolutionDefaultTest::initialiseWindowClass()
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = L"window resolution default test";

	if (RegisterClassEx(&windowClass))
	{
		return S_OK;
	}

	return E_FAIL;
}

LRESULT WindowResolutionDefaultTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

WindowsPlatform::Vector2 WindowResolutionDefaultTest::windowResolution(HWND window)
{
	RECT windowRect;

	GetClientRect(
		window,
		&windowRect
	);

	return WindowsPlatform::Vector2{
		(float)(windowRect.right - windowRect.left),
		(float)(windowRect.bottom - windowRect.top)
	};
}
