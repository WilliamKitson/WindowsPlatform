#include "WindowTagInitialiseTest.h"

WindowTagInitialiseTest::WindowTagInitialiseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, windowClass(), tag{ L"window tag initialise test" }
{
	initialiseWindowClass();
}

WindowTagInitialiseTest::~WindowTagInitialiseTest()
{
}

std::string WindowTagInitialiseTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		nCmdShow
	};

	unit.initialise(windowClass);
	std::wstring title = getWindowTitle(unit.getWindow());

	if (tag == title)
	{
		return std::string();
	}

	return "window tag initialise test failed\n";
}

HRESULT WindowTagInitialiseTest::initialiseWindowClass()
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = tag.c_str();

	if (RegisterClassEx(&windowClass))
	{
		return S_OK;
	}

	return E_FAIL;
}

LRESULT WindowTagInitialiseTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

std::wstring WindowTagInitialiseTest::getWindowTitle(HWND window)
{
	int size = GetWindowTextLength(window);
	size++;

	std::vector<wchar_t> buffer(size);

	GetWindowText(
		window,
		&buffer[0],
		size
	);

	std::wstring title = &buffer[0];
	return title;
}
