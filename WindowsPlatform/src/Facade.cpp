#include "Facade.h"

windowsPlatform::Facade::Facade()
{
}

windowsPlatform::Facade::~Facade()
{
}

void windowsPlatform::Facade::update()
{
}

HWND windowsPlatform::Facade::getWindow()
{
	return HWND();
}

bool windowsPlatform::Facade::getQuit()
{
	return false;
}

bool windowsPlatform::Facade::getMinimise()
{
	return false;
}

windowsPlatform::Vector2 windowsPlatform::Facade::getCursor()
{
	return Vector2();
}

windowsPlatform::Vector2 windowsPlatform::Facade::getDrag()
{
	return Vector2();
}

bool windowsPlatform::Facade::getMouse(Buttons)
{
	return false;
}

bool windowsPlatform::Facade::getKeyboard(Keys)
{
	return false;
}

float windowsPlatform::Facade::getDelta()
{
	return 0.0f;
}

void windowsPlatform::Facade::setTag(std::string)
{
}

void windowsPlatform::Facade::setResolution(Vector2)
{
}

void windowsPlatform::Facade::setBorderless()
{
}

void windowsPlatform::Facade::setWindowed()
{
}
