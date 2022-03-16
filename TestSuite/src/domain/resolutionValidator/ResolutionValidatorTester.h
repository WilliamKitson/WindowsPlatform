#pragma once

#include <string>
#include "default/ResolutionValidatorDefaultTester.h"

class ResolutionValidatorTester
{
public:
	ResolutionValidatorTester();
	~ResolutionValidatorTester();

	std::string test();


private:
	std::string testDefault();
};

