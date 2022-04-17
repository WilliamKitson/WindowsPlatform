#pragma once

#include <Windows.h>
#include "Keys.h"

namespace windowsPlatform
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		void press(WPARAM);
		void release(WPARAM);
		bool getKey(Keys);

	private:
		void initialiseKeys();
		Keys getIndex(WPARAM);

	private:
		bool keys[(int)Keys::size];
	};
}
