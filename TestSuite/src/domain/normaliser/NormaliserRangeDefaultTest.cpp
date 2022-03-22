#include "NormaliserRangeDefaultTest.h"

NormaliserRangeDefaultTest::NormaliserRangeDefaultTest()
{
}

NormaliserRangeDefaultTest::~NormaliserRangeDefaultTest()
{
}

std::string NormaliserRangeDefaultTest::test()
{
	WindowsPlatform::RangeNormaliser unit;
	
	unit.normalise(0.0f, 100.0f, 50.0f);

	if (unit.getNormalised() == 0.0f)
	{
		return std::string();
	}

	return "normaliser range default test failed\n";
}
