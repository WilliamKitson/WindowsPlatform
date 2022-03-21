#pragma once

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

		virtual bool getQuit();
		virtual bool getMinimise();
		virtual Vector2 getCursor();
		virtual Vector2 getDrag();
		virtual bool getMouse(MouseButtons);
		virtual bool getKeyboard(KeyboardKeys);
	};
}

