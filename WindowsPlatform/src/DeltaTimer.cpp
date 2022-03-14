#include "DeltaTimer.h"

WindowsPlatform::DeltaTimer::DeltaTimer()
	: delta{ 0.0f }, start(std::chrono::high_resolution_clock::now())
{
}

WindowsPlatform::DeltaTimer::~DeltaTimer()
{
}

void WindowsPlatform::DeltaTimer::update()
{
	calculateDelta();
	resetStart();
}

float WindowsPlatform::DeltaTimer::getDelta()
{
	return delta;
}

void WindowsPlatform::DeltaTimer::calculateDelta()
{
	delta = (float)std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
}

void WindowsPlatform::DeltaTimer::resetStart()
{
	start = std::chrono::high_resolution_clock::now();
}
