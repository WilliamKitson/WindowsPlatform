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

	failures += testTag();

	return failures;
}

std::string FacadeWindowTester::testTag()
{
	return FacadeWindowTagTest(hInstance, nCmdShow).test();
}
