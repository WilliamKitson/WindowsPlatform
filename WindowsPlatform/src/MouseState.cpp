#include "MouseState.h"

bool MouseState::operator==(MouseState value)
{
    return unequalXpos(value);
}

bool MouseState::unequalXpos(MouseState value)
{
    if (xpos != value.xpos)
    {
        return false;
    }

    return true;
}
