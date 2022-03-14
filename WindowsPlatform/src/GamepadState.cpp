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

    return unequalJoystickLY(value);
}

bool WindowsPlatform::GamepadState::unequalJoystickLY(GamepadState value)
{
    if (joystickLY != value.joystickLY)
    {
        return false;
    }

    return unequalJoystickRX(value);
}

bool WindowsPlatform::GamepadState::unequalJoystickRX(GamepadState value)
{
    if (joystickRX != value.joystickRX)
    {
        return false;
    }

    return unequalJoystickRY(value);
}

bool WindowsPlatform::GamepadState::unequalJoystickRY(GamepadState value)
{
    if (joystickRY != value.joystickRY)
    {
        return false;
    }

    return unequalTriggerL(value);
}

bool WindowsPlatform::GamepadState::unequalTriggerL(GamepadState value)
{
    if (triggerL != value.triggerL)
    {
        return false;
    }

    return true;
}
