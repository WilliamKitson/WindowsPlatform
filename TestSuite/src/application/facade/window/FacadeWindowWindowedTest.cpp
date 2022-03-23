#include "FacadeWindowWindowedTest.h"

FacadeWindowWindowedTest::FacadeWindowWindowedTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeWindowWindowedTest::~FacadeWindowWindowedTest()
{
}

std::string FacadeWindowWindowedTest::test()
{
	windowsPlatform::SubordianteFacade* unit = new windowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window windowed test"
	);

	unit->setBorderless();
	unit->setWindowed();

	DWORD style = (DWORD)GetWindowLongPtr(
		unit->getWindow(),
		GWL_STYLE
	);

	delete unit;
	unit = nullptr;

	DWORD windowed{ WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION };

	if ((style & windowed) == windowed)
	{
		return std::string();
	}

	return "facade window windowed test failed\n";
}
