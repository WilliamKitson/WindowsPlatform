#include "FacadeWindowCursorTest.h"

FacadeWindowCursorTest::FacadeWindowCursorTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeWindowCursorTest::~FacadeWindowCursorTest()
{
}

std::string FacadeWindowCursorTest::test()
{
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window cursor test"
	);

	WindowsPlatform::Vector2 simulated{
		1.0f,
		2.0f
	};

	PostMessage(
		unit->getWindow(),
		WM_MOUSEMOVE,
		0,
		MAKELPARAM(simulated.x, simulated.y)
	);

	unit->update();
	WindowsPlatform::Vector2 cursor = unit->getCursor();

	delete unit;
	unit = nullptr;

	if (cursor == simulated)
	{
		return std::string();
	}

	return "facade window cursor test failed\n";
}
