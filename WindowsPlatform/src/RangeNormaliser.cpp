#include "RangeNormaliser.h"

WindowsPlatform::RangeNormaliser::RangeNormaliser()
	: minimum{ 0.0f }, maximum{ 1.0f }, normalised{ 0.0f }
{
}

WindowsPlatform::RangeNormaliser::~RangeNormaliser()
{
}

void WindowsPlatform::RangeNormaliser::normalise(float min, float max, float current)
{
	normalised = ((maximum - minimum) * ((current - min) / (max - min)) + minimum);
}

float WindowsPlatform::RangeNormaliser::getNormalised()
{
	return normalised;
}

void WindowsPlatform::RangeNormaliser::setRange(float min, float max)
{
	minimum = getSmaller(min, max);
	maximum = getLarger(min, max);
}

float WindowsPlatform::RangeNormaliser::getSmaller(float x, float y)
{
	if (x < y)
	{
		return x;
	}

	return y;
}

float WindowsPlatform::RangeNormaliser::getLarger(float x, float y)
{
	if (x > y)
	{
		return x;
	}

	return y;
}
