#include "ResolutionValidator.h"

WindowsPlatform::ResolutionValidator::ResolutionValidator()
	: width{ 960 }
{
}

WindowsPlatform::ResolutionValidator::~ResolutionValidator()
{
}

int WindowsPlatform::ResolutionValidator::getWidth()
{
	return width;
}

int WindowsPlatform::ResolutionValidator::getHeight()
{
	return 540;
}

void WindowsPlatform::ResolutionValidator::setResolution(int w, int)
{
	width = w;
}
