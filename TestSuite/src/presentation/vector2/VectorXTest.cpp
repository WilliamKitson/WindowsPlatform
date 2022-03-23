#include "VectorXTest.h"

VectorXTest::VectorXTest()
{
}

VectorXTest::~VectorXTest()
{
}

std::string VectorXTest::test()
{
	windowsPlatform::Vector2 unit{
		1.0f,
		0.0f
	};

	if ((unit == windowsPlatform::Vector2()) == false)
	{
		return std::string();
	}

	return "vector x test failed\n";
}
