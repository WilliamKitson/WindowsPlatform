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

	for (int i{ 0 }; i < (int)windowsPlatform::Keys::size; i++)
	{
		successes += unit.getKey((windowsPlatform::Keys)i) == false;
	}

	if (successes == (int)windowsPlatform::Keys::size)
	{
		return std::string();
	}

	return "keyboard default test failed\n";
}
