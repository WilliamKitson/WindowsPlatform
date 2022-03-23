#include "DeltaUpdateTest.h"

DeltaUpdateTest::DeltaUpdateTest()
{
}

DeltaUpdateTest::~DeltaUpdateTest()
{
}

std::string DeltaUpdateTest::test()
{
	windowsPlatform::DeltaTimer unit;

	Sleep(500);
	unit.update();

	if (unit.getDelta() > 0.5f)
	{
		return std::string();
	}

	return "delta update test failed\n";
}
