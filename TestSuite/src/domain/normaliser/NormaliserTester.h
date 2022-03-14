#pragma once

#include <string>

#include "NormaliserRangeDefaultTest.h"
#include "NormaliserRangeParameterTest.h"
#include "NormaliserInvertedRangeTest.h"

class NormaliserTester
{
public:
	NormaliserTester();
	~NormaliserTester();

	std::string test();


private:
	std::string testDefault();
	std::string testParameter();
	std::string testInvalidRange();
};

