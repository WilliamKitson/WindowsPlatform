#pragma once

#include <Windows.h>
#include <string>

#include "Vector2.h"
#include "Resolution.h"

namespace windowsPlatform
{
	class Window
	{
	public:
		Window(int);
		~Window();

		void initialise(WNDCLASSEX);
		void borderless();
		void windowed();
		HWND getWindow();
		void setTag(std::string);
		void setResolution(Vector2);

	private:
		DWORD getWindowed();
		std::wstring getTag(WNDCLASSEX);
		RECT getWindowRectangle(Vector2);

	private:
		int nCmdShow;
		HWND window;
	};
}
