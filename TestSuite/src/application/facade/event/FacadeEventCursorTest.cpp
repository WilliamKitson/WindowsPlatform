#include "FacadeEventCursorTest.h"

FacadeEventCursorTest::FacadeEventCursorTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, itterations{ 4 }, successes{ 0 }
{
}

FacadeEventCursorTest::~FacadeEventCursorTest()
{
}

std::string FacadeEventCursorTest::test()
{
	windowsPlatform::Facade* unit = new windowsPlatform::Implimentation(
		hInstance,
		nCmdShow,
		"facade event cursor test"
	);

	for (int i{ 0 }; i < itterations; i++)
	{
		windowsPlatform::Vector2 state{
			(float)i + 1.0f,
			(float)i + 2.0f,
		};

		PostMessage(
			unit->getWindow(),
			WM_MOUSEMOVE,
			0,
			MAKELPARAM(state.x, state.y)
		);

		unit->update();
		successes += unit->getCursor() == state;
	}

	delete unit;
	unit = nullptr;

	if (successes == itterations)
	{
		return std::string();
	}

	return "facade event cursor test failed\n";
}
