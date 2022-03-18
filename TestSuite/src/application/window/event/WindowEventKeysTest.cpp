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

	for (int i{ 0 }; i < (int)WindowsPlatform::KeyboardKeys::size; i++)
	{
		postDown(unit.getWindow(), (WindowsPlatform::KeyboardKeys)i);
		unit.update();
		successes += unit.getKeyboard((WindowsPlatform::KeyboardKeys)i) == true;

		postUp(unit.getWindow(), (WindowsPlatform::KeyboardKeys)i);
		unit.update();
		successes += unit.getKeyboard((WindowsPlatform::KeyboardKeys)i) == false;
	}

	if ((successes / 2) == (int)WindowsPlatform::KeyboardKeys::size)
	{
		return std::string();
	}

	return "window event keys test failed\n";
}

void WindowEventKeysTest::postDown(HWND window, WindowsPlatform::KeyboardKeys key)
{
	if (isSysKey(key))
	{
		PostMessage(
			window,
			WM_SYSKEYDOWN,
			getKeyCode(key),
			0
		);

		return;
	}

	PostMessage(
		window,
		WM_KEYDOWN,
		getKeyCode(key),
		0
	);
}

void WindowEventKeysTest::postUp(HWND window, WindowsPlatform::KeyboardKeys button)
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

bool WindowEventKeysTest::isSysKey(WindowsPlatform::KeyboardKeys button)
{
	if (button == WindowsPlatform::KeyboardKeys::keyboard_F10)
	{
		return true;
	}

	if (button == WindowsPlatform::KeyboardKeys::keyboard_alt)
	{
		return true;
	}

	return false;
}

WPARAM WindowEventKeysTest::getKeyCode(WindowsPlatform::KeyboardKeys key)
{
	switch (key)
	{
	case WindowsPlatform::KeyboardKeys::keyboard_ESC:
	{
		return VK_ESCAPE;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F1:
	{
		return VK_F1;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F2:
	{
		return VK_F2;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F3:
	{
		return VK_F3;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F4:
	{
		return VK_F4;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F5:
	{
		return VK_F5;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F6:
	{
		return VK_F6;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F7:
	{
		return VK_F7;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F8:
	{
		return VK_F8;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F9:
	{
		return VK_F9;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_F10:
	{
		return VK_F10;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_scrollLock:
	{
		return VK_SCROLL;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_pause:
	{
		return VK_PAUSE;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_1:
	{
		return 0x31;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_2:
	{
		return 0x32;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_3:
	{
		return 0x33;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_4:
	{
		return 0x34;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_5:
	{
		return 0x35;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_6:
	{
		return 0x36;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_7:
	{
		return 0x37;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_8:
	{
		return 0x38;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_9:
	{
		return 0x39;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_0:
	{
		return 0x30;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_dash:
	{
		return VK_OEM_MINUS;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_equals:
	{
		return VK_OEM_PLUS;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_backspace:
	{
		return VK_BACK;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_insert:
	{
		return VK_INSERT;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_home:
	{
		return VK_HOME;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_pageUp:
	{
		return VK_PRIOR;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_tab:
	{
		return VK_TAB;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_q:
	{
		return 0x51;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_w:
	{
		return 0x57;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_e:
	{
		return 0x45;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_r:
	{
		return 0x52;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_t:
	{
		return 0x54;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_y:
	{
		return 0x59;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_u:
	{
		return 0x55;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_i:
	{
		return 0x49;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_o:
	{
		return 0x4F;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_p:
	{
		return 0x50;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_openBrace:
	{
		return VK_OEM_4;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_closeBrace:
	{
		return VK_OEM_6;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_enter:
	{
		return VK_RETURN;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_delete:
	{
		return VK_DELETE;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_end:
	{
		return VK_END;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_pageDown:
	{
		return VK_NEXT;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_caps:
	{
		return VK_CAPITAL;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_a:
	{
		return 0x41;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_s:
	{
		return 0x53;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_d:
	{
		return 0x44;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_f:
	{
		return 0x46;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_g:
	{
		return 0x47;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_h:
	{
		return 0x48;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_j:
	{
		return 0x4A;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_k:
	{
		return 0x4B;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_l:
	{
		return 0x4C;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_semicolon:
	{
		return VK_OEM_1;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_at:
	{
		return VK_OEM_3;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_hash:
	{
		return VK_OEM_7;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_shift:
	{
		return VK_SHIFT;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_backslash:
	{
		return VK_OEM_5;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_z:
	{
		return 0x5A;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_x:
	{
		return 0x58;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_c:
	{
		return 0x43;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_v:
	{
		return 0x56;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_b:
	{
		return 0x42;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_n:
	{
		return 0x4E;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_m:
	{
		return 0x4D;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_comma:
	{
		return VK_OEM_COMMA;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_stop:
	{
		return VK_OEM_PERIOD;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_forwardslash:
	{
		return VK_OEM_2;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_control:
	{
		return VK_CONTROL;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_alt:
	{
		return VK_MENU;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_space:
	{
		return VK_SPACE;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_up:
	{
		return VK_UP;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_down:
	{
		return VK_DOWN;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_left:
	{
		return VK_LEFT;
	}
	break;
	case WindowsPlatform::KeyboardKeys::keyboard_right:
	{
		return VK_RIGHT;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_numlock:
	{
		return VK_NUMLOCK;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_divide:
	{
		return VK_DIVIDE;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_multiply:
	{
		return VK_MULTIPLY;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_subtract:
	{
		return VK_SUBTRACT;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_7:
	{
		return VK_NUMPAD7;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_8:
	{
		return VK_NUMPAD8;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_9:
	{
		return VK_NUMPAD9;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_add:
	{
		return VK_ADD;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_4:
	{
		return VK_NUMPAD4;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_5:
	{
		return VK_NUMPAD5;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_6:
	{
		return VK_NUMPAD6;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_1:
	{
		return VK_NUMPAD1;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_2:
	{
		return VK_NUMPAD2;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_3:
	{
		return VK_NUMPAD3;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_0:
	{
		return VK_NUMPAD0;
	}
	break;
	case WindowsPlatform::KeyboardKeys::numpad_stop:
	{
		return VK_DECIMAL;
	}
	break;
	}

	return WPARAM();
}
