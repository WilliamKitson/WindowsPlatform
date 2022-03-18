#include "KeyboardTester.h"

KeyboardTester::KeyboardTester()
{
}

KeyboardTester::~KeyboardTester()
{
}

std::string KeyboardTester::test()
{
	std::string failures{ "" };

	failures += testDefault();
	failures += testPress();
	failures += testRelease();

	return failures;
}

std::string KeyboardTester::testDefault()
{
	return KeyboardDefaultTest().test();
}

std::string KeyboardTester::testPress()
{
	return KeyboardPressTest().test();
}

std::string KeyboardTester::testRelease()
{
	return KeyboardReleaseTest().test();
}
