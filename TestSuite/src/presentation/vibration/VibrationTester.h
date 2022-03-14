#pragma once

#include <string>
#include "VibrationDefaultTest.h"

class VibrationTester
{
public:
	VibrationTester();
	~VibrationTester();

	std::string test();


private:
	std::string testDefault();
};

