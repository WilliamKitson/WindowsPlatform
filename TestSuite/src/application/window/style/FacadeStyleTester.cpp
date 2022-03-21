#include "FacadeStyleTester.h"

FacadeStyleTester::FacadeStyleTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeStyleTester::~FacadeStyleTester()
{
}

std::string FacadeStyleTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testBorderless();
	failures += testBorderlessResolution();
	failures += testWindowed();
	failures += testWindowedResolution();

	return failures;
}

std::string FacadeStyleTester::testDefault()
{
	return FacadeStyleDefaultTest(hInstance, nCmdShow).test();
}

std::string FacadeStyleTester::testBorderless()
{
	return FacadeStyleBorderlessTest(hInstance, nCmdShow).test();
}

std::string FacadeStyleTester::testBorderlessResolution()
{
	return FacadeStyleBorderlessResolutionTest(hInstance, nCmdShow).test();
}

std::string FacadeStyleTester::testWindowed()
{
	return FacadeStyleWindowedTest(hInstance, nCmdShow).test();
}

std::string FacadeStyleTester::testWindowedResolution()
{
	return FacadeStyleWindowedResolutionTest(hInstance, nCmdShow).test();
}
