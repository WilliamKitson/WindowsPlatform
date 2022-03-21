#include "FacadeTagTester.h"

FacadeTagTester::FacadeTagTester(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeTagTester::~FacadeTagTester()
{
}

std::string FacadeTagTester::test()
{
	std::string failures{ "" };

	failures += testParameter();
	failures += testSet();

	return failures;
}

std::string FacadeTagTester::testParameter()
{
	return FacadeTagParameterTest(hInstance, nCmdShow).test();
}

std::string FacadeTagTester::testSet()
{
	return FacadeTagSetTest(hInstance, nCmdShow).test();
}
