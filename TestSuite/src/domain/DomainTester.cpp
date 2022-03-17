#include "DomainTester.h"

DomainTester::DomainTester()
{
}

DomainTester::~DomainTester()
{
}

std::string DomainTester::test()
{
	std::string failures{ "" };

	failures += testResolution();
	failures += testNormaliser();

	return failures;
}

std::string DomainTester::testResolution()
{
	return ResolutionTester().test();
}

std::string DomainTester::testNormaliser()
{
	return NormaliserTester().test();
}
