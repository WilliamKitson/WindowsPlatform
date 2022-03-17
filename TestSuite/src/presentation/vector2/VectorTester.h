#pragma once

#include <string>

#include "VectorDefaultTest.h"
#include "VectorXTest.h"

class VectorTester
{
public:
	VectorTester();
	~VectorTester();

	std::string test();


private:
	std::string testDefault();
	std::string testX();
};

