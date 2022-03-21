#include "SubordinateFacade.h"

WindowsPlatform::SubordianteFacade::SubordianteFacade()
{
}

WindowsPlatform::SubordianteFacade::~SubordianteFacade()
{
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
