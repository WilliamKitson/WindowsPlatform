#pragma once

#include <string>
#include "normaliser/NormaliserTester.h"

class DomainTester
{
public:
	DomainTester();
	~DomainTester();

	std::string test();


private:
	std::string testNormaliser();
};

