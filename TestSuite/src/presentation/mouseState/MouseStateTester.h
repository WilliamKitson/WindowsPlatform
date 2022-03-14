#pragma once

#include <string>

#include "MouseStateDefaultTest.h"
#include "MouseStateXposTest.h"

class MouseStateTester
{
public:
	MouseStateTester();
	~MouseStateTester();

	std::string test();


private:
	std::string testDefault();
	std::string testXpos();
};

