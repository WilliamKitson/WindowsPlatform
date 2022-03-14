#include "VibrationTester.h"

VibrationTester::VibrationTester()
{
}

VibrationTester::~VibrationTester()
{
}

std::string VibrationTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testLeft();

	return failures;
}

std::string VibrationTester::testDefault()
{
	return VibrationDefaultTest().test();
}

std::string VibrationTester::testLeft()
{
	return VibrationLeftTest().test();
}
