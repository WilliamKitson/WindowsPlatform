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
	return WindowStyleDefaultTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testBorderless()
{
	return WindowsStyleBorderlessTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testBorderlessResolution()
{
	return WindowStyleBorderlessResolutionTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testWindowed()
{
	return WindowStyleWindowedTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testWindowedResolution()
{
	return WindowStyleWindowedResolutionTest(hInstance, nCmdShow).test();
}
