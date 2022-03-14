#include "VibrationDefaultTest.h"

VibrationDefaultTest::VibrationDefaultTest()
{
}

VibrationDefaultTest::~VibrationDefaultTest()
{
}

std::string VibrationDefaultTest::test()
{
	WindowsPlatform::Vibration unit{
		0.0f,
		0.0f,
	};

	if (unit == WindowsPlatform::Vibration())
	{
		return std::string();
	}

	return "vibration default test failed\n";
}
