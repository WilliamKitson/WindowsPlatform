#include "GamepadState.h"

bool WindowsPlatform::GamepadState::operator==(GamepadState value)
{
    return unequalJoystickLX(value);
}

bool WindowsPlatform::GamepadState::unequalJoystickLX(GamepadState value)
{
    if (joystickLX != value.joystickLX)
    {
        return false;
    }

    return true;
}
