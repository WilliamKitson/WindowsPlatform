#pragma once

#include <string>
#include "ResolutionDefaultWidthTest.h"

class ResolutionDefaultTester
{
public:
	ResolutionDefaultTester();
	~ResolutionDefaultTester();

	std::string test();


private:
	std::string testWidth();
};

