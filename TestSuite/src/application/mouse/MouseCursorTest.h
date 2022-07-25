#pragma once

#include <Windows.h>
#include <string>

#include "Mouse.h"

class MouseCursorTest
{
public:
	MouseCursorTest();
	~MouseCursorTest();

	std::string test();

private:
	bool success(windowsPlatform::Vector2);

private:
	windowsPlatform::Vector2 cursor;
};
