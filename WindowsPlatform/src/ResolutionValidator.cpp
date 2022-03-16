#include "ResolutionValidator.h"

WindowsPlatform::ResolutionValidator::ResolutionValidator()
	: resolution()
{
	setResolution(0, 0);
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
	resolution[0] = validateMinimum(960, width);
	resolution[1] = validateMinimum(540, height);;
}

int WindowsPlatform::ResolutionValidator::validateMinimum(int minimum, int value)
{
	if (value < minimum)
	{
		return minimum;
	}

	return value;
}
