#pragma once

#include "GamepadState.h"
#include "GamepadButtons.h"

namespace WindowsPlatform
{
	class XInputGamepad
	{
	public:
		XInputGamepad();
		~XInputGamepad();

		GamepadState getState();
		bool getButton(GamepadButtons);
	};
}

