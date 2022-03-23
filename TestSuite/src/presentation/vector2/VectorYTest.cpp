#include "VectorYTest.h"

VectorYTest::VectorYTest()
{
}

VectorYTest::~VectorYTest()
{
}

std::string VectorYTest::test()
{
	windowsPlatform::Vector2 unit{
		0.0f,
		1.0f
	};

	if ((unit == windowsPlatform::Vector2()) == false)
	{
		return std::string();
	}

	return "vector y test failed\n";
}
