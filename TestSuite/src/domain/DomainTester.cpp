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

	failures += testNormaliser();

	return failures;
}

std::string DomainTester::testNormaliser()
{
	return NormaliserTester().test();
}
