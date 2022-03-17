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
