#pragma once

#include <string>
#include "default/ResolutionDefaultTester.h"

class ResolutionTester
{
public:
	ResolutionTester();
	~ResolutionTester();

	std::string test();


private:
	std::string testDefault();
};

