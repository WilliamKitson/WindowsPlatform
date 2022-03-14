#include "NormaliserInvertedRangeTest.h"

NormaliserInvertedRangeTest::NormaliserInvertedRangeTest()
{
}

NormaliserInvertedRangeTest::~NormaliserInvertedRangeTest()
{
}

std::string NormaliserInvertedRangeTest::test()
{
	WindowsPlatform::Normaliser unit;

	unit.setRange(50.0f, -50.0f);
	unit.normalise(0.0f, 10.0f, 2.0f);

	if (unit.getNormalised() == -30.0f)
	{
		return std::string();
	}

	return "normaliser inverted range test failed\n";
}
