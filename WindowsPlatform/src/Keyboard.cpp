#include "Keyboard.h"

windowsPlatform::Keyboard::Keyboard()
	: keys()
{
	initialiseKeys();
}

windowsPlatform::Keyboard::~Keyboard()
{
}

void windowsPlatform::Keyboard::press(WPARAM wParam)
{
	keys[(int)getIndex(wParam)] = true;
}

void windowsPlatform::Keyboard::release(WPARAM wParam)
{
	keys[(int)getIndex(wParam)] = false;
}

bool windowsPlatform::Keyboard::getKey(KeyboardKeys index)
{
	return keys[(int)index];
}

void windowsPlatform::Keyboard::initialiseKeys()
{
	for (int i{ 0 }; i < (int)KeyboardKeys::size; i++)
	{
		keys[i] = false;
	}
}

windowsPlatform::KeyboardKeys windowsPlatform::Keyboard::getIndex(WPARAM wParam)
{
	switch (wParam)
	{
	case VK_ESCAPE:
	{
		return KeyboardKeys::keyboard_ESC;
	}
	break;
	case VK_F1:
	{
		return KeyboardKeys::keyboard_F1;
	}
	break;
	case VK_F2:
	{
		return KeyboardKeys::keyboard_F2;
	}
	break;
	case VK_F3:
	{
		return KeyboardKeys::keyboard_F3;
	}
	break;
	case VK_F4:
	{
		return KeyboardKeys::keyboard_F4;
	}
	break;
	case VK_F5:
	{
		return KeyboardKeys::keyboard_F5;
	}
	break;
	case VK_F6:
	{
		return KeyboardKeys::keyboard_F6;
	}
	break;
	case VK_F7:
	{
		return KeyboardKeys::keyboard_F7;
	}
	break;
	case VK_F8:
	{
		return KeyboardKeys::keyboard_F8;
	}
	break;
	case VK_F9:
	{
		return KeyboardKeys::keyboard_F9;
	}
	break;
	case VK_F10:
	{
		return KeyboardKeys::keyboard_F10;
	}
	break;
	case VK_SCROLL:
	{
		return KeyboardKeys::keyboard_scrollLock;
	}
	break;
	case VK_PAUSE:
	{
		return KeyboardKeys::keyboard_pause;
	}
	break;
	case 0x31:
	{
		return KeyboardKeys::keyboard_1;
	}
	break;
	case 0x32:
	{
		return KeyboardKeys::keyboard_2;
	}
	break;
	case 0x33:
	{
		return KeyboardKeys::keyboard_3;
	}
	break;
	case 0x34:
	{
		return KeyboardKeys::keyboard_4;
	}
	break;
	case 0x35:
	{
		return KeyboardKeys::keyboard_5;
	}
	break;
	case 0x36:
	{
		return KeyboardKeys::keyboard_6;
	}
	break;
	case 0x37:
	{
		return KeyboardKeys::keyboard_7;
	}
	break;
	case 0x38:
	{
		return KeyboardKeys::keyboard_8;
	}
	break;
	case 0x39:
	{
		return KeyboardKeys::keyboard_9;
	}
	break;
	case 0x30:
	{
		return KeyboardKeys::keyboard_0;
	}
	break;
	case VK_OEM_MINUS:
	{
		return KeyboardKeys::keyboard_dash;
	}
	break;
	case VK_OEM_PLUS:
	{
		return KeyboardKeys::keyboard_equals;
	}
	break;
	case VK_BACK:
	{
		return KeyboardKeys::keyboard_backspace;
	}
	break;
	case VK_INSERT:
	{
		return KeyboardKeys::keyboard_insert;
	}
	break;
	case VK_HOME:
	{
		return KeyboardKeys::keyboard_home;
	}
	break;
	case VK_PRIOR:
	{
		return KeyboardKeys::keyboard_pageUp;
	}
	break;
	case VK_TAB:
	{
		return KeyboardKeys::keyboard_tab;
	}
	break;
	case 0x51:
	{
		return KeyboardKeys::keyboard_q;
	}
	break;
	case 0x57:
	{
		return KeyboardKeys::keyboard_w;
	}
	break;
	case 0x45:
	{
		return KeyboardKeys::keyboard_e;
	}
	break;
	case 0x52:
	{
		return KeyboardKeys::keyboard_r;
	}
	break;
	case 0x54:
	{
		return KeyboardKeys::keyboard_t;
	}
	break;
	case 0x59:
	{
		return KeyboardKeys::keyboard_y;
	}
	break;
	case 0x55:
	{
		return KeyboardKeys::keyboard_u;
	}
	break;
	case 0x49:
	{
		return KeyboardKeys::keyboard_i;
	}
	break;
	case 0x4F:
	{
		return KeyboardKeys::keyboard_o;
	}
	break;
	case 0x50:
	{
		return KeyboardKeys::keyboard_p;
	}
	break;
	case VK_OEM_4:
	{
		return KeyboardKeys::keyboard_openBrace;
	}
	break;
	case VK_OEM_6:
	{
		return KeyboardKeys::keyboard_closeBrace;
	}
	break;
	case VK_RETURN:
	{
		return KeyboardKeys::keyboard_enter;
	}
	break;
	case VK_DELETE:
	{
		return KeyboardKeys::keyboard_delete;
	}
	break;
	case VK_END:
	{
		return KeyboardKeys::keyboard_end;
	}
	break;
	case VK_NEXT:
	{
		return KeyboardKeys::keyboard_pageDown;
	}
	break;
	case VK_CAPITAL:
	{
		return KeyboardKeys::keyboard_caps;
	}
	break;
	case 0x41:
	{
		return KeyboardKeys::keyboard_a;
	}
	break;
	case 0x53:
	{
		return KeyboardKeys::keyboard_s;
	}
	break;
	case 0x44:
	{
		return KeyboardKeys::keyboard_d;
	}
	break;
	case 0x46:
	{
		return KeyboardKeys::keyboard_f;
	}
	break;
	case 0x47:
	{
		return KeyboardKeys::keyboard_g;
	}
	break;
	case 0x48:
	{
		return KeyboardKeys::keyboard_h;
	}
	break;
	case 0x4A:
	{
		return KeyboardKeys::keyboard_j;
	}
	break;
	case 0x4B:
	{
		return KeyboardKeys::keyboard_k;
	}
	break;
	case 0x4C:
	{
		return KeyboardKeys::keyboard_l;
	}
	break;
	case VK_OEM_1:
	{
		return KeyboardKeys::keyboard_semicolon;
	}
	break;
	case VK_OEM_3:
	{
		return KeyboardKeys::keyboard_at;
	}
	break;
	case VK_OEM_7:
	{
		return KeyboardKeys::keyboard_hash;
	}
	break;
	case VK_SHIFT:
	{
		return KeyboardKeys::keyboard_shift;
	}
	break;
	case VK_OEM_5:
	{
		return KeyboardKeys::keyboard_backslash;
	}
	break;
	case 0x5A:
	{
		return KeyboardKeys::keyboard_z;
	}
	break;
	case 0x58:
	{
		return KeyboardKeys::keyboard_x;
	}
	break;
	case 0x43:
	{
		return KeyboardKeys::keyboard_c;
	}
	break;
	case 0x56:
	{
		return KeyboardKeys::keyboard_v;
	}
	break;
	case 0x42:
	{
		return KeyboardKeys::keyboard_b;
	}
	break;
	case 0x4E:
	{
		return KeyboardKeys::keyboard_n;
	}
	break;
	case 0x4D:
	{
		return KeyboardKeys::keyboard_m;
	}
	break;
	case VK_OEM_COMMA:
	{
		return KeyboardKeys::keyboard_comma;
	}
	break;
	case VK_OEM_PERIOD:
	{
		return KeyboardKeys::keyboard_stop;
	}
	break;
	case VK_OEM_2:
	{
		return KeyboardKeys::keyboard_forwardslash;
	}
	break;
	case VK_CONTROL:
	{
		return KeyboardKeys::keyboard_control;
	}
	break;
	case VK_MENU:
	{
		return KeyboardKeys::keyboard_alt;
	}
	break;
	case VK_SPACE:
	{
		return KeyboardKeys::keyboard_space;
	}
	break;
	case VK_UP:
	{
		return KeyboardKeys::keyboard_up;
	}
	break;
	case VK_DOWN:
	{
		return KeyboardKeys::keyboard_down;
	}
	break;
	case VK_LEFT:
	{
		return KeyboardKeys::keyboard_left;
	}
	break;
	case VK_RIGHT:
	{
		return KeyboardKeys::keyboard_right;
	}
	break;
	case VK_NUMLOCK:
	{
		return KeyboardKeys::numpad_numlock;
	}
	break;
	case VK_DIVIDE:
	{
		return KeyboardKeys::numpad_divide;
	}
	break;
	case VK_MULTIPLY:
	{
		return KeyboardKeys::numpad_multiply;
	}
	break;
	case VK_SUBTRACT:
	{
		return KeyboardKeys::numpad_subtract;
	}
	break;
	case VK_NUMPAD7:
	{
		return KeyboardKeys::numpad_7;
	}
	break;
	case VK_NUMPAD8:
	{
		return KeyboardKeys::numpad_8;
	}
	break;
	case VK_NUMPAD9:
	{
		return KeyboardKeys::numpad_9;
	}
	break;
	case VK_ADD:
	{
		return KeyboardKeys::numpad_add;
	}
	break;
	case VK_NUMPAD4:
	{
		return KeyboardKeys::numpad_4;
	}
	break;
	case VK_NUMPAD5:
	{
		return KeyboardKeys::numpad_5;
	}
	break;
	case VK_NUMPAD6:
	{
		return KeyboardKeys::numpad_6;
	}
	break;
	case VK_NUMPAD1:
	{
		return KeyboardKeys::numpad_1;
	}
	break;
	case VK_NUMPAD2:
	{
		return KeyboardKeys::numpad_2;
	}
	break;
	case VK_NUMPAD3:
	{
		return KeyboardKeys::numpad_3;
	}
	break;
	case VK_NUMPAD0:
	{
		return KeyboardKeys::numpad_0;
	}
	break;
	case VK_DECIMAL:
	{
		return KeyboardKeys::numpad_stop;
	}
	break;
	}

	return KeyboardKeys();
}
