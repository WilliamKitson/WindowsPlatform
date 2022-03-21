#include "WindowEventCursorTest.h"

WindowEventCursorTest::WindowEventCursorTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, itterations{ 4 }, successes{ 0 }
{
}

WindowEventCursorTest::~WindowEventCursorTest()
{
}

std::string WindowEventCursorTest::test()
{
	WindowsPlatform::SubordinateImplimentation unit{
		hInstance,
		nCmdShow,
		"window event cursor test"
	};

	for (int i{ 0 }; i < itterations; i++)
	{
		WindowsPlatform::Vector2 state{
			(float)i + 1.0f,
			(float)i + 2.0f,
		};

		PostMessage(
			unit.getWindow(),
			WM_MOUSEMOVE,
			0,
			MAKELPARAM(state.x, state.y)
		);

		unit.update();
		successes += unit.getCursor() == state;
	}

	if (successes == itterations)
	{
		return std::string();
	}

	return "window event cursor test failed\n";
}
