#include "NormaliserRangeParameterTest.h"

NormaliserRangeParameterTest::NormaliserRangeParameterTest()
{
}

NormaliserRangeParameterTest::~NormaliserRangeParameterTest()
{
}

std::string NormaliserRangeParameterTest::test()
{
	Normaliser unit{ -50, 50 };

	unit.normalise(0.0f, 1.0f, 0.75f);

	if (unit.getNormalised() == 25.0f)
	{
		return std::string();
	}

	return "normaliser range parameter test failed\n";
}
