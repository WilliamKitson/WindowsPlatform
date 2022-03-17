#pragma once

#include <Windows.h>
#include <string>

#include "SubordinateFacade.h"
#include "ApplicationWindow.h"

namespace WindowsPlatform
{
	class SubordinateImplimentation
		: public SubordinateFacade
	{
	public:
		SubordinateImplimentation(HINSTANCE, int, std::string);
		virtual ~SubordinateImplimentation();

		virtual void update();
		virtual HWND getWindow();
		virtual bool getQuit();
		virtual bool getMinimise();
		virtual Vector2 getCursor();
		virtual bool getButton(WindowsButtons);
		virtual void setTag(std::string);


	private:
		ApplicationWindow window;
	};
}

