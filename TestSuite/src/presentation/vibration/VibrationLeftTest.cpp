#include "VibrationLeftTest.h"

VibrationLeftTest::VibrationLeftTest()
{
}

VibrationLeftTest::~VibrationLeftTest()
{
}

std::string VibrationLeftTest::test()
{
	WindowsPlatform::Vibration unit{
		1.0f,
		0.0f,
	};

	if ((unit == WindowsPlatform::Vibration()) == false)
	{
		return std::string();
	}

	return "vibration left test failed\n";
}
