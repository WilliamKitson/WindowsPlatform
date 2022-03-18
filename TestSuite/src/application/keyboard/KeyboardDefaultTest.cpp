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
	WindowsPlatform::Keyboard unit;

	for (int i{ 0 }; i < (int)WindowsPlatform::KeyboardKeys::size; i++)
	{
		successes += unit.getKey((WindowsPlatform::KeyboardKeys)i) == false;
	}

	if (successes == (int)WindowsPlatform::KeyboardKeys::size)
	{
		return std::string();
	}

	return "keyboard default test failed\n";
}
