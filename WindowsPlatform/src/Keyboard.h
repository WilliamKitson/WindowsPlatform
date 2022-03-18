#pragma once

#include "KeyboardKeys.h"

namespace WindowsPlatform
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		bool getKey(KeyboardKeys);
	};
}

