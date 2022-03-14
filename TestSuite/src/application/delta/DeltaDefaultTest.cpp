#include "DeltaDefaultTest.h"

DeltaDefaultTest::DeltaDefaultTest()
{
}

DeltaDefaultTest::~DeltaDefaultTest()
{
}

std::string DeltaDefaultTest::test()
{
	if (WindowsPlatform::DeltaTimer().getDelta() == 0.0f)
	{
		return std::string();
	}

	return "delta default test failed\n";
}
