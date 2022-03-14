#include "NormaliserInvalidRangeTest.h"

NormaliserInvalidRangeTest::NormaliserInvalidRangeTest()
{
}

NormaliserInvalidRangeTest::~NormaliserInvalidRangeTest()
{
}

std::string NormaliserInvalidRangeTest::test()
{
	Normaliser unit{ 50.0f, -50.0f };

	unit.normalise(0.0f, 10.0f, 2.0f);

	if (unit.getNormalised() == -30.0f)
	{
		return std::string();
	}

	return "normaliser invalid range test failed\n";
}
