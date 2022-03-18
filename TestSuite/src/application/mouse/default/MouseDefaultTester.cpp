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

	return failures;
}

std::string MouseDefaultTester::testCursor()
{
	return MouseDefaultCursorTest().test();
}
