#pragma once

#include <Windows.h>
#include <string>

#include "Vector2.h"
#include "MouseButtons.h"
#include "KeyboardKeys.h"

namespace WindowsPlatform
{
	class SubordianteFacade
	{
	public:
		SubordianteFacade();
		virtual ~SubordianteFacade();

		virtual void update();
		virtual HWND getWindow();
		virtual bool getQuit();
		virtual bool getMinimise();
		virtual Vector2 getCursor();
		virtual Vector2 getDrag();
		virtual bool getMouse(MouseButtons);
		virtual bool getKeyboard(KeyboardKeys);
		virtual float getDelta();
		virtual void setTag(std::string);
		virtual void setResolution(Vector2);
		virtual void setBorderless();
		virtual void setWindowed();
	};
}

