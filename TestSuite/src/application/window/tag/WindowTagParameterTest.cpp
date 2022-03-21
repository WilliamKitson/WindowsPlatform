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
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		tag
	);

	std::wstring title = getWindowTitle(unit->getWindow());

	delete unit;
	unit = nullptr;

	if (std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag) == title)
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
