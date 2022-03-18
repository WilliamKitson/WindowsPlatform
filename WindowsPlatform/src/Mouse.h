#pragma once

#include "Vector2.h"

namespace WindowsPlatform
{
	class Mouse
	{
	public:
		Mouse();
		~Mouse();

		Vector2 getCursor();
	};
}

