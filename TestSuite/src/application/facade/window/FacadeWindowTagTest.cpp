#include "FacadeWindowTagTest.h"

FacadeWindowTagTest::FacadeWindowTagTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, tag{ "tag set by function" }
{
}

FacadeWindowTagTest::~FacadeWindowTagTest()
{
}

std::string FacadeWindowTagTest::test()
{
	windowsPlatform::Facade* unit = new windowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window tag test"
	);

	unit->setTag(tag);

	std::wstring title = getWindowTitle(unit->getWindow());

	delete unit;
	unit = nullptr;

	if (std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag) == title)
	{
		return std::string();
	}

	return "facade window tag test failed\n";
}

std::wstring FacadeWindowTagTest::getWindowTitle(HWND window)
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
