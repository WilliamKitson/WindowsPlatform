#include "NormaliserTester.h"

NormaliserTester::NormaliserTester()
{
}

NormaliserTester::~NormaliserTester()
{
}

std::string NormaliserTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testParameter();
	failures += testInvalidRange();

	return failures;
}

std::string NormaliserTester::testDefault()
{
	return NormaliserRangeDefaultTest().test();
}

std::string NormaliserTester::testParameter()
{
	return NormaliserRangeParameterTest().test();
}

std::string NormaliserTester::testInvalidRange()
{
	return NormaliserInvalidRangeTest().test();
}
