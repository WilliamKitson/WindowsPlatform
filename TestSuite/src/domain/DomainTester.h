#pragma once

#include <string>

#include "resolutionValidator/ResolutionValidatorTester.h"
#include "normaliser/NormaliserTester.h"

class DomainTester
{
public:
	DomainTester();
	~DomainTester();

	std::string test();


private:
	std::string testResolutionValidator();
	std::string testNormaliser();
};

