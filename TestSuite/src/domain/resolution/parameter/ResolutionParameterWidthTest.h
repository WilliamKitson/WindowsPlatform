#pragma once

#include <string>
#include "ResolutionValidator.h"

class ResolutionParameterWidthTest
{
public:
	ResolutionParameterWidthTest();
	~ResolutionParameterWidthTest();

	std::string test();

private:
	int width;
};
