#include "Resolution.h"

bool WindowsPlatform::Resolution::operator==(Resolution value)
{
    return unequalWidth(value);
}

bool WindowsPlatform::Resolution::unequalWidth(Resolution value)
{
    if (width != value.width)
    {
        return false;
    }

    return true;
}
