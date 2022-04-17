#include "KeyboardPressTest.h"

KeyboardPressTest::KeyboardPressTest()
	: successes{ 0 }
{
}

KeyboardPressTest::~KeyboardPressTest()
{
}

std::string KeyboardPressTest::test()
{
	windowsPlatform::Keyboard unit;

	for (int i{ 0 }; i < (int)windowsPlatform::Keys::size; i++)
	{
		unit.press(getWparam((windowsPlatform::Keys)i));
		successes += unit.getKey((windowsPlatform::Keys)i) == true;
	}

	if (successes == (int)windowsPlatform::Keys::size)
	{
		return std::string();
	}

	return "keyboard press test failed\n";
}

WPARAM KeyboardPressTest::getWparam(windowsPlatform::Keys key)
{
	switch (key)
	{
	case windowsPlatform::Keys::keyboard_ESC:
	{
		return VK_ESCAPE;
	}
	break;
	case windowsPlatform::Keys::keyboard_F1:
	{
		return VK_F1;
	}
	break;
	case windowsPlatform::Keys::keyboard_F2:
	{
		return VK_F2;
	}
	break;
	case windowsPlatform::Keys::keyboard_F3:
	{
		return VK_F3;
	}
	break;
	case windowsPlatform::Keys::keyboard_F4:
	{
		return VK_F4;
	}
	break;
	case windowsPlatform::Keys::keyboard_F5:
	{
		return VK_F5;
	}
	break;
	case windowsPlatform::Keys::keyboard_F6:
	{
		return VK_F6;
	}
	break;
	case windowsPlatform::Keys::keyboard_F7:
	{
		return VK_F7;
	}
	break;
	case windowsPlatform::Keys::keyboard_F8:
	{
		return VK_F8;
	}
	break;
	case windowsPlatform::Keys::keyboard_F9:
	{
		return VK_F9;
	}
	break;
	case windowsPlatform::Keys::keyboard_F10:
	{
		return VK_F10;
	}
	break;
	case windowsPlatform::Keys::keyboard_scrollLock:
	{
		return VK_SCROLL;
	}
	break;
	case windowsPlatform::Keys::keyboard_pause:
	{
		return VK_PAUSE;
	}
	break;
	case windowsPlatform::Keys::keyboard_1:
	{
		return 0x31;
	}
	break;
	case windowsPlatform::Keys::keyboard_2:
	{
		return 0x32;
	}
	break;
	case windowsPlatform::Keys::keyboard_3:
	{
		return 0x33;
	}
	break;
	case windowsPlatform::Keys::keyboard_4:
	{
		return 0x34;
	}
	break;
	case windowsPlatform::Keys::keyboard_5:
	{
		return 0x35;
	}
	break;
	case windowsPlatform::Keys::keyboard_6:
	{
		return 0x36;
	}
	break;
	case windowsPlatform::Keys::keyboard_7:
	{
		return 0x37;
	}
	break;
	case windowsPlatform::Keys::keyboard_8:
	{
		return 0x38;
	}
	break;
	case windowsPlatform::Keys::keyboard_9:
	{
		return 0x39;
	}
	break;
	case windowsPlatform::Keys::keyboard_0:
	{
		return 0x30;
	}
	break;
	case windowsPlatform::Keys::keyboard_dash:
	{
		return VK_OEM_MINUS;
	}
	break;
	case windowsPlatform::Keys::keyboard_equals:
	{
		return VK_OEM_PLUS;
	}
	break;
	case windowsPlatform::Keys::keyboard_backspace:
	{
		return VK_BACK;
	}
	break;
	case windowsPlatform::Keys::keyboard_insert:
	{
		return VK_INSERT;
	}
	break;
	case windowsPlatform::Keys::keyboard_home:
	{
		return VK_HOME;
	}
	break;
	case windowsPlatform::Keys::keyboard_pageUp:
	{
		return VK_PRIOR;
	}
	break;
	case windowsPlatform::Keys::keyboard_tab:
	{
		return VK_TAB;
	}
	break;
	case windowsPlatform::Keys::keyboard_q:
	{
		return 0x51;
	}
	break;
	case windowsPlatform::Keys::keyboard_w:
	{
		return 0x57;
	}
	break;
	case windowsPlatform::Keys::keyboard_e:
	{
		return 0x45;
	}
	break;
	case windowsPlatform::Keys::keyboard_r:
	{
		return 0x52;
	}
	break;
	case windowsPlatform::Keys::keyboard_t:
	{
		return 0x54;
	}
	break;
	case windowsPlatform::Keys::keyboard_y:
	{
		return 0x59;
	}
	break;
	case windowsPlatform::Keys::keyboard_u:
	{
		return 0x55;
	}
	break;
	case windowsPlatform::Keys::keyboard_i:
	{
		return 0x49;
	}
	break;
	case windowsPlatform::Keys::keyboard_o:
	{
		return 0x4F;
	}
	break;
	case windowsPlatform::Keys::keyboard_p:
	{
		return 0x50;
	}
	break;
	case windowsPlatform::Keys::keyboard_openBrace:
	{
		return VK_OEM_4;
	}
	break;
	case windowsPlatform::Keys::keyboard_closeBrace:
	{
		return VK_OEM_6;
	}
	break;
	case windowsPlatform::Keys::keyboard_enter:
	{
		return VK_RETURN;
	}
	break;
	case windowsPlatform::Keys::keyboard_delete:
	{
		return VK_DELETE;
	}
	break;
	case windowsPlatform::Keys::keyboard_end:
	{
		return VK_END;
	}
	break;
	case windowsPlatform::Keys::keyboard_pageDown:
	{
		return VK_NEXT;
	}
	break;
	case windowsPlatform::Keys::keyboard_caps:
	{
		return VK_CAPITAL;
	}
	break;
	case windowsPlatform::Keys::keyboard_a:
	{
		return 0x41;
	}
	break;
	case windowsPlatform::Keys::keyboard_s:
	{
		return 0x53;
	}
	break;
	case windowsPlatform::Keys::keyboard_d:
	{
		return 0x44;
	}
	break;
	case windowsPlatform::Keys::keyboard_f:
	{
		return 0x46;
	}
	break;
	case windowsPlatform::Keys::keyboard_g:
	{
		return 0x47;
	}
	break;
	case windowsPlatform::Keys::keyboard_h:
	{
		return 0x48;
	}
	break;
	case windowsPlatform::Keys::keyboard_j:
	{
		return 0x4A;
	}
	break;
	case windowsPlatform::Keys::keyboard_k:
	{
		return 0x4B;
	}
	break;
	case windowsPlatform::Keys::keyboard_l:
	{
		return 0x4C;
	}
	break;
	case windowsPlatform::Keys::keyboard_semicolon:
	{
		return VK_OEM_1;
	}
	break;
	case windowsPlatform::Keys::keyboard_at:
	{
		return VK_OEM_3;
	}
	break;
	case windowsPlatform::Keys::keyboard_hash:
	{
		return VK_OEM_7;
	}
	break;
	case windowsPlatform::Keys::keyboard_shift:
	{
		return VK_SHIFT;
	}
	break;
	case windowsPlatform::Keys::keyboard_backslash:
	{
		return VK_OEM_5;
	}
	break;
	case windowsPlatform::Keys::keyboard_z:
	{
		return 0x5A;
	}
	break;
	case windowsPlatform::Keys::keyboard_x:
	{
		return 0x58;
	}
	break;
	case windowsPlatform::Keys::keyboard_c:
	{
		return 0x43;
	}
	break;
	case windowsPlatform::Keys::keyboard_v:
	{
		return 0x56;
	}
	break;
	case windowsPlatform::Keys::keyboard_b:
	{
		return 0x42;
	}
	break;
	case windowsPlatform::Keys::keyboard_n:
	{
		return 0x4E;
	}
	break;
	case windowsPlatform::Keys::keyboard_m:
	{
		return 0x4D;
	}
	break;
	case windowsPlatform::Keys::keyboard_comma:
	{
		return VK_OEM_COMMA;
	}
	break;
	case windowsPlatform::Keys::keyboard_stop:
	{
		return VK_OEM_PERIOD;
	}
	break;
	case windowsPlatform::Keys::keyboard_forwardslash:
	{
		return VK_OEM_2;
	}
	break;
	case windowsPlatform::Keys::keyboard_control:
	{
		return VK_CONTROL;
	}
	break;
	case windowsPlatform::Keys::keyboard_alt:
	{
		return VK_MENU;
	}
	break;
	case windowsPlatform::Keys::keyboard_space:
	{
		return VK_SPACE;
	}
	break;
	case windowsPlatform::Keys::keyboard_up:
	{
		return VK_UP;
	}
	break;
	case windowsPlatform::Keys::keyboard_down:
	{
		return VK_DOWN;
	}
	break;
	case windowsPlatform::Keys::keyboard_left:
	{
		return VK_LEFT;
	}
	break;
	case windowsPlatform::Keys::keyboard_right:
	{
		return VK_RIGHT;
	}
	break;
	case windowsPlatform::Keys::numpad_numlock:
	{
		return VK_NUMLOCK;
	}
	break;
	case windowsPlatform::Keys::numpad_divide:
	{
		return VK_DIVIDE;
	}
	break;
	case windowsPlatform::Keys::numpad_multiply:
	{
		return VK_MULTIPLY;
	}
	break;
	case windowsPlatform::Keys::numpad_subtract:
	{
		return VK_SUBTRACT;
	}
	break;
	case windowsPlatform::Keys::numpad_7:
	{
		return VK_NUMPAD7;
	}
	break;
	case windowsPlatform::Keys::numpad_8:
	{
		return VK_NUMPAD8;
	}
	break;
	case windowsPlatform::Keys::numpad_9:
	{
		return VK_NUMPAD9;
	}
	break;
	case windowsPlatform::Keys::numpad_add:
	{
		return VK_ADD;
	}
	break;
	case windowsPlatform::Keys::numpad_4:
	{
		return VK_NUMPAD4;
	}
	break;
	case windowsPlatform::Keys::numpad_5:
	{
		return VK_NUMPAD5;
	}
	break;
	case windowsPlatform::Keys::numpad_6:
	{
		return VK_NUMPAD6;
	}
	break;
	case windowsPlatform::Keys::numpad_1:
	{
		return VK_NUMPAD1;
	}
	break;
	case windowsPlatform::Keys::numpad_2:
	{
		return VK_NUMPAD2;
	}
	break;
	case windowsPlatform::Keys::numpad_3:
	{
		return VK_NUMPAD3;
	}
	break;
	case windowsPlatform::Keys::numpad_0:
	{
		return VK_NUMPAD0;
	}
	break;
	case windowsPlatform::Keys::numpad_stop:
	{
		return VK_DECIMAL;
	}
	break;
	}

	return WPARAM();
}
