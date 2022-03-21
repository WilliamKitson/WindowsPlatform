#include "FacadeTagSetTest.h"

FacadeTagSetTest::FacadeTagSetTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, tag{ "set test" }
{
}

FacadeTagSetTest::~FacadeTagSetTest()
{
}

std::string FacadeTagSetTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade tag set test"
	);

	unit->setTag(tag);
	std::wstring title = getWindowTitle(unit->getWindow());

	delete unit;
	unit = nullptr;

	if (std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag) == title)
	{
		return std::string();
	}

	return "facade tag set test failed\n";
}

std::wstring FacadeTagSetTest::getWindowTitle(HWND window)
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
