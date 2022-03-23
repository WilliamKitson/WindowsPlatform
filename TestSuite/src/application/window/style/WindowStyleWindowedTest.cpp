#include "WindowStyleWindowedTest.h"

WindowStyleWindowedTest::WindowStyleWindowedTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, windowClass()
{
	initialiseWindowClass();
}

WindowStyleWindowedTest::~WindowStyleWindowedTest()
{
}

std::string WindowStyleWindowedTest::test()
{
	windowsPlatform::ApplicationWindow unit{
		nCmdShow
	};

	unit.initialise(windowClass);
	unit.borderless();
	unit.windowed();

	DWORD style = (DWORD)GetWindowLongPtr(
		unit.getWindow(),
		GWL_STYLE
	);

	DWORD windowed{ WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION };

	if ((style & windowed) == windowed)
	{
		return std::string();
	}

	return "window style windowed test failed\n";
}

HRESULT WindowStyleWindowedTest::initialiseWindowClass()
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = L"window style windowed test";

	if (RegisterClassEx(&windowClass))
	{
		return S_OK;
	}

	return E_FAIL;
}

LRESULT WindowStyleWindowedTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}
