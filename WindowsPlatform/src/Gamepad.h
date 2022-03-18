#pragma once

#include "Vector2.h"
#include "GamepadButtons.h"

namespace WindowsPlatform
{
	class Gamepad
	{
	public:
		Gamepad();
		~Gamepad();

		Vector2 getJoystickLeft();
		Vector2 getJoystickRight();
		float getTriggerLeft();
		float getTriggerRight();
		bool getButton(GamepadButtons);
	};
}

