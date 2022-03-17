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
	failures += testVibration();

	return failures;
}

std::string PresentationTester::testVector()
{
	return VectorTester().test();
}

std::string PresentationTester::testVibration()
{
	return VibrationTester().test();
}
