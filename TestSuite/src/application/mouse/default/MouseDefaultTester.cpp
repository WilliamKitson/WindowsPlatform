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
