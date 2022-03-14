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
		float xdrag{ 0.0f };
		float ydrag{ 0.0f };


	private:
		bool unequalXpos(MouseState);
		bool unequalYpos(MouseState);
		bool unequalXdrag(MouseState);
		bool unequalYdrag(MouseState);
	};
}

