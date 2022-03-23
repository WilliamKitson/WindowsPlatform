#include "DeltaTimer.h"

windowsPlatform::DeltaTimer::DeltaTimer()
	: delta{ 0.0f }, start(std::chrono::high_resolution_clock::now())
{
}

windowsPlatform::DeltaTimer::~DeltaTimer()
{
}

void windowsPlatform::DeltaTimer::update()
{
	calculateDelta();
	resetStart();
}

float windowsPlatform::DeltaTimer::getDelta()
{
	return delta;
}

void windowsPlatform::DeltaTimer::calculateDelta()
{
	delta = (float)std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
}

void windowsPlatform::DeltaTimer::resetStart()
{
	start = std::chrono::high_resolution_clock::now();
}
