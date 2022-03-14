#include "NormaliserRangeSetTest.h"

NormaliserRangeParameterTest::NormaliserRangeParameterTest()
{
}

NormaliserRangeParameterTest::~NormaliserRangeParameterTest()
{
}

std::string NormaliserRangeParameterTest::test()
{
	WindowsPlatform::Normaliser unit;

	unit.setRange(-50.0f, 50.0f);
	unit.normalise(0.0f, 1.0f, 0.75f);

	if (unit.getNormalised() == 25.0f)
	{
		return std::string();
	}

	return "normaliser range set test failed\n";
}
