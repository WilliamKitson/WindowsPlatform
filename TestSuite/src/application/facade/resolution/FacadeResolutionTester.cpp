#include "FacadeResolutionTester.h"

FacadeResolutionTester::FacadeResolutionTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeResolutionTester::~FacadeResolutionTester()
{
}

std::string FacadeResolutionTester::test()
{
	std::string failures{ "" };

	failures += testDefaultWidth();
	failures += testDefaultHeight();
	failures += testSetWidth();
	failures += testSetHeight();
	failures += testMinimumWidth();
	failures += testMinimumHeight();

	return failures;
}

std::string FacadeResolutionTester::testDefaultWidth()
{
	return FacadeResolutionDefaultWidthTest(hInstance, nCmdShow).test();
}

std::string FacadeResolutionTester::testDefaultHeight()
{
	return FacadeResolutionDefaultHeightTest(hInstance, nCmdShow).test();
}

std::string FacadeResolutionTester::testSetWidth()
{
	return FacadeResolutionSetWidthTest(hInstance, nCmdShow).test();
}

std::string FacadeResolutionTester::testSetHeight()
{
	return FacadeResolutionSetHeightTest(hInstance, nCmdShow).test();
}

std::string FacadeResolutionTester::testMinimumWidth()
{
	return FacadeResolutionMinimumWidthTest(hInstance, nCmdShow).test();
}

std::string FacadeResolutionTester::testMinimumHeight()
{
	return FacadeResolutionMinimumHeightTest(hInstance, nCmdShow).test();
}
