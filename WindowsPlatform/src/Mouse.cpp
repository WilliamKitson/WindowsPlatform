#include "Mouse.h"

WindowsPlatform::Mouse::Mouse()
{
}

WindowsPlatform::Mouse::~Mouse()
{
}

WindowsPlatform::Vector2 WindowsPlatform::Mouse::getCursor()
{
	return Vector2();
}

bool WindowsPlatform::Mouse::getButton(MouseButtons)
{
	return false;
}
