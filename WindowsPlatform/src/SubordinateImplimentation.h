#pragma once

#include <Windows.h>
#include <Windowsx.h>
#include <hidusage.h>
#include <string>
#include <codecvt>

#include "SubordinateFacade.h"
#include "Vector2.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "ResolutionValidator.h"

namespace WindowsPlatform
{
	class SubordinateImplimentation
		: public SubordianteFacade
	{
	public:
		SubordinateImplimentation(HINSTANCE, int, std::string);
		virtual ~SubordinateImplimentation();

		void update();
		HWND getWindow();
		virtual bool getQuit();
		virtual bool getMinimise();
		virtual Vector2 getCursor();
		virtual Vector2 getDrag();
		virtual bool getMouse(MouseButtons);
		bool getKeyboard(KeyboardKeys);
		void setTag(std::string);
		void setResolution(Vector2);
		void setBorderless();
		void setWindowed();


	private:
		void initialise(HINSTANCE, std::wstring);
		HRESULT registerWindowClass(HINSTANCE, std::wstring);
		HRESULT initialiseWindow(std::wstring);
		RECT getWindowRectangle(Vector2);
		DWORD getWindowed();
		HRESULT initialiseRawInput();
		void resetQuit();
		void resetMinimise();
		void resetDrag();
		void messageLoop();
		static LRESULT CALLBACK applicationWindowProcedure(HWND, UINT, WPARAM, LPARAM);
		static LRESULT processMessage(HWND, UINT, WPARAM, LPARAM);
		static void processMinimise(WPARAM);
		static void processDrag(LPARAM);
		static RAWINPUT* initialiseRawInputData(LPARAM);


	private:
		const int nCmdShow;
		WNDCLASSEX windowClass;
		HWND window;
		bool quit;
		bool minimise;
		Vector2 drag;
		Mouse mouse;
		Keyboard keyboard;
		static SubordinateImplimentation* active;
	};
}

