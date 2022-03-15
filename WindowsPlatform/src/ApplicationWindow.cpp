#include "ApplicationWindow.h"

WindowsPlatform::ApplicationWindow::ApplicationWindow(HINSTANCE hInstance, int nCmdShowValue, std::string tag)
	: nCmdShow{ nCmdShowValue }, windowClass(), window(), quit{ false }, minimise{ false }, mouse(), buttons{ false }
{
	initialise(hInstance, std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(tag));
}

WindowsPlatform::ApplicationWindow::~ApplicationWindow()
{
	DestroyWindow(window);
}

void WindowsPlatform::ApplicationWindow::update()
{
	resetQuit();
	resetMinimise();
	resetScrollForwards();
	resetScrollBackwards();
	messageLoop();
}

HWND WindowsPlatform::ApplicationWindow::getWindow()
{
    return window;
}

bool WindowsPlatform::ApplicationWindow::getQuit()
{
	return quit;
}

bool WindowsPlatform::ApplicationWindow::getMinimise()
{
	return minimise;
}

WindowsPlatform::MouseState WindowsPlatform::ApplicationWindow::getMouse()
{
	return mouse;
}

bool WindowsPlatform::ApplicationWindow::getButton(WindowsButtons button)
{
	return buttons[(unsigned int)button];
}

void WindowsPlatform::ApplicationWindow::setTag(std::string value)
{
	SetWindowTextA(
		window,
		value.c_str()
	);
}

void WindowsPlatform::ApplicationWindow::setResolution(Resolution value)
{
	RECT windowRect = {
		0,
		0,
		validateWidth(value.width),
		validateHeight(value.height)
	};

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

void WindowsPlatform::ApplicationWindow::setBorderless()
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

void WindowsPlatform::ApplicationWindow::setWindowed()
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

void WindowsPlatform::ApplicationWindow::initialise(HINSTANCE hInstance, std::wstring tag)
{
	if (FAILED(initialiseWindowClass(hInstance, tag)))
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

HRESULT WindowsPlatform::ApplicationWindow::initialiseWindowClass(HINSTANCE hInstance, std::wstring tag)
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

HRESULT WindowsPlatform::ApplicationWindow::initialiseWindow(std::wstring tag)
{
	RECT windowRect = {
		0,
		0,
		validateWidth(0),
		validateHeight(0)
	};

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

DWORD WindowsPlatform::ApplicationWindow::getWindowed()
{
	return { WS_TILED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION };
}

HRESULT WindowsPlatform::ApplicationWindow::initialiseRawInput()
{
	RAWINPUTDEVICE rawInputDevice[1];

	rawInputDevice[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
	rawInputDevice[0].usUsage = HID_USAGE_GENERIC_MOUSE;
	rawInputDevice[0].dwFlags = RIDEV_INPUTSINK;
	rawInputDevice[0].hwndTarget = window;

	if (RegisterRawInputDevices(rawInputDevice, 1, sizeof(rawInputDevice[0])))
	{
		return S_OK;
	}

	return E_FAIL;
}

int WindowsPlatform::ApplicationWindow::validateWidth(int width)
{
	const int min{ 960 };

	if (width < min)
	{
		return min;
	}

	return width;
}

int WindowsPlatform::ApplicationWindow::validateHeight(int height)
{
	const int min{ 540 };

	if (height < min)
	{
		return min;
	}

	return height;
}

void WindowsPlatform::ApplicationWindow::resetQuit()
{
	if (quit)
	{
		quit = false;
	}
}

void WindowsPlatform::ApplicationWindow::resetMinimise()
{
	if (minimise)
	{
		minimise = false;
	}
}

void WindowsPlatform::ApplicationWindow::resetScrollForwards()
{
	if (buttons[(unsigned int)WindowsButtons::mouse_scrollForwards])
	{
		buttons[(unsigned int)WindowsButtons::mouse_scrollForwards] = false;
	}
}

void WindowsPlatform::ApplicationWindow::resetScrollBackwards()
{
	if (buttons[(unsigned int)WindowsButtons::mouse_scrollBackwards])
	{
		buttons[(unsigned int)WindowsButtons::mouse_scrollBackwards] = false;
	}
}

void WindowsPlatform::ApplicationWindow::messageLoop()
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

LRESULT CALLBACK WindowsPlatform::ApplicationWindow::applicationWindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (!active)
	{
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

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
		if (wParam == SIZE_MINIMIZED)
		{
			active->minimise = true;
			return 0;
		}
	}
	break;
	case WM_MOUSEMOVE:
	{
		active->mouse.xpos = GET_X_LPARAM(lParam);
		active->mouse.ypos = GET_Y_LPARAM(lParam);
	}
	break;
	case WM_INPUT:
	{
		UINT dwSize = sizeof(RAWINPUT);
		static BYTE lpb[sizeof(RAWINPUT)];

		GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

		RAWINPUT* rawinput = (RAWINPUT*)lpb;

		if (rawinput->header.dwType == RIM_TYPEMOUSE)
		{
			//active->dragX = rawinput->data.mouse.lLastX;
			//active->dragY = rawinput->data.mouse.lLastY;
		}

		return 0;
	}
	break;
	case WM_LBUTTONDOWN:
	{
		active->buttons[(unsigned int)WindowsButtons::mouse_LMB] = true;
		return 0;
	}
	break;
	case WM_RBUTTONDOWN:
	{
		active->buttons[(unsigned int)WindowsButtons::mouse_RMB] = true;
		return 0;
	}
	break;
	case WM_MBUTTONDOWN:
	{
		active->buttons[(unsigned int)WindowsButtons::mouse_MMB] = true;
		return 0;
	}
	break;
	case WM_XBUTTONDOWN:
	{
		if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1)
		{
			active->buttons[(unsigned int)WindowsButtons::mouse_MB4] = true;
			return 0;
		}
		else
		{
			active->buttons[(unsigned int)WindowsButtons::mouse_MB5] = true;
			return 0;
		}
	}
	break;
	case WM_MOUSEWHEEL:
	{
		if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
		{
			active->buttons[(unsigned int)WindowsButtons::mouse_scrollForwards] = true;
			return 0;
		}
		else
		{
			active->buttons[(unsigned int)WindowsButtons::mouse_scrollBackwards] = true;
			return 0;
		}
	}
	break;
	case WM_LBUTTONUP:
	{
		active->buttons[(unsigned int)WindowsButtons::mouse_LMB] = false;
		return 0;
	}
	break;
	case WM_RBUTTONUP:
	{
		active->buttons[(unsigned int)WindowsButtons::mouse_RMB] = false;
		return 0;
	}
	break;
	case WM_MBUTTONUP:
	{
		active->buttons[(unsigned int)WindowsButtons::mouse_MMB] = false;
		return 0;
	}
	break;
	case WM_XBUTTONUP:
	{
		if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1)
		{
			active->buttons[(unsigned int)WindowsButtons::mouse_MB4] = false;
			return 0;
		}
		else
		{
			active->buttons[(unsigned int)WindowsButtons::mouse_MB5] = false;
			return 0;
		}
	}
	break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_ESC] = true;
			return 0;
		}
		break;
		case VK_F1:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F1] = true;
			return 0;
		}
		break;
		case VK_F2:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F2] = true;
			return 0;
		}
		break;
		case VK_F3:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F3] = true;
			return 0;
		}
		break;
		case VK_F4:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F4] = true;
			return 0;
		}
		break;
		case VK_F5:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F5] = true;
			return 0;
		}
		break;
		case VK_F6:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F6] = true;
			return 0;
		}
		break;
		case VK_F7:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F7] = true;
			return 0;
		}
		break;
		case VK_F8:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F8] = true;
			return 0;
		}
		break;
		case VK_F9:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F9] = true;
			return 0;
		}
		break;
		case VK_SCROLL:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_scrollLock] = true;
			return 0;
		}
		break;
		case VK_PAUSE:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_pause] = true;
			return 0;
		}
		break;
		case 0x31:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_1] = true;
			return 0;
		}
		break;
		case 0x32:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_2] = true;
			return 0;
		}
		break;
		case 0x33:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_3] = true;
			return 0;
		}
		break;
		case 0x34:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_4] = true;
			return 0;
		}
		break;
		case 0x35:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_5] = true;
			return 0;
		}
		break;
		case 0x36:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_6] = true;
			return 0;
		}
		break;
		case 0x37:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_7] = true;
			return 0;
		}
		break;
		case 0x38:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_8] = true;
			return 0;
		}
		break;
		case 0x39:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_9] = true;
			return 0;
		}
		break;
		case 0x30:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_0] = true;
			return 0;
		}
		break;
		case VK_OEM_MINUS:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_dash] = true;
			return 0;
		}
		break;
		case VK_OEM_PLUS:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_equals] = true;
			return 0;
		}
		break;
		case VK_BACK:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_backspace] = true;
			return 0;
		}
		break;
		case VK_INSERT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_insert] = true;
			return 0;
		}
		break;
		case VK_HOME:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_home] = true;
			return 0;
		}
		break;
		case VK_PRIOR:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_pageUp] = true;
			return 0;
		}
		break;
		case VK_TAB:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_tab] = true;
			return 0;
		}
		break;
		case 0x51:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_q] = true;
			return 0;
		}
		break;
		case 0x57:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_w] = true;
			return 0;
		}
		break;
		case 0x45:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_e] = true;
			return 0;
		}
		break;
		case 0x52:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_r] = true;
			return 0;
		}
		break;
		case 0x54:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_t] = true;
			return 0;
		}
		break;
		case 0x59:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_y] = true;
			return 0;
		}
		break;
		case 0x55:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_u] = true;
			return 0;
		}
		break;
		case 0x49:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_i] = true;
			return 0;
		}
		break;
		case 0x4F:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_o] = true;
			return 0;
		}
		break;
		case 0x50:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_p] = true;
			return 0;
		}
		break;
		case VK_OEM_4:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_openBrace] = true;
			return 0;
		}
		break;
		case VK_OEM_6:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_closeBrace] = true;
			return 0;
		}
		break;
		case VK_RETURN:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_enter] = true;
			return 0;
		}
		break;
		case VK_DELETE:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_delete] = true;
			return 0;
		}
		break;
		case VK_END:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_end] = true;
			return 0;
		}
		break;
		case VK_NEXT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_pageDown] = true;
			return 0;
		}
		break;
		case VK_CAPITAL:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_caps] = true;
			return 0;
		}
		break;
		case 0x41:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_a] = true;
			return 0;
		}
		break;
		case 0x53:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_s] = true;
			return 0;
		}
		break;
		case 0x44:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_d] = true;
			return 0;
		}
		break;
		case 0x46:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_f] = true;
			return 0;
		}
		break;
		case 0x47:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_g] = true;
			return 0;
		}
		break;
		case 0x48:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_h] = true;
			return 0;
		}
		break;
		case 0x4A:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_j] = true;
			return 0;
		}
		break;
		case 0x4B:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_k] = true;
			return 0;
		}
		break;
		case 0x4C:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_l] = true;
			return 0;
		}
		break;
		case VK_OEM_1:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_semicolon] = true;
			return 0;
		}
		break;
		case VK_OEM_3:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_at] = true;
			return 0;
		}
		break;
		case VK_OEM_7:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_hash] = true;
			return 0;
		}
		break;
		case VK_SHIFT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_shift] = true;
			return 0;
		}
		break;
		case VK_OEM_5:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_backslash] = true;
			return 0;
		}
		break;
		case 0x5A:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_z] = true;
			return 0;
		}
		break;
		case 0x58:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_x] = true;
			return 0;
		}
		break;
		case 0x43:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_c] = true;
			return 0;
		}
		break;
		case 0x56:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_v] = true;
			return 0;
		}
		break;
		case 0x42:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_b] = true;
			return 0;
		}
		break;
		case 0x4E:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_n] = true;
			return 0;
		}
		break;
		case 0x4D:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_m] = true;
			return 0;
		}
		break;
		case VK_OEM_COMMA:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_comma] = true;
			return 0;
		}
		break;
		case VK_OEM_PERIOD:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_stop] = true;
			return 0;
		}
		break;
		case VK_OEM_2:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_forwardslash] = true;
			return 0;
		}
		break;
		case VK_CONTROL:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_control] = true;
			return 0;
		}
		break;
		case VK_SPACE:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_space] = true;
			return 0;
		}
		break;
		case VK_UP:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_up] = true;
			return 0;
		}
		break;
		case VK_DOWN:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_down] = true;
			return 0;
		}
		break;
		case VK_LEFT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_left] = true;
			return 0;
		}
		break;
		case VK_RIGHT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_right] = true;
			return 0;
		}
		break;
		case VK_NUMLOCK:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_numlock] = true;
			return 0;
		}
		break;
		case VK_DIVIDE:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_divide] = true;
			return 0;
		}
		break;
		case VK_MULTIPLY:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_multiply] = true;
			return 0;
		}
		break;
		case VK_SUBTRACT:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_subtract] = true;
			return 0;
		}
		break;
		case VK_NUMPAD7:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_7] = true;
			return 0;
		}
		break;
		case VK_NUMPAD8:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_8] = true;
			return 0;
		}
		break;
		case VK_NUMPAD9:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_9] = true;
			return 0;
		}
		break;
		case VK_ADD:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_add] = true;
			return 0;
		}
		break;
		case VK_NUMPAD4:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_4] = true;
			return 0;
		}
		break;
		case VK_NUMPAD5:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_5] = true;
			return 0;
		}
		break;
		case VK_NUMPAD6:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_6] = true;
			return 0;
		}
		break;
		case VK_NUMPAD1:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_1] = true;
			return 0;
		}
		break;
		case VK_NUMPAD2:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_2] = true;
			return 0;
		}
		break;
		case VK_NUMPAD3:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_3] = true;
			return 0;
		}
		break;
		case VK_NUMPAD0:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_0] = true;
			return 0;
		}
		break;
		case VK_DECIMAL:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_stop] = true;
			return 0;
		}
		break;
		}
	}
	break;
	case WM_KEYUP:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_ESC] = false;
			return 0;
		}
		break;
		case VK_F1:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F1] = false;
			return 0;
		}
		break;
		case VK_F2:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F2] = false;
			return 0;
		}
		break;
		case VK_F3:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F3] = false;
			return 0;
		}
		break;
		case VK_F4:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F4] = false;
			return 0;
		}
		break;
		case VK_F5:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F5] = false;
			return 0;
		}
		break;
		case VK_F6:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F6] = false;
			return 0;
		}
		break;
		case VK_F7:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F7] = false;
			return 0;
		}
		break;
		case VK_F8:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F8] = false;
			return 0;
		}
		break;
		case VK_F9:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F9] = false;
			return 0;
		}
		break;
		case VK_SCROLL:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_scrollLock] = false;
			return 0;
		}
		break;
		case VK_PAUSE:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_pause] = false;
			return 0;
		}
		break;
		case 0x31:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_1] = false;
			return 0;
		}
		break;
		case 0x32:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_2] = false;
			return 0;
		}
		break;
		case 0x33:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_3] = false;
			return 0;
		}
		break;
		case 0x34:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_4] = false;
			return 0;
		}
		break;
		case 0x35:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_5] = false;
			return 0;
		}
		break;
		case 0x36:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_6] = false;
			return 0;
		}
		break;
		case 0x37:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_7] = false;
			return 0;
		}
		break;
		case 0x38:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_8] = false;
			return 0;
		}
		break;
		case 0x39:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_9] = false;
			return 0;
		}
		break;
		case 0x30:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_0] = false;
			return 0;
		}
		break;
		case VK_OEM_MINUS:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_dash] = false;
			return 0;
		}
		break;
		case VK_OEM_PLUS:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_equals] = false;
			return 0;
		}
		break;
		case VK_BACK:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_backspace] = false;
			return 0;
		}
		break;
		case VK_INSERT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_insert] = false;
			return 0;
		}
		break;
		case VK_HOME:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_home] = false;
			return 0;
		}
		break;
		case VK_PRIOR:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_pageUp] = false;
			return 0;
		}
		break;
		case VK_TAB:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_tab] = false;
			return 0;
		}
		break;
		case 0x51:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_q] = false;
			return 0;
		}
		break;
		case 0x57:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_w] = false;
			return 0;
		}
		break;
		case 0x45:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_e] = false;
			return 0;
		}
		break;
		case 0x52:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_r] = false;
			return 0;
		}
		break;
		case 0x54:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_t] = false;
			return 0;
		}
		break;
		case 0x59:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_y] = false;
			return 0;
		}
		break;
		case 0x55:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_u] = false;
			return 0;
		}
		break;
		case 0x49:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_i] = false;
			return 0;
		}
		break;
		case 0x4F:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_o] = false;
			return 0;
		}
		break;
		case 0x50:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_p] = false;
			return 0;
		}
		break;
		case VK_OEM_4:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_openBrace] = false;
			return 0;
		}
		break;
		case VK_OEM_6:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_closeBrace] = false;
			return 0;
		}
		break;
		case VK_RETURN:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_enter] = false;
			return 0;
		}
		break;
		case VK_DELETE:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_delete] = false;
			return 0;
		}
		break;
		case VK_END:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_end] = false;
			return 0;
		}
		break;
		case VK_NEXT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_pageDown] = false;
			return 0;
		}
		break;
		case VK_CAPITAL:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_caps] = false;
			return 0;
		}
		break;
		case 0x41:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_a] = false;
			return 0;
		}
		break;
		case 0x53:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_s] = false;
			return 0;
		}
		break;
		case 0x44:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_d] = false;
			return 0;
		}
		break;
		case 0x46:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_f] = false;
			return 0;
		}
		break;
		case 0x47:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_g] = false;
			return 0;
		}
		break;
		case 0x48:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_h] = false;
			return 0;
		}
		break;
		case 0x4A:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_j] = false;
			return 0;
		}
		break;
		case 0x4B:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_k] = false;
			return 0;
		}
		break;
		case 0x4C:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_l] = false;
			return 0;
		}
		break;
		case VK_OEM_1:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_semicolon] = false;
			return 0;
		}
		break;
		case VK_OEM_3:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_at] = false;
			return 0;
		}
		break;
		case VK_OEM_7:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_hash] = false;
			return 0;
		}
		break;
		case VK_SHIFT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_shift] = false;
			return 0;
		}
		break;
		case VK_OEM_5:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_backslash] = false;
			return 0;
		}
		break;
		case 0x5A:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_z] = false;
			return 0;
		}
		break;
		case 0x58:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_x] = false;
			return 0;
		}
		break;
		case 0x43:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_c] = false;
			return 0;
		}
		break;
		case 0x56:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_v] = false;
			return 0;
		}
		break;
		case 0x42:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_b] = false;
			return 0;
		}
		break;
		case 0x4E:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_n] = false;
			return 0;
		}
		break;
		case 0x4D:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_m] = false;
			return 0;
		}
		break;
		case VK_OEM_COMMA:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_comma] = false;
			return 0;
		}
		break;
		case VK_OEM_PERIOD:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_stop] = false;
			return 0;
		}
		break;
		case VK_OEM_2:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_forwardslash] = false;
			return 0;
		}
		break;
		case VK_CONTROL:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_control] = false;
			return 0;
		}
		break;
		case VK_SPACE:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_space] = false;
			return 0;
		}
		break;
		case VK_UP:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_up] = false;
			return 0;
		}
		break;
		case VK_DOWN:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_down] = false;
			return 0;
		}
		break;
		case VK_LEFT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_left] = false;
			return 0;
		}
		break;
		case VK_RIGHT:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_right] = false;
			return 0;
		}
		break;
		case VK_NUMLOCK:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_numlock] = false;
			return 0;
		}
		break;
		case VK_DIVIDE:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_divide] = false;
			return 0;
		}
		break;
		case VK_MULTIPLY:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_multiply] = false;
			return 0;
		}
		break;
		case VK_SUBTRACT:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_subtract] = false;
			return 0;
		}
		break;
		case VK_NUMPAD7:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_7] = false;
			return 0;
		}
		break;
		case VK_NUMPAD8:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_8] = false;
			return 0;
		}
		break;
		case VK_NUMPAD9:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_9] = false;
			return 0;
		}
		break;
		case VK_ADD:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_add] = false;
			return 0;
		}
		break;
		case VK_NUMPAD4:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_4] = false;
			return 0;
		}
		break;
		case VK_NUMPAD5:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_5] = false;
			return 0;
		}
		break;
		case VK_NUMPAD6:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_6] = false;
			return 0;
		}
		break;
		case VK_NUMPAD1:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_1] = false;
			return 0;
		}
		break;
		case VK_NUMPAD2:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_2] = false;
			return 0;
		}
		break;
		case VK_NUMPAD3:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_3] = false;
			return 0;
		}
		break;
		case VK_NUMPAD0:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_0] = false;
			return 0;
		}
		break;
		case VK_DECIMAL:
		{
			active->buttons[(unsigned int)WindowsButtons::numpad_stop] = false;
			return 0;
		}
		break;
		}
	}
	break;
	case WM_SYSKEYDOWN:
	{
		switch (wParam)
		{
		case VK_F10:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F10] = true;
			return 0;
		}
		break;
		case VK_MENU:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_alt] = true;
			return 0;
		}
		break;
		}
	}
	break;
	case WM_SYSKEYUP:
	{
		switch (wParam)
		{
		case VK_F10:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_F10] = false;
			return 0;
		}
		break;
		case VK_MENU:
		{
			active->buttons[(unsigned int)WindowsButtons::keyboard_alt] = false;
			return 0;
		}
		break;
		}
	}
	break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

WindowsPlatform::ApplicationWindow* WindowsPlatform::ApplicationWindow::active = nullptr;
