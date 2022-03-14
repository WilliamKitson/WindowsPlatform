#pragma once

#include <string>

#include "resolution/ResolutionTester.h"
#include "mouseState/MouseStateTester.h"

class PresentationTester
{
public:
	PresentationTester();
	~PresentationTester();

	std::string test();


private:
	std::string testResolution();
	std::string testMouseState();
};

