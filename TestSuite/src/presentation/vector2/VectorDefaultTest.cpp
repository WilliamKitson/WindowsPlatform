#include "VectorDefaultTest.h"

VectorDefaultTest::VectorDefaultTest()
{
}

VectorDefaultTest::~VectorDefaultTest()
{
}

std::string VectorDefaultTest::test()
{
	windowsPlatform::Vector2 unit{
		0.0f,
		0.0f
	};

	if (unit == windowsPlatform::Vector2())
	{
		return std::string();
	}

	return "vector default test failed\n";
}
