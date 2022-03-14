#pragma once

namespace WindowsPlatform
{
	struct GamepadState
	{
	public:
		bool operator==(GamepadState);


	public:
		float joystickLX{ 0.0f };
		float joystickLY{ 0.0f };
		float joystickRX{ 0.0f };
		float joystickRY{ 0.0f };
		float triggerL{ 0.0f };
		float triggerR{ 0.0f };


	private:
		bool unequalJoystickLX(GamepadState);
		bool unequalJoystickLY(GamepadState);
	};
}

