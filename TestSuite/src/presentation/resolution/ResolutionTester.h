#pragma once

#include <string>

#include "ResolutionDefaultTest.h"
#include "ResolutionWidthTest.h"

class ResolutionTester
{
public:
	ResolutionTester();
	~ResolutionTester();

	std::string test();


private:
	std::string testDefault();
	std::string testWidth();
};

