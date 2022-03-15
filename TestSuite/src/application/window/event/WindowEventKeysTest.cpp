#include "WindowEventKeysTest.h"

WindowEventKeysTest::WindowEventKeysTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, successes{ 0 }
{
}

WindowEventKeysTest::~WindowEventKeysTest()
{
}

std::string WindowEventKeysTest::test()
{
	WindowsPlatform::ApplicationWindow unit{
		hInstance,
		nCmdShow,
		"window event keys test"
	};

	for (int i{ (int)WindowsPlatform::WindowsButtons::keyboard_ESC }; i < (int)WindowsPlatform::WindowsButtons::windowsButtonsSize; i++)
	{
		postDown(unit.getWindow(), (WindowsPlatform::WindowsButtons)i);
		unit.update();
		successes += unit.getButton((WindowsPlatform::WindowsButtons)i) == true;

		postUp(unit.getWindow(), (WindowsPlatform::WindowsButtons)i);
		unit.update();
		successes -= unit.getButton((WindowsPlatform::WindowsButtons)i) == false;
	}

	if (successes == 0)
	{
		return std::string();
	}

	return "window event keys test failed\n";
}

void WindowEventKeysTest::postDown(HWND window, WindowsPlatform::WindowsButtons button)
{
	if (isSysKey(button))
	{
		PostMessage(
			window,
			WM_SYSKEYDOWN,
			getKeyCode(button),
			0
		);

		return;
	}

	PostMessage(
		window,
		WM_KEYDOWN,
		getKeyCode(button),
		0
	);
}

void WindowEventKeysTest::postUp(HWND window, WindowsPlatform::WindowsButtons button)
{
	if (isSysKey(button))
	{
		PostMessage(
			window,
			WM_SYSKEYUP,
			getKeyCode(button),
			0
		);

		return;
	}

	PostMessage(
		window,
		WM_KEYUP,
		getKeyCode(button),
		0
	);
}

bool WindowEventKeysTest::isSysKey(WindowsPlatform::WindowsButtons button)
{
	if (button == WindowsPlatform::WindowsButtons::keyboard_F10)
	{
		return true;
	}

	if (button == WindowsPlatform::WindowsButtons::keyboard_alt)
	{
		return true;
	}

	return false;
}

int WindowEventKeysTest::getKeyCode(WindowsPlatform::WindowsButtons button)
{
	switch (button)
	{
	case WindowsPlatform::WindowsButtons::keyboard_ESC:
	{
		return VK_ESCAPE;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F1:
	{
		return VK_F1;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F2:
	{
		return VK_F2;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F3:
	{
		return VK_F3;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F4:
	{
		return VK_F4;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F5:
	{
		return VK_F5;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F6:
	{
		return VK_F6;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F7:
	{
		return VK_F7;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F8:
	{
		return VK_F8;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F9:
	{
		return VK_F9;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_F10:
	{
		return VK_F10;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_scrollLock:
	{
		return VK_SCROLL;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_pause:
	{
		return VK_PAUSE;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_1:
	{
		return 0x31;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_2:
	{
		return 0x32;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_3:
	{
		return 0x33;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_4:
	{
		return 0x34;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_5:
	{
		return 0x35;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_6:
	{
		return 0x36;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_7:
	{
		return 0x37;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_8:
	{
		return 0x38;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_9:
	{
		return 0x39;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_0:
	{
		return 0x30;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_dash:
	{
		return VK_OEM_MINUS;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_equals:
	{
		return VK_OEM_PLUS;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_backspace:
	{
		return VK_BACK;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_insert:
	{
		return VK_INSERT;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_home:
	{
		return VK_HOME;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_pageUp:
	{
		return VK_PRIOR;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_tab:
	{
		return VK_TAB;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_q:
	{
		return 0x51;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_w:
	{
		return 0x57;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_e:
	{
		return 0x45;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_r:
	{
		return 0x52;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_t:
	{
		return 0x54;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_y:
	{
		return 0x59;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_u:
	{
		return 0x55;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_i:
	{
		return 0x49;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_o:
	{
		return 0x4F;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_p:
	{
		return 0x50;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_openBrace:
	{
		return VK_OEM_4;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_closeBrace:
	{
		return VK_OEM_6;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_enter:
	{
		return VK_RETURN;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_delete:
	{
		return VK_DELETE;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_end:
	{
		return VK_END;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_pageDown:
	{
		return VK_NEXT;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_caps:
	{
		return VK_CAPITAL;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_a:
	{
		return 0x41;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_s:
	{
		return 0x53;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_d:
	{
		return 0x44;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_f:
	{
		return 0x46;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_g:
	{
		return 0x47;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_h:
	{
		return 0x48;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_j:
	{
		return 0x4A;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_k:
	{
		return 0x4B;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_l:
	{
		return 0x4C;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_semicolon:
	{
		return VK_OEM_1;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_at:
	{
		return VK_OEM_3;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_hash:
	{
		return VK_OEM_7;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_shift:
	{
		return VK_SHIFT;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_backslash:
	{
		return VK_OEM_5;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_z:
	{
		return 0x5A;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_x:
	{
		return 0x58;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_c:
	{
		return 0x43;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_v:
	{
		return 0x56;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_b:
	{
		return 0x42;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_n:
	{
		return 0x4E;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_m:
	{
		return 0x4D;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_comma:
	{
		return VK_OEM_COMMA;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_stop:
	{
		return VK_OEM_PERIOD;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_forwardslash:
	{
		return VK_OEM_2;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_control:
	{
		return VK_CONTROL;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_alt:
	{
		return VK_MENU;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_space:
	{
		return VK_SPACE;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_up:
	{
		return VK_UP;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_down:
	{
		return VK_DOWN;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_left:
	{
		return VK_LEFT;
	}
		break;
	case WindowsPlatform::WindowsButtons::keyboard_right:
	{
		return VK_RIGHT;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_numlock:
	{
		return VK_NUMLOCK;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_divide:
	{
		return VK_DIVIDE;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_multiply:
	{
		return VK_MULTIPLY;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_subtract:
	{
		return VK_SUBTRACT;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_7:
	{
		return VK_NUMPAD7;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_8:
	{
		return VK_NUMPAD8;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_9:
	{
		return VK_NUMPAD9;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_add:
	{
		return VK_ADD;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_4:
	{
		return VK_NUMPAD4;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_5:
	{
		return VK_NUMPAD5;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_6:
	{
		return VK_NUMPAD6;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_1:
	{
		return VK_NUMPAD1;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_2:
	{
		return VK_NUMPAD2;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_3:
	{
		return VK_NUMPAD3;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_0:
	{
		return VK_NUMPAD0;
	}
		break;
	case WindowsPlatform::WindowsButtons::numpad_stop:
	{
		return VK_DECIMAL;
	}
		break;
	}

	return 0;
}
