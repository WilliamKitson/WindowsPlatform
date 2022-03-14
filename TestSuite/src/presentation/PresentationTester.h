#pragma once

#include <string>
#include "mouseState/MouseStateTester.h"

class PresentationTester
{
public:
	PresentationTester();
	~PresentationTester();

	std::string test();


private:
	std::string testMouseState();
};

