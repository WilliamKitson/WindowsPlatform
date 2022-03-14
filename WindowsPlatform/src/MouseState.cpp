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

    return unequalYpos(value);
}

bool WindowsPlatform::MouseState::unequalYpos(MouseState value)
{
    if (ypos != value.ypos)
    {
        return false;
    }

    return unequalXdrag(value);
}

bool WindowsPlatform::MouseState::unequalXdrag(MouseState value)
{
    if (xdrag != value.xdrag)
    {
        return false;
    }

    return unequalYdrag(value);
}

bool WindowsPlatform::MouseState::unequalYdrag(MouseState value)
{
    if (ydrag != value.ydrag)
    {
        return false;
    }

    return true;
}
