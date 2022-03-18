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
		void release(MouseButtons);
		Vector2 getCursor();
		bool getButton(MouseButtons);


	private:
		void initialiseButtons();


	private:
		Vector2 cursor;
		bool buttons[(int)MouseButtons::size];
	};
}

