#pragma once

#include <string>
#include "ResolutionValidatorMinimumWidthTest.h"

class ResolutionValidatorMinimumTester
{
public:
	ResolutionValidatorMinimumTester();
	~ResolutionValidatorMinimumTester();

	std::string test();


private:
	std::string testWidth();
};

