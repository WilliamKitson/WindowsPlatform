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
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window event cursor test"
	};

	for (int i{ 0 }; i < itterations; i++)
	{
		WindowsPlatform::MouseState state{
			i + 1,
			i + 2,
			0.0f,
			0.0f
		};

		PostMessage(
			unit.getWindow(),
			WM_MOUSEMOVE,
			0,
			MAKELPARAM(state.xpos, state.ypos)
		);

		unit.update();
		successes += unit.getMouse() == state;
	}

	if (successes == itterations)
	{
		return std::string();
	}

	return "window event cursor test failed\n";
}
