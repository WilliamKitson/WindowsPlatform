#include "WindowDefaultTester.h"

WindowDefaultTester::WindowDefaultTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowDefaultTester::~WindowDefaultTester()
{
}

std::string WindowDefaultTester::test()
{
	std::string failures{ "" };

	failures += testQuit();

	return failures;
}

std::string WindowDefaultTester::testQuit()
{
	return WindowDefaultQuitTest(hInstance, nCmdShow).test();
}
