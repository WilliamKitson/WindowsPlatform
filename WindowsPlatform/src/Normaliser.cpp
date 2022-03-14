#include "Normaliser.h"

WindowsPlatform::Normaliser::Normaliser()
	: minimum{ 0.0f }, maximum{ 1.0f }, normalised{ 0.0f }
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

void WindowsPlatform::Normaliser::setRange(float min, float max)
{
	minimum = getSmaller(min, max);
	maximum = getLarger(min, max);
}

float WindowsPlatform::Normaliser::getSmaller(float x, float y)
{
	if (x < y)
	{
		return x;
	}

	return y;
}

float WindowsPlatform::Normaliser::getLarger(float x, float y)
{
	if (x > y)
	{
		return x;
	}

	return y;
}
