#include "SubordinateImplimentation.h"

WindowsPlatform::SubordinateImplimentation::SubordinateImplimentation(HINSTANCE hInstance, int nCmdShowValue, std::string tag)
	: SubordianteFacade(), nCmdShow{ nCmdShowValue }, windowClass(), window(), quit{ false }, minimise{ false }, drag(), mouse(), keyboard()
{
	initialise(hInstance, std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag));
}

WindowsPlatform::SubordinateImplimentation::~SubordinateImplimentation()
{
	DestroyWindow(window);
}

void WindowsPlatform::SubordinateImplimentation::update()
{
	resetQuit();
	resetMinimise();
	resetDrag();
	mouse.reset();
	messageLoop();
}

HWND WindowsPlatform::SubordinateImplimentation::getWindow()
{
    return window;
}

bool WindowsPlatform::SubordinateImplimentation::getQuit()
{
	return quit;
}

bool WindowsPlatform::SubordinateImplimentation::getMinimise()
{
	return minimise;
}

WindowsPlatform::Vector2 WindowsPlatform::SubordinateImplimentation::getCursor()
{
	return mouse.getCursor();
}

WindowsPlatform::Vector2 WindowsPlatform::SubordinateImplimentation::getDrag()
{
	return drag;
}

bool WindowsPlatform::SubordinateImplimentation::getMouse(MouseButtons button)
{
	return mouse.getButton(button);
}

bool WindowsPlatform::SubordinateImplimentation::getKeyboard(KeyboardKeys key)
{
	return keyboard.getKey(key);
}

void WindowsPlatform::SubordinateImplimentation::setTag(std::string value)
{
	SetWindowTextA(
		window,
		value.c_str()
	);
}

void WindowsPlatform::SubordinateImplimentation::setResolution(Vector2 value)
{
	RECT windowRect = getWindowRectangle(value);

	if (!AdjustWindowRect(&windowRect, (DWORD)GetWindowLongPtr(window, GWL_STYLE), FALSE))
	{
		return;
	}

	if (window)
	{
		MoveWindow(
			window,
			100,
			100,
			windowRect.right - windowRect.left,
			windowRect.bottom - windowRect.top,
			true
		);
	}
}

void WindowsPlatform::SubordinateImplimentation::setBorderless()
{
	SetWindowLongPtr(
		window,
		GWL_STYLE,
		WS_POPUPWINDOW
	);

	ShowWindow(
		window,
		nCmdShow
	);
}

void WindowsPlatform::SubordinateImplimentation::setWindowed()
{
	SetWindowLongPtr(
		window,
		GWL_STYLE,
		getWindowed()
	);

	ShowWindow(
		window,
		nCmdShow
	);
}

void WindowsPlatform::SubordinateImplimentation::initialise(HINSTANCE hInstance, std::wstring tag)
{
	if (FAILED(registerWindowClass(hInstance, tag)))
	{
		return;
	}

	if (FAILED(initialiseWindow(tag)))
	{
		return;
	}

	if (FAILED(initialiseRawInput()))
	{
		return;
	}
}

HRESULT WindowsPlatform::SubordinateImplimentation::registerWindowClass(HINSTANCE hInstance, std::wstring tag)
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = applicationWindowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = tag.c_str();

	if (RegisterClassEx(&windowClass))
	{
		return S_OK;
	}

	return E_FAIL;
}

HRESULT WindowsPlatform::SubordinateImplimentation::initialiseWindow(std::wstring tag)
{
	RECT windowRect = getWindowRectangle(Vector2());

	if (!AdjustWindowRect(&windowRect, getWindowed(), FALSE))
	{
		return E_FAIL;
	}

	window = CreateWindow(
		tag.c_str(),
		tag.c_str(),
		getWindowed(),
		100,
		100,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		NULL,
		NULL,
		windowClass.hInstance,
		NULL
	);

	if (!window)
	{
		return E_FAIL;
	}

	if (ShowWindow(window, nCmdShow))
	{
		return E_FAIL;
	}

	return S_OK;
}

RECT WindowsPlatform::SubordinateImplimentation::getWindowRectangle(Vector2 value)
{
	ResolutionValidator resolution;
	resolution.setResolution((int)value.x, (int)value.y);

	RECT windowRect = {
		0,
		0,
		resolution.getWidth(),
		resolution.getHeight()
	};

	return windowRect;
}

DWORD WindowsPlatform::SubordinateImplimentation::getWindowed()
{
	return { WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION };
}

HRESULT WindowsPlatform::SubordinateImplimentation::initialiseRawInput()
{
	RAWINPUTDEVICE rawInputDevice[1];

	rawInputDevice[0] = RAWINPUTDEVICE{
		HID_USAGE_PAGE_GENERIC,
		HID_USAGE_GENERIC_MOUSE,
		RIDEV_INPUTSINK,
		window
	};

	if (RegisterRawInputDevices(rawInputDevice, 1, sizeof(rawInputDevice[0])))
	{
		return S_OK;
	}

	return E_FAIL;
}

void WindowsPlatform::SubordinateImplimentation::resetQuit()
{
	quit = false;
}

void WindowsPlatform::SubordinateImplimentation::resetMinimise()
{
	minimise = false;
}

void WindowsPlatform::SubordinateImplimentation::resetDrag()
{
	drag = Vector2();
}

void WindowsPlatform::SubordinateImplimentation::messageLoop()
{
	MSG message;
	active = this;

	while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	active = nullptr;
}

LRESULT CALLBACK WindowsPlatform::SubordinateImplimentation::applicationWindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (active)
	{
		return processMessage(hWnd, msg, wParam, lParam);
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT WindowsPlatform::SubordinateImplimentation::processMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
	{
		active->quit = true;
		return 0;
	}
	break;
	case WM_SIZE:
	{
		processMinimise(wParam);
		return 0;
	}
	break;
	case WM_MOUSEMOVE:
	{
		active->mouse.move(lParam);
		return 0;
	}
	break;
	case WM_INPUT:
	{
		processDrag(lParam);
		return 0;
	}
	break;
	case WM_LBUTTONDOWN:
	{
		active->mouse.press(MouseButtons::mouse_LMB);
		return 0;
	}
	break;
	case WM_RBUTTONDOWN:
	{
		active->mouse.press(MouseButtons::mouse_RMB);
		return 0;
	}
	break;
	case WM_MBUTTONDOWN:
	{
		active->mouse.press(MouseButtons::mouse_MMB);
		return 0;
	}
	break;
	case WM_XBUTTONDOWN:
	{
		active->mouse.press(wParam);
		return 0;
	}
	break;
	case WM_MOUSEWHEEL:
	{
		active->mouse.wheel(wParam);
		return 0;
	}
	break;
	case WM_LBUTTONUP:
	{
		active->mouse.release(MouseButtons::mouse_LMB);
		return 0;
	}
	break;
	case WM_RBUTTONUP:
	{
		active->mouse.release(MouseButtons::mouse_RMB);
		return 0;
	}
	break;
	case WM_MBUTTONUP:
	{
		active->mouse.release(MouseButtons::mouse_MMB);
		return 0;
	}
	break;
	case WM_XBUTTONUP:
	{
		active->mouse.release(wParam);
		return 0;
	}
	break;
	case WM_KEYDOWN:
	{
		active->keyboard.press(wParam);
		return 0;
	}
	break;
	case WM_KEYUP:
	{
		active->keyboard.release(wParam);
		return 0;
	}
	break;
	case WM_SYSKEYDOWN:
	{
		active->keyboard.press(wParam);
		return 0;
	}
	break;
	case WM_SYSKEYUP:
	{
		active->keyboard.release(wParam);
		return 0;
	}
	break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void WindowsPlatform::SubordinateImplimentation::processMinimise(WPARAM wParam)
{
	if (wParam != SIZE_MINIMIZED)
	{
		return;
	}

	active->minimise = true;
}

void WindowsPlatform::SubordinateImplimentation::processDrag(LPARAM lParam)
{
	RAWINPUT* rawInput = initialiseRawInputData(lParam);

	if (rawInput->header.dwType != RIM_TYPEMOUSE)
	{
		return;
	}

	Vector2 rawInputDrag{
		(float)rawInput->data.mouse.lLastX,
		(float)rawInput->data.mouse.lLastY
	};

	active->drag = rawInputDrag;
}

RAWINPUT* WindowsPlatform::SubordinateImplimentation::initialiseRawInputData(LPARAM lParam)
{
	UINT dwSize = sizeof(RAWINPUT);
	static BYTE lpb[sizeof(RAWINPUT)];

	GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

	return (RAWINPUT*)lpb;
}

WindowsPlatform::SubordinateImplimentation* WindowsPlatform::SubordinateImplimentation::active = nullptr;
