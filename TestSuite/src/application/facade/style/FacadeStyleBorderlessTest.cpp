#include "FacadeStyleBorderlessTest.h"

FacadeStyleBorderlessTest::FacadeStyleBorderlessTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeStyleBorderlessTest::~FacadeStyleBorderlessTest()
{
}

std::string FacadeStyleBorderlessTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade style borderless test"
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

	return "facade style borderless test failed\n";
}
