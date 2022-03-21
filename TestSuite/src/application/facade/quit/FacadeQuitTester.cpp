#include "FacadeQuitTester.h"

FacadeQuitTester::FacadeQuitTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeQuitTester::~FacadeQuitTester()
{
}

std::string FacadeQuitTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testEvent();
	failures += testReset();

	return failures;
}

std::string FacadeQuitTester::testDefault()
{
	return FacadeQuitDefaultTest(hInstance, nCmdShow).test();
}

std::string FacadeQuitTester::testEvent()
{
	return FacadeQuitEventTest(hInstance, nCmdShow).test();
}

std::string FacadeQuitTester::testReset()
{
	return FacadeQuitResetTest(hInstance, nCmdShow).test();
}
