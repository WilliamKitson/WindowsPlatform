#pragma once

#include <string>

#include "ResolutionValidatorMinimumWidthTest.h"
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

