#pragma once

#include <string>

#include "resolution/ResolutionTester.h"
#include "normaliser/NormaliserTester.h"

class DomainTester
{
public:
	DomainTester();
	~DomainTester();

	std::string test();


private:
	std::string testResolution();
	std::string testNormaliser();
};

