#include "PresentationTester.h"

PresentationTester::PresentationTester()
{
}

PresentationTester::~PresentationTester()
{
}

std::string PresentationTester::test()
{
	std::string failures{ "" };

	failures += testVector();
	failures += testResolution();
	failures += testMouseState();
	failures += testGamepadState();
	failures += testVibration();

	return failures;
}

std::string PresentationTester::testVector()
{
	return VectorTester().test();
}

std::string PresentationTester::testResolution()
{
	return ResolutionTester().test();
}

std::string PresentationTester::testMouseState()
{
	return MouseStateTester().test();
}

std::string PresentationTester::testGamepadState()
{
	return GamepadStateTester().test();
}

std::string PresentationTester::testVibration()
{
	return VibrationTester().test();
}
