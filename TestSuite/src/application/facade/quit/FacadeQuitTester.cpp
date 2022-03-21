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

	return failures;
}

std::string FacadeQuitTester::testDefault()
{
	return FacadeQuitDefaultTest(hInstance, nCmdShow).test();
}
