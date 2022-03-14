#pragma once

#include <string>

#include "ResolutionDefaultTest.h"
#include "ResolutionWidthTest.h"
#include "ResolutionHeightTest.h"

class ResolutionTester
{
public:
	ResolutionTester();
	~ResolutionTester();

	std::string test();


private:
	std::string testDefault();
	std::string testWidth();
	std::string testHeight();
};

