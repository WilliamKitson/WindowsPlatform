#include "RangeNormaliser.h"

windowsPlatform::RangeNormaliser::RangeNormaliser()
	: minimum{ 0.0f }, maximum{ 0.0f }, normalised{ 0.0f }
{
}

windowsPlatform::RangeNormaliser::~RangeNormaliser()
{
}

void windowsPlatform::RangeNormaliser::normalise(float min, float max, float current)
{
	normalised = ((maximum - minimum) * ((current - min) / (max - min)) + minimum);
}

float windowsPlatform::RangeNormaliser::getNormalised()
{
	return normalised;
}

void windowsPlatform::RangeNormaliser::setRange(float min, float max)
{
	minimum = getSmaller(min, max);
	maximum = getLarger(min, max);
}

float windowsPlatform::RangeNormaliser::getSmaller(float x, float y)
{
	if (x < y)
	{
		return x;
	}

	return y;
}

float windowsPlatform::RangeNormaliser::getLarger(float x, float y)
{
	if (x > y)
	{
		return x;
	}

	return y;
}
