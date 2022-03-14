#include "DeltaTester.h"

DeltaTester::DeltaTester()
{
}

DeltaTester::~DeltaTester()
{
}

std::string DeltaTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testUpdate();
	failures += testReset();

	return failures;
}

std::string DeltaTester::testDefault()
{
	return DeltaDefaultTest().test();
}

std::string DeltaTester::testUpdate()
{
	return DeltaUpdateTest().test();
}

std::string DeltaTester::testReset()
{
	return DeltaResetTest().test();
}
