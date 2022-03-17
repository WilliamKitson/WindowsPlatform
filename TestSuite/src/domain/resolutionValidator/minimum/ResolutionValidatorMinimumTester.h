#pragma once

#include <string>

#include "ResolutionMinimumWidthTest.h"
#include "ResolutionValidatorMinimumHeightTest.h"

class ResolutionValidatorMinimumTester
{
public:
	ResolutionValidatorMinimumTester();
	~ResolutionValidatorMinimumTester();

	std::string test();


private:
	std::string testWidth();
	std::string testHeight();
};

