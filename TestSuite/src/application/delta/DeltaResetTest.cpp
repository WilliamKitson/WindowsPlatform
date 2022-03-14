#include "DeltaResetTest.h"

DeltaResetTest::DeltaResetTest()
{
}

DeltaResetTest::~DeltaResetTest()
{
}

std::string DeltaResetTest::test()
{
	WindowsPlatform::DeltaTimer unit;

	Sleep(500);

	unit.update();
	unit.update();

	if (unit.getDelta() < 0.5f)
	{
		return std::string();
	}

	return "delta reset test failed\n";
}
