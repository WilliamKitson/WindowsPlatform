#pragma once

#include <string>

#include "VibrationDefaultTest.h"
#include "VibrationLeftTest.h"

class VibrationTester
{
public:
	VibrationTester();
	~VibrationTester();

	std::string test();


private:
	std::string testDefault();
	std::string testLeft();
};

