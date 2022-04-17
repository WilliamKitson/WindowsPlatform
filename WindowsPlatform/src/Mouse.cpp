#include "Mouse.h"

windowsPlatform::Mouse::Mouse()
	: cursor(), buttons()
{
	initialiseButtons();
}

windowsPlatform::Mouse::~Mouse()
{
}

void windowsPlatform::Mouse::move(LPARAM lParam)
{
	cursor = Vector2{
		(float)GET_X_LPARAM(lParam),
		(float)GET_Y_LPARAM(lParam)
	};
}

void windowsPlatform::Mouse::press(Buttons index)
{
	buttons[(int)index] = true;
}

void windowsPlatform::Mouse::press(WPARAM wParam)
{
	buttons[(int)xbuttonIndex(wParam)] = true;
}

void windowsPlatform::Mouse::wheel(WPARAM wParam)
{
	if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
	{
		buttons[(unsigned int)Buttons::mouse_scrollForwards] = true;
		return;
	}

	buttons[(unsigned int)Buttons::mouse_scrollBackwards] = true;
}

void windowsPlatform::Mouse::release(Buttons index)
{
	buttons[(int)index] = false;
}

void windowsPlatform::Mouse::release(WPARAM wParam)
{
	buttons[(int)xbuttonIndex(wParam)] = false;
}

void windowsPlatform::Mouse::reset()
{
	resetForward();
	buttons[(int)Buttons::mouse_scrollBackwards] = false;
}

windowsPlatform::Vector2 windowsPlatform::Mouse::getCursor()
{
	return cursor;
}

bool windowsPlatform::Mouse::getButton(Buttons index)
{
	return buttons[(int)index];
}

void windowsPlatform::Mouse::initialiseButtons()
{
	for (int i{ 0 }; i < (int)Buttons::size; i++)
	{
		buttons[i] = false;
	}
}

windowsPlatform::Buttons windowsPlatform::Mouse::xbuttonIndex(WPARAM wParam)
{
	if (GET_XBUTTON_WPARAM(wParam) != XBUTTON2)
	{
		return Buttons::mouse_MB4;
	}

	return Buttons::mouse_MB5;
}

void windowsPlatform::Mouse::resetForward()
{
	buttons[(int)Buttons::mouse_scrollForwards] = false;
}
