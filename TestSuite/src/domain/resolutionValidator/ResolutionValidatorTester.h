#pragma once

#include <string>

#include "default/ResolutionValidatorDefaultTester.h"
#include "parameter/ResolutionValidatorParameterTester.h"

class ResolutionValidatorTester
{
public:
	ResolutionValidatorTester();
	~ResolutionValidatorTester();

	std::string test();


private:
	std::string testDefault();
	std::string testParameter();
};

