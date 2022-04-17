#pragma once

#include <Windows.h>
#include <Windowsx.h>
#include <hidusage.h>
#include <string>
#include <codecvt>

#include "SubordinateFacade.h"
#include "Window.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Delta.h"

namespace windowsPlatform
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
		virtual bool getMouse(Buttons);
		virtual bool getKeyboard(Keys);
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
		Window window;
		bool quit;
		bool minimise;
		Vector2 drag;
		Mouse mouse;
		Keyboard keyboard;
		Delta delta;
		static SubordinateImplimentation* active;
	};
}
