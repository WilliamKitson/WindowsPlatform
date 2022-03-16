#pragma once

#include <string>
#include "ResolutionValidatorDefaultWidthTest.h"

class ResolutionValidatorDefaultTester
{
public:
	ResolutionValidatorDefaultTester();
	~ResolutionValidatorDefaultTester();

	std::string test();


private:
	std::string testWidth();
};

