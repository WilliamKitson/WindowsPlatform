#pragma once

#include <Windows.h>
#include <Windowsx.h>
#include <hidusage.h>
#include <string>
#include <codecvt>

#include "MouseState.h"
#include "WindowsButtons.h"
#include "Resolution.h"

namespace WindowsPlatform
{
	class ApplicationWindow
	{
	public:
		ApplicationWindow(HINSTANCE, int, std::string);
		~ApplicationWindow();

		void update();
		HWND getWindow();
		bool getQuit();
		bool getMinimise();
		MouseState getMouse();
		bool getButton(WindowsButtons);
		void setTag(std::string);
		void setResolution(Resolution);
		void setBorderless();
		void setWindowed();


	private:
		void initialise(HINSTANCE, std::wstring);
		HRESULT initialiseWindowClass(HINSTANCE, std::wstring);
		HRESULT initialiseWindow(std::wstring);
		DWORD getWindowed();
		HRESULT initialiseRawInput();
		int validateWidth(int);
		int validateHeight(int);
		void resetQuit();
		void resetMinimise();
		void resetDrag();
		void resetScrollForwards();
		void resetScrollBackwards();
		void messageLoop();
		static LRESULT CALLBACK applicationWindowProcedure(HWND, UINT, WPARAM, LPARAM);
		static void processMouseDrag(LPARAM);


	private:
		const int nCmdShow;
		WNDCLASSEX windowClass;
		HWND window;
		bool quit;
		bool minimise;
		MouseState mouse;
		bool buttons[(unsigned int)WindowsButtons::windowsButtonsSize];
		static ApplicationWindow* active;
	};
}

