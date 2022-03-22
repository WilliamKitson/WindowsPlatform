#pragma once

#include <Windows.h>
#include <string>

#include "Vector2.h"
#include "ResolutionValidator.h"

namespace WindowsPlatform
{
	class ApplicationWindow
	{
	public:
		ApplicationWindow(int);
		~ApplicationWindow();

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

