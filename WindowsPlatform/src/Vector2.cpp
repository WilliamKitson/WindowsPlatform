#include "Vector2.h"

bool WindowsPlatform::Vector2::operator==(Vector2 value)
{
    return equalX(value);
}

bool WindowsPlatform::Vector2::equalX(Vector2 value)
{
    if (x != value.x)
    {
        return false;
    }

    return equalY(value);
}

bool WindowsPlatform::Vector2::equalY(Vector2 value)
{
    if (y != value.y)
    {
        return false;
    }

    return true;
}
