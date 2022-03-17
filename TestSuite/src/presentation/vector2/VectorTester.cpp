#include "VectorTester.h"

VectorTester::VectorTester()
{
}

VectorTester::~VectorTester()
{
}

std::string VectorTester::test()
{
	std::string failures{ "" };

	failures += testDefault();

	return failures;
}

std::string VectorTester::testDefault()
{
	return VectorDefaultTest().test();
}
