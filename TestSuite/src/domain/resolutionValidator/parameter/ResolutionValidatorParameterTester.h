#pragma once

#include <string>

#include "ResolutionParameterWidthTest.h"
#include "ResolutionParameterHeightTest.h"

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

