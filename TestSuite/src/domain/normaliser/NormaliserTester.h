#pragma once

#include <string>

#include "NormaliserRangeDefaultTest.h"
#include "NormaliserRangeSetTest.h"
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

