#include "MouseTester.h"

MouseTester::MouseTester()
{
}

MouseTester::~MouseTester()
{
}

std::string MouseTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testButtons();
	failures += testXButtons();
	failures += testWheel();
	failures += testCursor();

	return failures;
}

std::string MouseTester::testDefault()
{
	return MouseDefaultTester().test();
}

std::string MouseTester::testButtons()
{
	return MouseButtonsTester().test();
}

std::string MouseTester::testXButtons()
{
	return MouseXButtonsTester().test();
}

std::string MouseTester::testWheel()
{
	return MouseWheelTester().test();
}

std::string MouseTester::testCursor()
{
	return MouseCursorTest().test();
}
