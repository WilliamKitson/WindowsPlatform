#pragma once

#include "Vector2.h"

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
	};
}

