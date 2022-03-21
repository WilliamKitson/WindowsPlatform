#include "WindowStyleTester.h"

WindowStyleTester::WindowStyleTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowStyleTester::~WindowStyleTester()
{
}

std::string WindowStyleTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testBorderless();
	failures += testBorderlessResolution();
	failures += testWindowed();
	failures += testWindowedResolution();

	return failures;
}

std::string WindowStyleTester::testDefault()
{
	return FacadeStyleDefaultTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testBorderless()
{
	return FacadeStyleBorderlessTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testBorderlessResolution()
{
	return FacadeStyleBorderlessResolutionTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testWindowed()
{
	return FacadeStyleWindowedTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testWindowedResolution()
{
	return FacadeStyleWindowedResolutionTest(hInstance, nCmdShow).test();
}
