#pragma once

#include <string>
#include "ResolutionValidatorParameterWidthTest.h"

class ResolutionValidatorParameterTester
{
public:
	ResolutionValidatorParameterTester();
	~ResolutionValidatorParameterTester();

	std::string test();


private:
	std::string testWidth();
};

