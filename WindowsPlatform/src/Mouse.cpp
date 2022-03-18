#include "Mouse.h"

WindowsPlatform::Mouse::Mouse()
	: cursor(), buttons()
{
	initialiseButtons();
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

void WindowsPlatform::Mouse::press(MouseButtons index)
{
	buttons[(int)index] = true;
}

void WindowsPlatform::Mouse::release(MouseButtons index)
{
	buttons[(int)index] = false;
}

WindowsPlatform::Vector2 WindowsPlatform::Mouse::getCursor()
{
	return cursor;
}

bool WindowsPlatform::Mouse::getButton(MouseButtons index)
{
	return buttons[(int)index];
}

void WindowsPlatform::Mouse::initialiseButtons()
{
	for (int i{ 0 }; i < (int)MouseButtons::size; i++)
	{
		buttons[i] = false;
	}
}
