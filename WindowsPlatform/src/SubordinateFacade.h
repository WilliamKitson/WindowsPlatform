#pragma once

#include <Windows.h>

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
	};
}

