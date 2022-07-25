#include "SubordinateTester.h"

SubordinateTester::SubordinateTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

SubordinateTester::~SubordinateTester()
{
}

std::string SubordinateTester::test()
{
	std::string failures{ "" };

	failures += testDomain();
	failures += testApplication();

	return failures;
}

std::string SubordinateTester::testDomain()
{
	return DomainTester().test();
}

std::string SubordinateTester::testApplication()
{
	return ApplicationTester(hInstance, nCmdShow).test();
}
