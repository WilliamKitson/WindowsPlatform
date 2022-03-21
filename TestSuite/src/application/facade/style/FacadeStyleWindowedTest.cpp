#include "FacadeStyleWindowedTest.h"

FacadeStyleWindowedTest::FacadeStyleWindowedTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeStyleWindowedTest::~FacadeStyleWindowedTest()
{
}

std::string FacadeStyleWindowedTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade style windowed test"
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

	return "facade style windowed test failed\n";
}
