#include "WindowTester.h"

WindowTester::WindowTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowTester::~WindowTester()
{
}

std::string WindowTester::test()
{
	std::string failures{ "" };

	failures += testTag();

	return failures;
}

std::string WindowTester::testTag()
{
	return WindowTagTester(hInstance, nCmdShow).test();
}
