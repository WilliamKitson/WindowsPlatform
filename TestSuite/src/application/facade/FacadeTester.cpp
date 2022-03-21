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

	failures += testDefault();
	failures += testTag();
	failures += testResolution();
	failures += testStyle();
	failures += testEvent();
	failures += testDestroyed();
	failures += testOpenPostQuit();
	failures += testDelta();

	return failures;
}

std::string FacadeTester::testDefault()
{
	return FacadeDefaultTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testTag()
{
	return FacadeTagTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testResolution()
{
	return FacadeResolutionTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testStyle()
{
	return FacadeStyleTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testEvent()
{
	return FacadeEventTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testDestroyed()
{
	return FacadeDestroyedTest(hInstance, nCmdShow).test();
}

std::string FacadeTester::testOpenPostQuit()
{
	return FacadeOpenPostQuitTest(hInstance, nCmdShow).test();
}

std::string FacadeTester::testDelta()
{
	return FacadeDeltaTest(hInstance, nCmdShow).test();
}
