#pragma once

#include <Windows.h>
#include <Windowsx.h>
#include <hidusage.h>
#include <string>
#include <codecvt>

#include "Vector2.h"
#include "WindowsButtons.h"
#include "ResolutionValidator.h"

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
		Vector2 getCursor();
		Vector2 getDrag();
		bool getButton(WindowsButtons);
		void setTag(std::string);
		void setResolution(Vector2);
		void setBorderless();
		void setWindowed();


	private:
		void initialise(HINSTANCE, std::wstring);
		HRESULT initialiseWindowClass(HINSTANCE, std::wstring);
		HRESULT initialiseWindow(std::wstring);
		RECT getWindowRectangle(Vector2);
		DWORD getWindowed();
		HRESULT initialiseRawInput();
		void resetQuit();
		void resetMinimise();
		void resetDrag();
		void resetScrollForwards();
		void resetScrollBackwards();
		void messageLoop();
		static LRESULT CALLBACK applicationWindowProcedure(HWND, UINT, WPARAM, LPARAM);
		static LRESULT processMessage(HWND, UINT, WPARAM, LPARAM);
		static void processMinimise(WPARAM);
		static void processCursor(LPARAM);
		static void processMouseDrag(LPARAM);
		static RAWINPUT* initialiseRawInputData(LPARAM);
		static void processXbuttonDown(WPARAM);
		static void processMouseWheel(WPARAM);
		static void processXbuttonUp(WPARAM);
		static void processKeyDown(WPARAM);
		static void processKeyUp(WPARAM);
		static WindowsButtons getButtonIndex(WPARAM);


	private:
		const int nCmdShow;
		WNDCLASSEX windowClass;
		HWND window;
		bool quit;
		bool minimise;
		Vector2 cursor;
		Vector2 drag;
		bool buttons[(unsigned int)WindowsButtons::windowsButtonsSize];
		static ApplicationWindow* active;
	};
}

