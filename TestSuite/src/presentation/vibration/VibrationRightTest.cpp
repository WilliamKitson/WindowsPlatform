#include "VibrationRightTest.h"

VibrationRightTest::VibrationRightTest()
{
}

VibrationRightTest::~VibrationRightTest()
{
}

std::string VibrationRightTest::test()
{
	WindowsPlatform::Vibration unit{
		0.0f,
		1.0f,
	};

	if ((unit == WindowsPlatform::Vibration()) == false)
	{
		return std::string();
	}

	return "vibration right test failed\n";
}
