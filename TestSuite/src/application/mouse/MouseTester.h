#pragma once

#include <string>
#include "default/MouseDefaultTester.h"

class MouseTester
{
public:
	MouseTester();
	~MouseTester();

	std::string test();


private:
	std::string testDefault();
};

