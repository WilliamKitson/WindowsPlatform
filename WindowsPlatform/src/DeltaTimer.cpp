#include "DeltaTimer.h"

DeltaTimer::DeltaTimer()
	: delta{ 0.0f }, start(std::chrono::high_resolution_clock::now())
{
}

DeltaTimer::~DeltaTimer()
{
}

void DeltaTimer::update()
{
	calculateDelta();
	resetStart();
}

float DeltaTimer::getDelta()
{
	return delta;
}

void DeltaTimer::calculateDelta()
{
	delta = (float)std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
}

void DeltaTimer::resetStart()
{
	start = std::chrono::high_resolution_clock::now();
}
