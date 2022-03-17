#pragma once

#include <string>

#include "ResolutionDefaultWidthTest.h"
#include "ResolutionDefaultHeightTest.h"

class ResolutionValidatorDefaultTester
{
public:
	ResolutionValidatorDefaultTester();
	~ResolutionValidatorDefaultTester();

	std::string test();


private:
	std::string testWidth();
	std::string testHeight();
};

