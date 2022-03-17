#pragma once

#include <Windows.h>
#include <string>

#include "Vector2.h"
#include "WindowsButtons.h"

namespace WindowsPlatform
{
	class SubordinateFacade
	{
	public:
		SubordinateFacade();
		virtual ~SubordinateFacade();

		virtual void update();
		virtual HWND getWindow();
		virtual bool getQuit();
		virtual bool getMinimise();
		virtual Vector2 getCursor();
		virtual Vector2 getDrag();
		virtual bool getButton(WindowsButtons);
		virtual void setTag(std::string);
	};
}

