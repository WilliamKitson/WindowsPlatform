#pragma once

#include "Vector2.h"
#include "MouseButtons.h"

namespace WindowsPlatform
{
	class Mouse
	{
	public:
		Mouse();
		~Mouse();

		Vector2 getCursor();
		Vector2 getDrag();
		bool getButton(MouseButtons);
	};
}

