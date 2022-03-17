#include "SubordinateFacade.h"

WindowsPlatform::SubordinateFacade::SubordinateFacade()
{
}

WindowsPlatform::SubordinateFacade::~SubordinateFacade()
{
}

void WindowsPlatform::SubordinateFacade::update()
{
}

HWND WindowsPlatform::SubordinateFacade::getWindow()
{
	return HWND();
}

bool WindowsPlatform::SubordinateFacade::getQuit()
{
	return false;
}

bool WindowsPlatform::SubordinateFacade::getMinimise()
{
	return false;
}

WindowsPlatform::Vector2 WindowsPlatform::SubordinateFacade::getCursor()
{
	return Vector2();
}

WindowsPlatform::Vector2 WindowsPlatform::SubordinateFacade::getDrag()
{
	return Vector2();
}

bool WindowsPlatform::SubordinateFacade::getButton(WindowsButtons)
{
	return false;
}

void WindowsPlatform::SubordinateFacade::setTag(std::string)
{
}

void WindowsPlatform::SubordinateFacade::setResolution(Vector2)
{
}
