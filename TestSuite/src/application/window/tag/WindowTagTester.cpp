#include "WindowTagTester.h"

WindowTagTester::WindowTagTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowTagTester::~WindowTagTester()
{
}

std::string WindowTagTester::test()
{
	std::string failures{ "" };

	failures += testParameter();
	failures += testSet();

	return failures;
}

std::string WindowTagTester::testParameter()
{
	return WindowTagParameterTest(hInstance, nCmdShow).test();
}

std::string WindowTagTester::testSet()
{
	return WindowTagSetTest(hInstance, nCmdShow).test();
}
