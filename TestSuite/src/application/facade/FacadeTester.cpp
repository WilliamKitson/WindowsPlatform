#include "FacadeTester.h"

FacadeTester::FacadeTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeTester::~FacadeTester()
{
}

std::string FacadeTester::test()
{
	std::string failures{ "" };

	failures += testWindow();
	failures += testDelta();

	return failures;
}

std::string FacadeTester::testWindow()
{
	return FacadeWindowTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testDelta()
{
	return FacadeDeltaTest(hInstance, nCmdShow).test();
}
