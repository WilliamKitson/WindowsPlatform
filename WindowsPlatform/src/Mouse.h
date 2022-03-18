#pragma once

#include <Windows.h>
#include <windowsx.h>

#include "Vector2.h"
#include "MouseButtons.h"

namespace WindowsPlatform
{
	class Mouse
	{
	public:
		Mouse();
		~Mouse();

		void move(LPARAM);
		void press(MouseButtons);
		void press(WPARAM);
		void wheel(WPARAM);
		void release(MouseButtons);
		void release(WPARAM);
		void reset();
		Vector2 getCursor();
		bool getButton(MouseButtons);


	private:
		void initialiseButtons();
		MouseButtons xbuttonIndex(WPARAM);


	private:
		Vector2 cursor;
		bool buttons[(int)MouseButtons::size];
	};
}

