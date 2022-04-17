#include "WindowResolutionSetTest.h"

WindowResolutionSetTest::WindowResolutionSetTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, windowClass(), resolution()
{
	initialiseWindowClass();

	resolution = windowsPlatform::Vector2{
		1000.0f,
		1000.0f
	};
}

WindowResolutionSetTest::~WindowResolutionSetTest()
{
}

std::string WindowResolutionSetTest::test()
{
	windowsPlatform::Window unit{
	nCmdShow
	};

	unit.initialise(windowClass);
	unit.setResolution(resolution);

	if (windowResolution(unit.getWindow()) == resolution)
	{
		return std::string();
	}

	return "window resolution set test failed\n";
}

HRESULT WindowResolutionSetTest::initialiseWindowClass()
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = L"window resolution set test";

	if (RegisterClassEx(&windowClass))
	{
		return S_OK;
	}

	return E_FAIL;
}

LRESULT WindowResolutionSetTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

windowsPlatform::Vector2 WindowResolutionSetTest::windowResolution(HWND window)
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
