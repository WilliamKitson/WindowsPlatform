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
