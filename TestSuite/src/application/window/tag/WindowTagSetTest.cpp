#include "WindowTagSetTest.h"

WindowTagSetTest::WindowTagSetTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, windowClass(), tag{ "tag set by function" }
{
	initialiseWindowClass();
}

WindowTagSetTest::~WindowTagSetTest()
{
}

std::string WindowTagSetTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		nCmdShow
	};

	unit.initialise(windowClass);
	unit.setTag(tag);

	std::wstring title = getWindowTitle(unit.getWindow());

	if (std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag) == title)
	{
		return std::string();
	}

	return "window tag set test failed\n";
}

HRESULT WindowTagSetTest::initialiseWindowClass()
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = L"window tag set test";

	if (RegisterClassEx(&windowClass))
	{
		return S_OK;
	}

	return E_FAIL;
}

LRESULT WindowTagSetTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}

std::wstring WindowTagSetTest::getWindowTitle(HWND window)
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
