#pragma once

#include <string>

#include "vector2/VectorTester.h"
#include "vibration/VibrationTester.h"

class PresentationTester
{
public:
	PresentationTester();
	~PresentationTester();

	std::string test();


private:
	std::string testVector();
	std::string testVibration();
};

