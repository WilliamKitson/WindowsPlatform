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

	return failures;
}

std::string KeyboardTester::testDefault()
{
	return KeyboardDefaultTest().test();
}
