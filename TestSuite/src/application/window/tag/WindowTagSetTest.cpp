#include "WindowTagSetTest.h"

WindowTagSetTest::WindowTagSetTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, tag{ "set test" }
{
}

WindowTagSetTest::~WindowTagSetTest()
{
}

std::string WindowTagSetTest::test()
{
	WindowsPlatform::SubordinateImplimentation unit{
		hInstance,
		nCmdShow,
		"window tag set test"
	};

	unit.setTag(tag);

	if (std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag) == getWindowTitle(unit.getWindow()))
	{
		return std::string();
	}

	return "window tag set test failed\n";
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
