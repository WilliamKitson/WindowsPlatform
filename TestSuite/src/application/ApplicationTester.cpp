#include "ApplicationTester.h"

ApplicationTester::ApplicationTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

ApplicationTester::~ApplicationTester()
{
}

std::string ApplicationTester::test()
{
	std::string failures{ "" };

	failures += testWindow();
	failures += testDelta();
	failures += testMouse();
	failures += testKeyboard();
	failures += testGamepad();

	return failures;
}

std::string ApplicationTester::testWindow()
{
	return WindowTester(hInstance, nCmdShow).test();
}

std::string ApplicationTester::testDelta()
{
	return DeltaTester().test();
}

std::string ApplicationTester::testMouse()
{
	return MouseTester().test();
}

std::string ApplicationTester::testKeyboard()
{
	return KeyboardTester().test();
}

std::string ApplicationTester::testGamepad()
{
	return GamepadTester().test();
}
