#include "SubordinateFacade.h"

WindowsPlatform::SubordianteFacade::SubordianteFacade()
{
}

WindowsPlatform::SubordianteFacade::~SubordianteFacade()
{
}

HWND WindowsPlatform::SubordianteFacade::getWindow()
{
	return HWND();
}

bool WindowsPlatform::SubordianteFacade::getQuit()
{
	return false;
}

bool WindowsPlatform::SubordianteFacade::getMinimise()
{
	return false;
}

WindowsPlatform::Vector2 WindowsPlatform::SubordianteFacade::getCursor()
{
	return Vector2();
}

WindowsPlatform::Vector2 WindowsPlatform::SubordianteFacade::getDrag()
{
	return Vector2();
}

bool WindowsPlatform::SubordianteFacade::getMouse(MouseButtons)
{
	return false;
}

bool WindowsPlatform::SubordianteFacade::getKeyboard(KeyboardKeys)
{
	return false;
}

void WindowsPlatform::SubordianteFacade::setTag(std::string)
{
}

void WindowsPlatform::SubordianteFacade::setResolution(Vector2)
{
}

void WindowsPlatform::SubordianteFacade::setBorderless()
{
}
