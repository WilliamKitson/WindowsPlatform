#pragma once

#include <string>
#include "delta/DeltaTester.h"

class ApplicationTester
{
public:
	ApplicationTester();
	~ApplicationTester();

	std::string test();


private:
	std::string testDelta();
};

