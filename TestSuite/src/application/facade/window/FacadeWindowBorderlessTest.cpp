#include "FacadeWindowBorderlessTest.h"

FacadeWindowBorderlessTest::FacadeWindowBorderlessTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeWindowBorderlessTest::~FacadeWindowBorderlessTest()
{
}

std::string FacadeWindowBorderlessTest::test()
{
	windowsPlatform::Facade* unit = new windowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window borderless test"
	);

	unit->setBorderless();

	DWORD style = (DWORD)GetWindowLongPtr(
		unit->getWindow(),
		GWL_STYLE
	);

	delete unit;
	unit = nullptr;

	if ((style & WS_POPUPWINDOW) == WS_POPUPWINDOW)
	{
		return std::string();
	}

	return "facade window borderless test failed\n";
}
