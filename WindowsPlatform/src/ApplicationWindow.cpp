#include "ApplicationWindow.h"

WindowsPlatform::ApplicationWindow::ApplicationWindow(HINSTANCE hInstance, int nCmdShowValue, std::string tag)
	: nCmdShow{ nCmdShowValue }, windowClass(), window(), quit{ false }, minimise{ false }, cursor(), drag(), buttons{ false }
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
	resetDrag();
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

WindowsPlatform::Vector2 WindowsPlatform::ApplicationWindow::getCursor()
{
	return cursor;
}

WindowsPlatform::Vector2 WindowsPlatform::ApplicationWindow::getDrag()
{
	return drag;
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

void WindowsPlatform::ApplicationWindow::setResolution(Vector2 value)
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

RECT WindowsPlatform::ApplicationWindow::getWindowRectangle(Vector2 value)
{
	ResolutionValidator validator;
	validator.setResolution((int)value.x, (int)value.y);

	RECT windowRect = {
		0,
		0,
		validator.getWidth(),
		validator.getHeight()
	};

	return windowRect;
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

void WindowsPlatform::ApplicationWindow::resetDrag()
{
	drag.x = 0.0f;
	drag.y = 0.0f;
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
	if (active)
	{
		return processMessage(hWnd, msg, wParam, lParam);
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT WindowsPlatform::ApplicationWindow::processMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
		processCursor(lParam);
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
		processXbuttonDown(wParam);
		return 0;
	}
	break;
	case WM_MOUSEWHEEL:
	{
		processMouseWheel(wParam);
		return 0;
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
		processXbuttonUp(wParam);
		return 0;
	}
	break;
	case WM_KEYDOWN:
	{
		processKeyDown(wParam);
		return 0;
	}
	break;
	case WM_KEYUP:
	{
		processKeyUp(wParam);
		return 0;
	}
	break;
	case WM_SYSKEYDOWN:
	{
		processKeyDown(wParam);
		return 0;
	}
	break;
	case WM_SYSKEYUP:
	{
		processKeyUp(wParam);
		return 0;
	}
	break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void WindowsPlatform::ApplicationWindow::processMinimise(WPARAM wParam)
{
	if (wParam != SIZE_MINIMIZED)
	{
		return;
	}

	active->minimise = true;
}

void WindowsPlatform::ApplicationWindow::processCursor(LPARAM lParam)
{
	active->cursor.x = (float)GET_X_LPARAM(lParam);
	active->cursor.y = (float)GET_Y_LPARAM(lParam);
}

void WindowsPlatform::ApplicationWindow::processDrag(LPARAM lParam)
{
	RAWINPUT* rawInput = initialiseRawInputData(lParam);

	if (rawInput->header.dwType != RIM_TYPEMOUSE)
	{
		return;
	}

	active->drag.x = (float)rawInput->data.mouse.lLastX;
	active->drag.y = (float)rawInput->data.mouse.lLastY;
}

RAWINPUT* WindowsPlatform::ApplicationWindow::initialiseRawInputData(LPARAM lParam)
{
	UINT dwSize = sizeof(RAWINPUT);
	static BYTE lpb[sizeof(RAWINPUT)];

	GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

	return (RAWINPUT*)lpb;
}

void WindowsPlatform::ApplicationWindow::processXbuttonDown(WPARAM wParam)
{
	if (GET_XBUTTON_WPARAM(wParam) != XBUTTON2)
	{
		active->buttons[(unsigned int)WindowsButtons::mouse_MB4] = true;
		return;
	}
	
	active->buttons[(unsigned int)WindowsButtons::mouse_MB5] = true;
}

void WindowsPlatform::ApplicationWindow::processMouseWheel(WPARAM wParam)
{
	if (GET_WHEEL_DELTA_WPARAM(wParam) > 0)
	{
		active->buttons[(unsigned int)WindowsButtons::mouse_scrollForwards] = true;
		return;
	}

	active->buttons[(unsigned int)WindowsButtons::mouse_scrollBackwards] = true;
}

void WindowsPlatform::ApplicationWindow::processXbuttonUp(WPARAM wParam)
{
	if (GET_XBUTTON_WPARAM(wParam) != XBUTTON2)
	{
		active->buttons[(unsigned int)WindowsButtons::mouse_MB4] = false;
		return;
	}

	active->buttons[(unsigned int)WindowsButtons::mouse_MB5] = false;
}

void WindowsPlatform::ApplicationWindow::processKeyDown(WPARAM wParam)
{
	active->buttons[(unsigned int)getButtonIndex(wParam)] = true;
}

void WindowsPlatform::ApplicationWindow::processKeyUp(WPARAM wParam)
{
	active->buttons[(unsigned int)getButtonIndex(wParam)] = false;
}

WindowsPlatform::WindowsButtons WindowsPlatform::ApplicationWindow::getButtonIndex(WPARAM wParam)
{
	switch (wParam)
	{
	case VK_ESCAPE:
	{
		return WindowsButtons::keyboard_ESC;
	}
	break;
	case VK_F1:
	{
		return WindowsButtons::keyboard_F1;
	}
	break;
	case VK_F2:
	{
		return WindowsButtons::keyboard_F2;
	}
	break;
	case VK_F3:
	{
		return WindowsButtons::keyboard_F3;
	}
	break;
	case VK_F4:
	{
		return WindowsButtons::keyboard_F4;
	}
	break;
	case VK_F5:
	{
		return WindowsButtons::keyboard_F5;
	}
	break;
	case VK_F6:
	{
		return WindowsButtons::keyboard_F6;
	}
	break;
	case VK_F7:
	{
		return WindowsButtons::keyboard_F7;
	}
	break;
	case VK_F8:
	{
		return WindowsButtons::keyboard_F8;
	}
	break;
	case VK_F9:
	{
		return WindowsButtons::keyboard_F9;
	}
	break;
	case VK_F10:
	{
		return WindowsButtons::keyboard_F10;
	}
	break;
	case VK_SCROLL:
	{
		return WindowsButtons::keyboard_scrollLock;
	}
	break;
	case VK_PAUSE:
	{
		return WindowsButtons::keyboard_pause;
	}
	break;
	case 0x31:
	{
		return WindowsButtons::keyboard_1;
	}
	break;
	case 0x32:
	{
		return WindowsButtons::keyboard_2;
	}
	break;
	case 0x33:
	{
		return WindowsButtons::keyboard_3;
	}
	break;
	case 0x34:
	{
		return WindowsButtons::keyboard_4;
	}
	break;
	case 0x35:
	{
		return WindowsButtons::keyboard_5;
	}
	break;
	case 0x36:
	{
		return WindowsButtons::keyboard_6;
	}
	break;
	case 0x37:
	{
		return WindowsButtons::keyboard_7;
	}
	break;
	case 0x38:
	{
		return WindowsButtons::keyboard_8;
	}
	break;
	case 0x39:
	{
		return WindowsButtons::keyboard_9;
	}
	break;
	case 0x30:
	{
		return WindowsButtons::keyboard_0;
	}
	break;
	case VK_OEM_MINUS:
	{
		return WindowsButtons::keyboard_dash;
	}
	break;
	case VK_OEM_PLUS:
	{
		return WindowsButtons::keyboard_equals;
	}
	break;
	case VK_BACK:
	{
		return WindowsButtons::keyboard_backspace;
	}
	break;
	case VK_INSERT:
	{
		return WindowsButtons::keyboard_insert;
	}
	break;
	case VK_HOME:
	{
		return WindowsButtons::keyboard_home;
	}
	break;
	case VK_PRIOR:
	{
		return WindowsButtons::keyboard_pageUp;
	}
	break;
	case VK_TAB:
	{
		return WindowsButtons::keyboard_tab;
	}
	break;
	case 0x51:
	{
		return WindowsButtons::keyboard_q;
	}
	break;
	case 0x57:
	{
		return WindowsButtons::keyboard_w;
	}
	break;
	case 0x45:
	{
		return WindowsButtons::keyboard_e;
	}
	break;
	case 0x52:
	{
		return WindowsButtons::keyboard_r;
	}
	break;
	case 0x54:
	{
		return WindowsButtons::keyboard_t;
	}
	break;
	case 0x59:
	{
		return WindowsButtons::keyboard_y;
	}
	break;
	case 0x55:
	{
		return WindowsButtons::keyboard_u;
	}
	break;
	case 0x49:
	{
		return WindowsButtons::keyboard_i;
	}
	break;
	case 0x4F:
	{
		return WindowsButtons::keyboard_o;
	}
	break;
	case 0x50:
	{
		return WindowsButtons::keyboard_p;
	}
	break;
	case VK_OEM_4:
	{
		return WindowsButtons::keyboard_openBrace;
	}
	break;
	case VK_OEM_6:
	{
		return WindowsButtons::keyboard_closeBrace;
	}
	break;
	case VK_RETURN:
	{
		return WindowsButtons::keyboard_enter;
	}
	break;
	case VK_DELETE:
	{
		return WindowsButtons::keyboard_delete;
	}
	break;
	case VK_END:
	{
		return WindowsButtons::keyboard_end;
	}
	break;
	case VK_NEXT:
	{
		return WindowsButtons::keyboard_pageDown;
	}
	break;
	case VK_CAPITAL:
	{
		return WindowsButtons::keyboard_caps;
	}
	break;
	case 0x41:
	{
		return WindowsButtons::keyboard_a;
	}
	break;
	case 0x53:
	{
		return WindowsButtons::keyboard_s;
	}
	break;
	case 0x44:
	{
		return WindowsButtons::keyboard_d;
	}
	break;
	case 0x46:
	{
		return WindowsButtons::keyboard_f;
	}
	break;
	case 0x47:
	{
		return WindowsButtons::keyboard_g;
	}
	break;
	case 0x48:
	{
		return WindowsButtons::keyboard_h;
	}
	break;
	case 0x4A:
	{
		return WindowsButtons::keyboard_j;
	}
	break;
	case 0x4B:
	{
		return WindowsButtons::keyboard_k;
	}
	break;
	case 0x4C:
	{
		return WindowsButtons::keyboard_l;
	}
	break;
	case VK_OEM_1:
	{
		return WindowsButtons::keyboard_semicolon;
	}
	break;
	case VK_OEM_3:
	{
		return WindowsButtons::keyboard_at;
	}
	break;
	case VK_OEM_7:
	{
		return WindowsButtons::keyboard_hash;
	}
	break;
	case VK_SHIFT:
	{
		return WindowsButtons::keyboard_shift;
	}
	break;
	case VK_OEM_5:
	{
		return WindowsButtons::keyboard_backslash;
	}
	break;
	case 0x5A:
	{
		return WindowsButtons::keyboard_z;
	}
	break;
	case 0x58:
	{
		return WindowsButtons::keyboard_x;
	}
	break;
	case 0x43:
	{
		return WindowsButtons::keyboard_c;
	}
	break;
	case 0x56:
	{
		return WindowsButtons::keyboard_v;
	}
	break;
	case 0x42:
	{
		return WindowsButtons::keyboard_b;
	}
	break;
	case 0x4E:
	{
		return WindowsButtons::keyboard_n;
	}
	break;
	case 0x4D:
	{
		return WindowsButtons::keyboard_m;
	}
	break;
	case VK_OEM_COMMA:
	{
		return WindowsButtons::keyboard_comma;
	}
	break;
	case VK_OEM_PERIOD:
	{
		return WindowsButtons::keyboard_stop;
	}
	break;
	case VK_OEM_2:
	{
		return WindowsButtons::keyboard_forwardslash;
	}
	break;
	case VK_CONTROL:
	{
		return WindowsButtons::keyboard_control;
	}
	break;
	case VK_MENU:
	{
		return WindowsButtons::keyboard_alt;
	}
	break;
	case VK_SPACE:
	{
		return WindowsButtons::keyboard_space;
	}
	break;
	case VK_UP:
	{
		return WindowsButtons::keyboard_up;
	}
	break;
	case VK_DOWN:
	{
		return WindowsButtons::keyboard_down;
	}
	break;
	case VK_LEFT:
	{
		return WindowsButtons::keyboard_left;
	}
	break;
	case VK_RIGHT:
	{
		return WindowsButtons::keyboard_right;
	}
	break;
	case VK_NUMLOCK:
	{
		return WindowsButtons::numpad_numlock;
	}
	break;
	case VK_DIVIDE:
	{
		return WindowsButtons::numpad_divide;
	}
	break;
	case VK_MULTIPLY:
	{
		return WindowsButtons::numpad_multiply;
	}
	break;
	case VK_SUBTRACT:
	{
		return WindowsButtons::numpad_subtract;
	}
	break;
	case VK_NUMPAD7:
	{
		return WindowsButtons::numpad_7;
	}
	break;
	case VK_NUMPAD8:
	{
		return WindowsButtons::numpad_8;
	}
	break;
	case VK_NUMPAD9:
	{
		return WindowsButtons::numpad_9;
	}
	break;
	case VK_ADD:
	{
		return WindowsButtons::numpad_add;
	}
	break;
	case VK_NUMPAD4:
	{
		return WindowsButtons::numpad_4;
	}
	break;
	case VK_NUMPAD5:
	{
		return WindowsButtons::numpad_5;
	}
	break;
	case VK_NUMPAD6:
	{
		return WindowsButtons::numpad_6;
	}
	break;
	case VK_NUMPAD1:
	{
		return WindowsButtons::numpad_1;
	}
	break;
	case VK_NUMPAD2:
	{
		return WindowsButtons::numpad_2;
	}
	break;
	case VK_NUMPAD3:
	{
		return WindowsButtons::numpad_3;
	}
	break;
	case VK_NUMPAD0:
	{
		return WindowsButtons::numpad_0;
	}
	break;
	case VK_DECIMAL:
	{
		return WindowsButtons::numpad_stop;
	}
	break;
	}

	return WindowsButtons::windowsButtonsSize;
}

WindowsPlatform::ApplicationWindow* WindowsPlatform::ApplicationWindow::active = nullptr;
