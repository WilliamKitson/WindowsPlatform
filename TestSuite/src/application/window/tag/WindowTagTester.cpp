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

	return failures;
}

std::string WindowTagTester::testInitialise()
{
	return WindowTagInitialiseTest(hInstance, nCmdShow).test();
}
