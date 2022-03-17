#include "FacadeWindowParameterTest.h"

FacadeWindowParameterTest::FacadeWindowParameterTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, tag{ "facade window parameter test" }
{
}

FacadeWindowParameterTest::~FacadeWindowParameterTest()
{
}

std::string FacadeWindowParameterTest::test()
{
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		tag
	);

	std::wstring windowTitle = getWindowTitle(unit->getWindow());

	delete unit;
	unit = nullptr;

	if (std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag) == windowTitle)
	{
		return std::string();
	}

	return "facade windows parameter test failed\n";
}

std::wstring FacadeWindowParameterTest::getWindowTitle(HWND window)
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
