#include "ResolutionValidator.h"

WindowsPlatform::ResolutionValidator::ResolutionValidator()
	: resolution()
{
	resolution[0] = 960;
	resolution[1] = 540;
}

WindowsPlatform::ResolutionValidator::~ResolutionValidator()
{
}

int WindowsPlatform::ResolutionValidator::getWidth()
{
	return resolution[0];
}

int WindowsPlatform::ResolutionValidator::getHeight()
{
	return resolution[1];
}

void WindowsPlatform::ResolutionValidator::setResolution(int width, int height)
{
	resolution[0] = validateWidth(width);
	resolution[1] = height;
}

int WindowsPlatform::ResolutionValidator::validateWidth(int value)
{
	int minimum = 960;

	if (value < minimum)
	{
		return minimum;
	}

	return value;
}
