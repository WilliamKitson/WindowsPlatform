#pragma once

#include "Vector2.h"
#include "GamepadButtons.h"

namespace WindowsPlatform
{
	class XInputGamepad
	{
	public:
		XInputGamepad();
		~XInputGamepad();

		Vector2 getJoystickLeft();
		Vector2 getJoystickRight();
		float getTriggerLeft();
		float getTriggerRight();
		bool getButton(GamepadButtons);
	};
}

