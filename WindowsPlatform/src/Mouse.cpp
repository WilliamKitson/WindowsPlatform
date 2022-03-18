#include "Mouse.h"

WindowsPlatform::Mouse::Mouse()
	: cursor()
{
}

WindowsPlatform::Mouse::~Mouse()
{
}

void WindowsPlatform::Mouse::move(LPARAM lParam)
{
	cursor = Vector2{
		(float)GET_X_LPARAM(lParam),
		(float)GET_Y_LPARAM(lParam)
	};
}

WindowsPlatform::Vector2 WindowsPlatform::Mouse::getCursor()
{
	return cursor;
}

bool WindowsPlatform::Mouse::getButton(MouseButtons)
{
	return false;
}
