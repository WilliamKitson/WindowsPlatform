#pragma once

#include <Windows.h>
#include <windowsx.h>

#include "Vector2.h"
#include "Buttons.h"

namespace windowsPlatform
{
	class Mouse
	{
	public:
		Mouse();
		~Mouse();

		void move(LPARAM);
		void press(Buttons);
		void press(WPARAM);
		void wheel(WPARAM);
		void release(Buttons);
		void release(WPARAM);
		void reset();
		Vector2 getCursor();
		bool getButton(Buttons);

	private:
		void initialiseButtons();
		Buttons xbuttonIndex(WPARAM);
		void resetForward();

	private:
		Vector2 cursor;
		bool buttons[(int)Buttons::size];
	};
}
