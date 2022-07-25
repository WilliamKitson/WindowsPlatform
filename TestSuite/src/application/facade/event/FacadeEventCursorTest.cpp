#include "FacadeEventCursorTest.h"

FacadeEventCursorTest::FacadeEventCursorTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, unit{ new windowsPlatform::Implimentation(hInstance, nCmdShow, "facade event cursor test") }, itterations{ 4 }, successes{ 0 }
{
}

FacadeEventCursorTest::~FacadeEventCursorTest()
{
	delete unit;
	unit = nullptr;
}

std::string FacadeEventCursorTest::test()
{
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
		successes += success(state);
	}

	if (successes == itterations)
	{
		return std::string();
	}

	return "facade event cursor test failed\n";
}

bool FacadeEventCursorTest::success(windowsPlatform::Vector2 input)
{
	if (unit->getCursor().x != input.x)
	{
		return false;
	}

	if (unit->getCursor().y != input.y)
	{
		return false;
	}

	return true;
}
