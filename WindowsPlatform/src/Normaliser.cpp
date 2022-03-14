#include "Normaliser.h"

Normaliser::Normaliser()
	: Normaliser(0, 1)
{
}

Normaliser::Normaliser(float min, float max)
	: minimum{ getSmaller(min, max) }, maximum{ getLarger(min, max) }, normalised{ 0.0f }
{
}

Normaliser::~Normaliser()
{
}

void Normaliser::normalise(float min, float max, float current)
{
	normalised = ((maximum - minimum) * ((current - min) / (max - min)) + minimum);
}

float Normaliser::getNormalised()
{
	return normalised;
}

float Normaliser::getSmaller(float min, float max)
{
	if (min < max)
	{
		return min;
	}

	return max;
}

float Normaliser::getLarger(float min, float max)
{
	if (min > max)
	{
		return min;
	}

	return max;
}
