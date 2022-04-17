#pragma once

#include <Windows.h>
#include <string>

#include "Vector2.h"
#include "Buttons.h"
#include "Keys.h"

namespace windowsPlatform
{
	class Facade
	{
	public:
		Facade();
		virtual ~Facade();

		virtual void update();
		virtual HWND getWindow();
		virtual bool getQuit();
		virtual bool getMinimise();
		virtual Vector2 getCursor();
		virtual Vector2 getDrag();
		virtual bool getMouse(Buttons);
		virtual bool getKeyboard(Keys);
		virtual float getDelta();
		virtual void setTag(std::string);
		virtual void setResolution(Vector2);
		virtual void setBorderless();
		virtual void setWindowed();
	};
}
