#include "WindowTagParameterTest.h"

WindowTagParameterTest::WindowTagParameterTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, tag{ "window tag parameter test" }
{
}

WindowTagParameterTest::~WindowTagParameterTest()
{
}

std::string WindowTagParameterTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		tag
	};

	if (std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag) == getWindowTitle(unit.getWindow()))
	{
		return std::string();
	}

	return "window tag parameter test failed\n";
}

std::wstring WindowTagParameterTest::getWindowTitle(HWND window)
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
