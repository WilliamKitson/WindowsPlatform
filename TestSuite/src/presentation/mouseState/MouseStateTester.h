#pragma once

#include <string>
#include "MouseStateDefaultTest.h"

class MouseStateTester
{
public:
	MouseStateTester();
	~MouseStateTester();

	std::string test();


private:
	std::string testDefault();
};

