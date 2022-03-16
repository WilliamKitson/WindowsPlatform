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

	failures += testResolutionValidator();
	failures += testNormaliser();

	return failures;
}

std::string DomainTester::testResolutionValidator()
{
	return ResolutionValidatorTester().test();
}

std::string DomainTester::testNormaliser()
{
	return NormaliserTester().test();
}
