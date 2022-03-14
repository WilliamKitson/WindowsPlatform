#include "Normaliser.h"

WindowsPlatform::Normaliser::Normaliser()
	: Normaliser(0, 1)
{
}

WindowsPlatform::Normaliser::Normaliser(float min, float max)
	: minimum{ getSmaller(min, max) }, maximum{ getLarger(min, max) }, normalised{ 0.0f }
{
}

WindowsPlatform::Normaliser::~Normaliser()
{
}

void WindowsPlatform::Normaliser::normalise(float min, float max, float current)
{
	normalised = ((maximum - minimum) * ((current - min) / (max - min)) + minimum);
}

float WindowsPlatform::Normaliser::getNormalised()
{
	return normalised;
}

float WindowsPlatform::Normaliser::getSmaller(float min, float max)
{
	if (min < max)
	{
		return min;
	}

	return max;
}

float WindowsPlatform::Normaliser::getLarger(float min, float max)
{
	if (min > max)
	{
		return min;
	}

	return max;
}
