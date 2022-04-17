#include "Implimentation.h"

windowsPlatform::Implimentation::Implimentation(HINSTANCE hInstance, int nCmdShow, std::string tag)
	: Facade(), windowClass(), window(nCmdShow), quit{ false }, minimise{ false }, drag(), mouse(), keyboard(), delta()
{
	initialise(hInstance, std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag));
}

windowsPlatform::Implimentation::~Implimentation()
{
}

void windowsPlatform::Implimentation::update()
{
	resetQuit();
	resetMinimise();
	resetDrag();
	mouse.reset();
	messageLoop();
	delta.update();
}

HWND windowsPlatform::Implimentation::getWindow()
{
    return window.getWindow();
}

bool windowsPlatform::Implimentation::getQuit()
{
	return quit;
}

bool windowsPlatform::Implimentation::getMinimise()
{
	return minimise;
}

windowsPlatform::Vector2 windowsPlatform::Implimentation::getCursor()
{
	return mouse.getCursor();
}

windowsPlatform::Vector2 windowsPlatform::Implimentation::getDrag()
{
	return drag;
}

bool windowsPlatform::Implimentation::getMouse(Buttons button)
{
	return mouse.getButton(button);
}

bool windowsPlatform::Implimentation::getKeyboard(Keys key)
{
	return keyboard.getKey(key);
}

float windowsPlatform::Implimentation::getDelta()
{
	return delta.getDelta();
}

void windowsPlatform::Implimentation::setTag(std::string value)
{
	window.setTag(value);
}

void windowsPlatform::Implimentation::setResolution(Vector2 value)
{
	window.setResolution(value);
}

void windowsPlatform::Implimentation::setBorderless()
{
	window.borderless();
}

void windowsPlatform::Implimentation::setWindowed()
{
	window.windowed();
}

void windowsPlatform::Implimentation::initialise(HINSTANCE hInstance, std::wstring tag)
{
	if (FAILED(initialiseWindowClass(hInstance, tag)))
	{
		return;
	}

	if (FAILED(initialiseRawInput()))
	{
		return;
	}
}

HRESULT windowsPlatform::Implimentation::initialiseWindowClass(HINSTANCE hInstance, std::wstring tag)
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = applicationWindowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = tag.c_str();

	if (RegisterClassEx(&windowClass))
	{
		window.initialise(windowClass);
		return S_OK;
	}

	return E_FAIL;
}

HRESULT windowsPlatform::Implimentation::initialiseRawInput()
{
	RAWINPUTDEVICE rawInputDevice[1];

	rawInputDevice[0] = RAWINPUTDEVICE{
		HID_USAGE_PAGE_GENERIC,
		HID_USAGE_GENERIC_MOUSE,
		RIDEV_INPUTSINK,
		window.getWindow()
	};

	if (RegisterRawInputDevices(rawInputDevice, 1, sizeof(rawInputDevice[0])))
	{
		return S_OK;
	}

	return E_FAIL;
}

void windowsPlatform::Implimentation::resetQuit()
{
	quit = false;
}

void windowsPlatform::Implimentation::resetMinimise()
{
	minimise = false;
}

void windowsPlatform::Implimentation::resetDrag()
{
	drag = Vector2();
}

void windowsPlatform::Implimentation::messageLoop()
{
	MSG message;
	active = this;

	while (PeekMessage(&message, window.getWindow(), 0, 0, PM_REMOVE))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	active = nullptr;
}

LRESULT CALLBACK windowsPlatform::Implimentation::applicationWindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (active)
	{
		return processMessage(hWnd, msg, wParam, lParam);
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT windowsPlatform::Implimentation::processMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
		active->mouse.press(Buttons::mouse_LMB);
		return 0;
	}
	break;
	case WM_RBUTTONDOWN:
	{
		active->mouse.press(Buttons::mouse_RMB);
		return 0;
	}
	break;
	case WM_MBUTTONDOWN:
	{
		active->mouse.press(Buttons::mouse_MMB);
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
		active->mouse.release(Buttons::mouse_LMB);
		return 0;
	}
	break;
	case WM_RBUTTONUP:
	{
		active->mouse.release(Buttons::mouse_RMB);
		return 0;
	}
	break;
	case WM_MBUTTONUP:
	{
		active->mouse.release(Buttons::mouse_MMB);
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

void windowsPlatform::Implimentation::processMinimise(WPARAM wParam)
{
	if (wParam != SIZE_MINIMIZED)
	{
		return;
	}

	active->minimise = true;
}

void windowsPlatform::Implimentation::processDrag(LPARAM lParam)
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

RAWINPUT* windowsPlatform::Implimentation::initialiseRawInputData(LPARAM lParam)
{
	UINT dwSize = sizeof(RAWINPUT);
	static BYTE lpb[sizeof(RAWINPUT)];

	GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

	return (RAWINPUT*)lpb;
}

windowsPlatform::Implimentation* windowsPlatform::Implimentation::active = nullptr;
