#pragma once

#include <string>

#include "default/ResolutionDefaultTester.h"
#include "parameter/ResolutionParameterTester.h"
#include "minimum/ResolutionMinimumTester.h"

class ResolutionValidatorTester
{
public:
	ResolutionValidatorTester();
	~ResolutionValidatorTester();

	std::string test();


private:
	std::string testDefault();
	std::string testParameter();
	std::string testMinimum();
};

