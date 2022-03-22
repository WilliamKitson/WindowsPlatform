#pragma once

#include <Windows.h>
#include <Windowsx.h>
#include <hidusage.h>
#include <string>
#include <codecvt>

#include "SubordinateFacade.h"
#include "ApplicationWindow.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "DeltaTimer.h"

namespace WindowsPlatform
{
	class SubordinateImplimentation
		: public SubordianteFacade
	{
	public:
		SubordinateImplimentation(HINSTANCE, int, std::string);
		virtual ~SubordinateImplimentation();

		virtual void update();
		virtual HWND getWindow();
		virtual bool getQuit();
		virtual bool getMinimise();
		virtual Vector2 getCursor();
		virtual Vector2 getDrag();
		virtual bool getMouse(MouseButtons);
		virtual bool getKeyboard(KeyboardKeys);
		virtual float getDelta();
		virtual void setTag(std::string);
		virtual void setResolution(Vector2);
		virtual void setBorderless();
		virtual void setWindowed();


	private:
		void initialise(HINSTANCE, std::wstring);
		HRESULT initialiseWindowClass(HINSTANCE, std::wstring);
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
		WNDCLASSEX windowClass;
		ApplicationWindow window;
		bool quit;
		bool minimise;
		Vector2 drag;
		Mouse mouse;
		Keyboard keyboard;
		DeltaTimer delta;
		static SubordinateImplimentation* active;
	};
}

