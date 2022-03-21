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

void WindowsPlatform::Mouse::press(WPARAM wParam)
{
	buttons[(int)xbuttonIndex(wParam)] = true;
}

void WindowsPlatform::Mouse::wheel(WPARAM wParam)
{
	if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
	{
		buttons[(unsigned int)MouseButtons::mouse_scrollForwards] = true;
		return;
	}

	buttons[(unsigned int)MouseButtons::mouse_scrollBackwards] = true;
}

void WindowsPlatform::Mouse::release(MouseButtons index)
{
	buttons[(int)index] = false;
}

void WindowsPlatform::Mouse::release(WPARAM wParam)
{
	buttons[(int)xbuttonIndex(wParam)] = false;
}

void WindowsPlatform::Mouse::reset()
{
	buttons[(int)MouseButtons::mouse_scrollForwards] = false;
	buttons[(int)MouseButtons::mouse_scrollBackwards] = false;
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

WindowsPlatform::MouseButtons WindowsPlatform::Mouse::xbuttonIndex(WPARAM wParam)
{
	if (GET_XBUTTON_WPARAM(wParam) != XBUTTON2)
	{
		return MouseButtons::mouse_MB4;
	}

	return MouseButtons::mouse_MB5;
}
