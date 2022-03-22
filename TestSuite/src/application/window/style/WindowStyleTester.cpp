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
	failures += testWindowed();

	return failures;
}

std::string WindowStyleTester::testDefault()
{
	return WindowStyleDefaultTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testBorderless()
{
	return WindowStyleBorderlessTest(hInstance, nCmdShow).test();
}

std::string WindowStyleTester::testWindowed()
{
	return WindowStyleWindowedTest(hInstance, nCmdShow).test();
}
