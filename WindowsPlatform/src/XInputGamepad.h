#pragma once

#include "GamepadState.h"

namespace WindowsPlatform
{
	class XInputGamepad
	{
	public:
		XInputGamepad();
		~XInputGamepad();

		GamepadState getState();
	};
}

