#include "WindowTagTester.h"

WindowTagTester::WindowTagTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowTagTester::~WindowTagTester()
{
}

std::string WindowTagTester::test()
{
	std::string failures{ "" };

	failures += testInitialise();
	failures += testSet();

	return failures;
}

std::string WindowTagTester::testInitialise()
{
	return WindowTagInitialiseTest(hInstance, nCmdShow).test();
}

std::string WindowTagTester::testSet()
{
	return WindowTagSetTest(hInstance, nCmdShow).test();
}
