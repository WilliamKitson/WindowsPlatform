#include "MouseDefaultTester.h"

MouseDefaultTester::MouseDefaultTester()
{
}

MouseDefaultTester::~MouseDefaultTester()
{
}

std::string MouseDefaultTester::test()
{
	std::string failures{ "" };

	failures += testCursor();
	failures += testDrag();
	failures += testButtons();

	return failures;
}

std::string MouseDefaultTester::testCursor()
{
	return MouseDefaultCursorTest().test();
}

std::string MouseDefaultTester::testDrag()
{
	return MouseDefaultDragTest().test();
}

std::string MouseDefaultTester::testButtons()
{
	return MouseDefaultButtonsTest().test();
}
