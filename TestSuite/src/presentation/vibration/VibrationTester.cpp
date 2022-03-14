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

	return failures;
}

std::string VibrationTester::testDefault()
{
	return VibrationDefaultTest().test();
}
