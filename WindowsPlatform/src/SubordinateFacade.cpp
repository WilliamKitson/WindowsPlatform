#include "SubordinateFacade.h"

windowsPlatform::SubordianteFacade::SubordianteFacade()
{
}

windowsPlatform::SubordianteFacade::~SubordianteFacade()
{
}

void windowsPlatform::SubordianteFacade::update()
{
}

HWND windowsPlatform::SubordianteFacade::getWindow()
{
	return HWND();
}

bool windowsPlatform::SubordianteFacade::getQuit()
{
	return false;
}

bool windowsPlatform::SubordianteFacade::getMinimise()
{
	return false;
}

windowsPlatform::Vector2 windowsPlatform::SubordianteFacade::getCursor()
{
	return Vector2();
}

windowsPlatform::Vector2 windowsPlatform::SubordianteFacade::getDrag()
{
	return Vector2();
}

bool windowsPlatform::SubordianteFacade::getMouse(MouseButtons)
{
	return false;
}

bool windowsPlatform::SubordianteFacade::getKeyboard(Keys)
{
	return false;
}

float windowsPlatform::SubordianteFacade::getDelta()
{
	return 0.0f;
}

void windowsPlatform::SubordianteFacade::setTag(std::string)
{
}

void windowsPlatform::SubordianteFacade::setResolution(Vector2)
{
}

void windowsPlatform::SubordianteFacade::setBorderless()
{
}

void windowsPlatform::SubordianteFacade::setWindowed()
{
}
