#pragma once

#include <Windows.h>
#include <string>

namespace WindowsPlatform
{
	class ApplicationWindow
	{
	public:
		ApplicationWindow(int);
		~ApplicationWindow();

		void initialise(WNDCLASSEX);
		HWND getWindow();


	private:
		HRESULT initialiseWindow(WNDCLASSEX);
		DWORD getWindowed();
		std::wstring getTag(WNDCLASSEX);


	private:
		int nCmdShow;
		HWND window;
	};
}

