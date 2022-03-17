#include "FacadeWindowTester.h"

FacadeWindowTester::FacadeWindowTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeWindowTester::~FacadeWindowTester()
{
}

std::string FacadeWindowTester::test()
{
	std::string failures{ "" };

	failures += testQuit();
	failures += testMinimise();

	return failures;
}

std::string FacadeWindowTester::testQuit()
{
	return FacadeWindowQuitTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testMinimise()
{
	return FacadeWindowMinimiseTest(hInstance, nCmdShow).test();
}
