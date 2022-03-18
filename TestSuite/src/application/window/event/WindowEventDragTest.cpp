#include "WindowEventDragTest.h"

WindowEventDragTest::WindowEventDragTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, tagPrefix{ "window event drag test, ESC TO CONTINUE" }
{
}

WindowEventDragTest::~WindowEventDragTest()
{
}

std::string WindowEventDragTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		tagPrefix
	};

	while (unit.getKeyboard(WindowsPlatform::KeyboardKeys::keyboard_ESC) == false)
	{
		Sleep(1);
		unit.update();

		std::string tag = tagPrefix + "(x:" + std::to_string(unit.getDrag().x) + "/y:" + std::to_string(unit.getDrag().y) + ")";
		unit.setTag(tag);
	}

	return std::string();
}
