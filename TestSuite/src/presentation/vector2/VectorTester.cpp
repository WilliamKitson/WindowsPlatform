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
	failures += testX();
	failures += testY();

	return failures;
}

std::string VectorTester::testDefault()
{
	return VectorDefaultTest().test();
}

std::string VectorTester::testX()
{
	return VectorXTest().test();
}

std::string VectorTester::testY()
{
	return VectorYTest().test();
}
