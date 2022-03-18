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

	failures += testParameter();
	failures += testQuit();
	failures += testMinimise();
	failures += testCursor();
	failures += testDrag();
	failures += testButtons();
	failures += testKeys();
	failures += testTag();
	failures += testResolution();
	failures += testBorderless();

	return failures;
}

std::string FacadeWindowTester::testParameter()
{
	return FacadeWindowParameterTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testQuit()
{
	return FacadeWindowQuitTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testMinimise()
{
	return FacadeWindowMinimiseTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testCursor()
{
	return FacadeWindowCursorTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testDrag()
{
	return FacadeWindowDragTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testButtons()
{
	return FacadeWindowButtonsTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testKeys()
{
	return FacadeWindowKeysTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testTag()
{
	return FacadeWindowTagTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testResolution()
{
	return FacadeWindowResolutionTest(hInstance, nCmdShow).test();
}

std::string FacadeWindowTester::testBorderless()
{
	return FacadeWindowBorderlessTest(hInstance, nCmdShow).test();
}
