#include "Vibration.h"

bool WindowsPlatform::Vibration::operator==(Vibration value)
{
    return unequalLeft(value);
}

bool WindowsPlatform::Vibration::unequalLeft(Vibration value)
{
    if (left != value.left)
    {
        return false;
    }

    return unequalRight(value);
}

bool WindowsPlatform::Vibration::unequalRight(Vibration value)
{
    if (right != value.right)
    {
        return false;
    }

    return true;
}
