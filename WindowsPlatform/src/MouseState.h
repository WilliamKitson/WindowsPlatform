#pragma once

namespace WindowsPlatform
{
	struct MouseState
	{
	public:
		bool operator==(MouseState);


	public:
		int xpos{ 0 };
		int ypos{ 0 };
		int xdrag{ 0 };
		int ydrag{ 0 };


	private:
		bool unequalXpos(MouseState);
		bool unequalYpos(MouseState);
		bool unequalXdrag(MouseState);
		bool unequalYdrag(MouseState);
	};
}

