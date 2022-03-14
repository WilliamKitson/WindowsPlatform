#include "MouseState.h"

bool WindowsPlatform::MouseState::operator==(MouseState value)
{
    return unequalXpos(value);
}

bool WindowsPlatform::MouseState::unequalXpos(MouseState value)
{
    if (xpos != value.xpos)
    {
        return false;
    }

    return true;
}
