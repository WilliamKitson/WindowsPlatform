#include "Delta.h"

windowsPlatform::Delta::Delta()
	: delta{ 0.0f }, start(std::chrono::high_resolution_clock::now())
{
}

windowsPlatform::Delta::~Delta()
{
}

void windowsPlatform::Delta::update()
{
	calculateDelta();
	resetStart();
}

float windowsPlatform::Delta::getDelta()
{
	return delta;
}

void windowsPlatform::Delta::calculateDelta()
{
	delta = (float)std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
}

void windowsPlatform::Delta::resetStart()
{
	start = std::chrono::high_resolution_clock::now();
}
