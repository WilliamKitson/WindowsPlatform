#pragma once

#include <string>
#include "ResolutionDefaultTest.h"

class ResolutionTester
{
public:
	ResolutionTester();
	~ResolutionTester();

	std::string test();


private:
	std::string testDefault();
};

