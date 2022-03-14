#pragma once

#include <string>

#include "MouseStateDefaultTest.h"
#include "MouseStateXposTest.h"
#include "MouseStateYposTest.h"
#include "MouseStateXdragTest.h"
#include "MouseStateYdragTest.h"

class MouseStateTester
{
public:
	MouseStateTester();
	~MouseStateTester();

	std::string test();


private:
	std::string testDefault();
	std::string testXpos();
	std::string testYpos();
	std::string testXdrag();
	std::string testYdrag();
};

