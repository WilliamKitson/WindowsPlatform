#include "SubordinateImplimentation.h"

WindowsPlatform::SubordinateImplimentation::SubordinateImplimentation(HINSTANCE hInstance, int nCmdShow, std::string tag)
	: SubordinateFacade(), window(hInstance, nCmdShow, tag)
{
}

WindowsPlatform::SubordinateImplimentation::~SubordinateImplimentation()
{
}

void WindowsPlatform::SubordinateImplimentation::update()
{
	window.update();
}

HWND WindowsPlatform::SubordinateImplimentation::getWindow()
{
	return window.getWindow();
}

bool WindowsPlatform::SubordinateImplimentation::getQuit()
{
	return window.getQuit();
}

bool WindowsPlatform::SubordinateImplimentation::getMinimise()
{
	return window.getMinimise();
}

WindowsPlatform::Vector2 WindowsPlatform::SubordinateImplimentation::getCursor()
{
	return window.getCursor();
}

WindowsPlatform::Vector2 WindowsPlatform::SubordinateImplimentation::getDrag()
{
	return window.getDrag();
}

bool WindowsPlatform::SubordinateImplimentation::getButton(WindowsButtons button)
{
	return window.getButton(button);
}

void WindowsPlatform::SubordinateImplimentation::setTag(std::string tag)
{
	window.setTag(tag);
}

void WindowsPlatform::SubordinateImplimentation::setResolution(Vector2 resolution)
{
	window.setResolution(resolution);
}

void WindowsPlatform::SubordinateImplimentation::setBorderless()
{
	window.setBorderless();
}

void WindowsPlatform::SubordinateImplimentation::setWindowed()
{
	window.setWindowed();
}
