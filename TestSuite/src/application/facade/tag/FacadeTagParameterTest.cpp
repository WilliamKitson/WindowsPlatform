#include "FacadeTagParameterTest.h"

FacadeTagParameterTest::FacadeTagParameterTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, tag{ "facade tag parameter test" }
{
}

FacadeTagParameterTest::~FacadeTagParameterTest()
{
}

std::string FacadeTagParameterTest::test()
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

	return "facade tag parameter test failed\n";
}

std::wstring FacadeTagParameterTest::getWindowTitle(HWND window)
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
