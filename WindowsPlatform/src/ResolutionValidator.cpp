#include "ResolutionValidator.h"

windowsPlatform::ResolutionValidator::ResolutionValidator()
	: resolution()
{
	setResolution(0, 0);
}

windowsPlatform::ResolutionValidator::~ResolutionValidator()
{
}

int windowsPlatform::ResolutionValidator::getWidth()
{
	return resolution[0];
}

int windowsPlatform::ResolutionValidator::getHeight()
{
	return resolution[1];
}

void windowsPlatform::ResolutionValidator::setResolution(int width, int height)
{
	resolution[0] = validateMinimum(960, width);
	resolution[1] = validateMinimum(540, height);;
}

int windowsPlatform::ResolutionValidator::validateMinimum(int minimum, int value)
{
	if (value < minimum)
	{
		return minimum;
	}

	return value;
}
