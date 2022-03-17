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

	return failures;
}

std::string PresentationTester::testVector()
{
	return VectorTester().test();
}
