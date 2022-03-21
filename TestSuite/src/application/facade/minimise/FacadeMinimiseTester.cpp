#include "FacadeMinimiseTester.h"

FacadeMinimiseTester::FacadeMinimiseTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeMinimiseTester::~FacadeMinimiseTester()
{
}

std::string FacadeMinimiseTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testEvent();
	failures += testReset();

	return failures;
}

std::string FacadeMinimiseTester::testDefault()
{
	return FacadeDefaultMinimiseTest(hInstance, nCmdShow).test();
}

std::string FacadeMinimiseTester::testEvent()
{
	return FacadeMinimiseEventTest(hInstance, nCmdShow).test();
}

std::string FacadeMinimiseTester::testReset()
{
	return FacadeMinimiseResetTest(hInstance, nCmdShow).test();
}
