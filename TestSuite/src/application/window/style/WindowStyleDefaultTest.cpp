#include "WindowStyleDefaultTest.h"

WindowStyleDefaultTest::WindowStyleDefaultTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, windowClass()
{
	initialiseWindowClass();
}

WindowStyleDefaultTest::~WindowStyleDefaultTest()
{
}

std::string WindowStyleDefaultTest::test()
{
	windowsPlatform::Window unit{
		nCmdShow
	};

	unit.initialise(windowClass);

	DWORD style = (DWORD)GetWindowLongPtr(
		unit.getWindow(),
		GWL_STYLE
	);

	DWORD windowed{ WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION };

	if ((style & windowed) == windowed)
	{
		return std::string();
	}

	return "windows style default test failed\n";
}

HRESULT WindowStyleDefaultTest::initialiseWindowClass()
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = L"window style default test";

	if (RegisterClassEx(&windowClass))
	{
		return S_OK;
	}

	return E_FAIL;
}

LRESULT WindowStyleDefaultTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}
