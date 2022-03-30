#pragma once

#include <string>

#include "DeltaDefaultTest.h"
#include "DeltaUpdateTest.h"
#include "DeltaResetTest.h"

class DeltaTester
{
public:
	DeltaTester();
	~DeltaTester();

	std::string test();

private:
	std::string testDefault();
	std::string testUpdate();
	std::string testReset();
};
