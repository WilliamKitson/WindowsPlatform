#pragma once

#include <string>
#include "VectorDefaultTest.h"

class VectorTester
{
public:
	VectorTester();
	~VectorTester();

	std::string test();


private:
	std::string testDefault();
};

