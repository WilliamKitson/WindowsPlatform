#pragma once

#include <string>

#include "ResolutionValidatorParameterWidthTest.h"
#include "ResolutionValidatorParameterHeightTest.h"

class ResolutionValidatorParameterTester
{
public:
	ResolutionValidatorParameterTester();
	~ResolutionValidatorParameterTester();

	std::string test();


private:
	std::string testWidth();
	std::string testHeight();
};

