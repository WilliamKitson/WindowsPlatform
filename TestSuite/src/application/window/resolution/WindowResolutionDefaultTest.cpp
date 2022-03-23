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
	windowsPlatform::ApplicationWindow unit{
		nCmdShow
	};

	unit.initialise(windowClass);

	windowsPlatform::Vector2 resolution{
		960.0f,
		540.0f
	};

	if (windowResolution(unit.getWindow()) == resolution)
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

windowsPlatform::Vector2 WindowResolutionDefaultTest::windowResolution(HWND window)
{
	RECT windowRect;

	GetClientRect(
		window,
		&windowRect
	);

	return windowsPlatform::Vector2{
		(float)(windowRect.right - windowRect.left),
		(float)(windowRect.bottom - windowRect.top)
	};
}
