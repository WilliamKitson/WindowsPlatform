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
	failures += testQuit();
	failures += testMinimise();
	failures += testDefault();
	failures += testEvent();
	failures += testOpenPostQuit();
	failures += testDelta();

	return failures;
}

std::string FacadeTester::testWindow()
{
	return FacadeWindowTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testQuit()
{
	return FacadeQuitTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testMinimise()
{
	return FacadeMinimiseTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testDefault()
{
	return FacadeDefaultTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testEvent()
{
	return FacadeEventTester(hInstance, nCmdShow).test();
}

std::string FacadeTester::testOpenPostQuit()
{
	return FacadeOpenPostQuitTest(hInstance, nCmdShow).test();
}

std::string FacadeTester::testDelta()
{
	return FacadeDeltaTest(hInstance, nCmdShow).test();
}
