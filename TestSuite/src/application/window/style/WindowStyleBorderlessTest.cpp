#include "WindowStyleBorderlessTest.h"

WindowStyleBorderlessTest::WindowStyleBorderlessTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, windowClass()
{
	initialiseWindowClass();
}

WindowStyleBorderlessTest::~WindowStyleBorderlessTest()
{
}

std::string WindowStyleBorderlessTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		nCmdShow
	};

	unit.initialise(windowClass);
	unit.borderless();

	DWORD style = (DWORD)GetWindowLongPtr(
		unit.getWindow(),
		GWL_STYLE
	);

	if ((style & WS_POPUPWINDOW) == WS_POPUPWINDOW)
	{
		return std::string();
	}

	return "window style borderless test failed\n";
}

HRESULT WindowStyleBorderlessTest::initialiseWindowClass()
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = L"window style borderless test";

	if (RegisterClassEx(&windowClass))
	{
		return S_OK;
	}

	return E_FAIL;
}

LRESULT WindowStyleBorderlessTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}
