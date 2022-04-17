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

bool windowsPlatform::Keyboard::getKey(Keys index)
{
	return keys[(int)index];
}

void windowsPlatform::Keyboard::initialiseKeys()
{
	for (int i{ 0 }; i < (int)Keys::size; i++)
	{
		keys[i] = false;
	}
}

windowsPlatform::Keys windowsPlatform::Keyboard::getIndex(WPARAM wParam)
{
	switch (wParam)
	{
	case VK_ESCAPE:
	{
		return Keys::keyboard_ESC;
	}
	break;
	case VK_F1:
	{
		return Keys::keyboard_F1;
	}
	break;
	case VK_F2:
	{
		return Keys::keyboard_F2;
	}
	break;
	case VK_F3:
	{
		return Keys::keyboard_F3;
	}
	break;
	case VK_F4:
	{
		return Keys::keyboard_F4;
	}
	break;
	case VK_F5:
	{
		return Keys::keyboard_F5;
	}
	break;
	case VK_F6:
	{
		return Keys::keyboard_F6;
	}
	break;
	case VK_F7:
	{
		return Keys::keyboard_F7;
	}
	break;
	case VK_F8:
	{
		return Keys::keyboard_F8;
	}
	break;
	case VK_F9:
	{
		return Keys::keyboard_F9;
	}
	break;
	case VK_F10:
	{
		return Keys::keyboard_F10;
	}
	break;
	case VK_SCROLL:
	{
		return Keys::keyboard_scrollLock;
	}
	break;
	case VK_PAUSE:
	{
		return Keys::keyboard_pause;
	}
	break;
	case 0x31:
	{
		return Keys::keyboard_1;
	}
	break;
	case 0x32:
	{
		return Keys::keyboard_2;
	}
	break;
	case 0x33:
	{
		return Keys::keyboard_3;
	}
	break;
	case 0x34:
	{
		return Keys::keyboard_4;
	}
	break;
	case 0x35:
	{
		return Keys::keyboard_5;
	}
	break;
	case 0x36:
	{
		return Keys::keyboard_6;
	}
	break;
	case 0x37:
	{
		return Keys::keyboard_7;
	}
	break;
	case 0x38:
	{
		return Keys::keyboard_8;
	}
	break;
	case 0x39:
	{
		return Keys::keyboard_9;
	}
	break;
	case 0x30:
	{
		return Keys::keyboard_0;
	}
	break;
	case VK_OEM_MINUS:
	{
		return Keys::keyboard_dash;
	}
	break;
	case VK_OEM_PLUS:
	{
		return Keys::keyboard_equals;
	}
	break;
	case VK_BACK:
	{
		return Keys::keyboard_backspace;
	}
	break;
	case VK_INSERT:
	{
		return Keys::keyboard_insert;
	}
	break;
	case VK_HOME:
	{
		return Keys::keyboard_home;
	}
	break;
	case VK_PRIOR:
	{
		return Keys::keyboard_pageUp;
	}
	break;
	case VK_TAB:
	{
		return Keys::keyboard_tab;
	}
	break;
	case 0x51:
	{
		return Keys::keyboard_q;
	}
	break;
	case 0x57:
	{
		return Keys::keyboard_w;
	}
	break;
	case 0x45:
	{
		return Keys::keyboard_e;
	}
	break;
	case 0x52:
	{
		return Keys::keyboard_r;
	}
	break;
	case 0x54:
	{
		return Keys::keyboard_t;
	}
	break;
	case 0x59:
	{
		return Keys::keyboard_y;
	}
	break;
	case 0x55:
	{
		return Keys::keyboard_u;
	}
	break;
	case 0x49:
	{
		return Keys::keyboard_i;
	}
	break;
	case 0x4F:
	{
		return Keys::keyboard_o;
	}
	break;
	case 0x50:
	{
		return Keys::keyboard_p;
	}
	break;
	case VK_OEM_4:
	{
		return Keys::keyboard_openBrace;
	}
	break;
	case VK_OEM_6:
	{
		return Keys::keyboard_closeBrace;
	}
	break;
	case VK_RETURN:
	{
		return Keys::keyboard_enter;
	}
	break;
	case VK_DELETE:
	{
		return Keys::keyboard_delete;
	}
	break;
	case VK_END:
	{
		return Keys::keyboard_end;
	}
	break;
	case VK_NEXT:
	{
		return Keys::keyboard_pageDown;
	}
	break;
	case VK_CAPITAL:
	{
		return Keys::keyboard_caps;
	}
	break;
	case 0x41:
	{
		return Keys::keyboard_a;
	}
	break;
	case 0x53:
	{
		return Keys::keyboard_s;
	}
	break;
	case 0x44:
	{
		return Keys::keyboard_d;
	}
	break;
	case 0x46:
	{
		return Keys::keyboard_f;
	}
	break;
	case 0x47:
	{
		return Keys::keyboard_g;
	}
	break;
	case 0x48:
	{
		return Keys::keyboard_h;
	}
	break;
	case 0x4A:
	{
		return Keys::keyboard_j;
	}
	break;
	case 0x4B:
	{
		return Keys::keyboard_k;
	}
	break;
	case 0x4C:
	{
		return Keys::keyboard_l;
	}
	break;
	case VK_OEM_1:
	{
		return Keys::keyboard_semicolon;
	}
	break;
	case VK_OEM_3:
	{
		return Keys::keyboard_at;
	}
	break;
	case VK_OEM_7:
	{
		return Keys::keyboard_hash;
	}
	break;
	case VK_SHIFT:
	{
		return Keys::keyboard_shift;
	}
	break;
	case VK_OEM_5:
	{
		return Keys::keyboard_backslash;
	}
	break;
	case 0x5A:
	{
		return Keys::keyboard_z;
	}
	break;
	case 0x58:
	{
		return Keys::keyboard_x;
	}
	break;
	case 0x43:
	{
		return Keys::keyboard_c;
	}
	break;
	case 0x56:
	{
		return Keys::keyboard_v;
	}
	break;
	case 0x42:
	{
		return Keys::keyboard_b;
	}
	break;
	case 0x4E:
	{
		return Keys::keyboard_n;
	}
	break;
	case 0x4D:
	{
		return Keys::keyboard_m;
	}
	break;
	case VK_OEM_COMMA:
	{
		return Keys::keyboard_comma;
	}
	break;
	case VK_OEM_PERIOD:
	{
		return Keys::keyboard_stop;
	}
	break;
	case VK_OEM_2:
	{
		return Keys::keyboard_forwardslash;
	}
	break;
	case VK_CONTROL:
	{
		return Keys::keyboard_control;
	}
	break;
	case VK_MENU:
	{
		return Keys::keyboard_alt;
	}
	break;
	case VK_SPACE:
	{
		return Keys::keyboard_space;
	}
	break;
	case VK_UP:
	{
		return Keys::keyboard_up;
	}
	break;
	case VK_DOWN:
	{
		return Keys::keyboard_down;
	}
	break;
	case VK_LEFT:
	{
		return Keys::keyboard_left;
	}
	break;
	case VK_RIGHT:
	{
		return Keys::keyboard_right;
	}
	break;
	case VK_NUMLOCK:
	{
		return Keys::numpad_numlock;
	}
	break;
	case VK_DIVIDE:
	{
		return Keys::numpad_divide;
	}
	break;
	case VK_MULTIPLY:
	{
		return Keys::numpad_multiply;
	}
	break;
	case VK_SUBTRACT:
	{
		return Keys::numpad_subtract;
	}
	break;
	case VK_NUMPAD7:
	{
		return Keys::numpad_7;
	}
	break;
	case VK_NUMPAD8:
	{
		return Keys::numpad_8;
	}
	break;
	case VK_NUMPAD9:
	{
		return Keys::numpad_9;
	}
	break;
	case VK_ADD:
	{
		return Keys::numpad_add;
	}
	break;
	case VK_NUMPAD4:
	{
		return Keys::numpad_4;
	}
	break;
	case VK_NUMPAD5:
	{
		return Keys::numpad_5;
	}
	break;
	case VK_NUMPAD6:
	{
		return Keys::numpad_6;
	}
	break;
	case VK_NUMPAD1:
	{
		return Keys::numpad_1;
	}
	break;
	case VK_NUMPAD2:
	{
		return Keys::numpad_2;
	}
	break;
	case VK_NUMPAD3:
	{
		return Keys::numpad_3;
	}
	break;
	case VK_NUMPAD0:
	{
		return Keys::numpad_0;
	}
	break;
	case VK_DECIMAL:
	{
		return Keys::numpad_stop;
	}
	break;
	}

	return Keys();
}
