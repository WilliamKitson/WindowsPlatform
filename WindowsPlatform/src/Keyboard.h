#pragma once

#include <Windows.h>
#include "KeyboardKeys.h"

namespace WindowsPlatform
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		void press(WPARAM);
		void release(WPARAM);
		bool getKey(KeyboardKeys);


	private:
		void initialiseKeys();
		KeyboardKeys getIndex(WPARAM);


	private:
		bool keys[(int)KeyboardKeys::size];
	};
}

