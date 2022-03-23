#include "KeyboardDefaultTest.h"

KeyboardDefaultTest::KeyboardDefaultTest()
	: successes{ 0 }
{
}

KeyboardDefaultTest::~KeyboardDefaultTest()
{
}

std::string KeyboardDefaultTest::test()
{
	windowsPlatform::Keyboard unit;

	for (int i{ 0 }; i < (int)windowsPlatform::KeyboardKeys::size; i++)
	{
		successes += unit.getKey((windowsPlatform::KeyboardKeys)i) == false;
	}

	if (successes == (int)windowsPlatform::KeyboardKeys::size)
	{
		return std::string();
	}

	return "keyboard default test failed\n";
}
