#pragma once

#include <string>
#include "vector2/VectorTester.h"

class PresentationTester
{
public:
	PresentationTester();
	~PresentationTester();

	std::string test();


private:
	std::string testVector();
};

