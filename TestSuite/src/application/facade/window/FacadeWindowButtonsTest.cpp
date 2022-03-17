#include "FacadeWindowButtonsTest.h"

FacadeWindowButtonsTest::FacadeWindowButtonsTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, successes{ 0 }
{
}

FacadeWindowButtonsTest::~FacadeWindowButtonsTest()
{
}

std::string FacadeWindowButtonsTest::test()
{
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade window buttons test"
	);

	for (int i{ 0 }; i < (int)WindowsPlatform::WindowsButtons::keyboard_ESC; i++)
	{
		switch ((WindowsPlatform::WindowsButtons)i)
		{
		case WindowsPlatform::WindowsButtons::mouse_LMB:
		{
			PostMessage(
				unit->getWindow(),
				WM_LBUTTONDOWN,
				0,
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_LBUTTONUP,
				0,
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == false;
		}
		break;
		case WindowsPlatform::WindowsButtons::mouse_RMB:
		{
			PostMessage(
				unit->getWindow(),
				WM_RBUTTONDOWN,
				0,
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_RBUTTONUP,
				0,
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == false;
		}
		break;
		case WindowsPlatform::WindowsButtons::mouse_MMB:
		{
			PostMessage(
				unit->getWindow(),
				WM_MBUTTONDOWN,
				0,
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_MBUTTONUP,
				0,
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == false;
		}
		break;
		case WindowsPlatform::WindowsButtons::mouse_MB4:
		{
			PostMessage(
				unit->getWindow(),
				WM_XBUTTONDOWN,
				MAKEWPARAM(0, XBUTTON1),
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_XBUTTONUP,
				MAKEWPARAM(0, XBUTTON1),
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == false;
		}
		break;
		case WindowsPlatform::WindowsButtons::mouse_MB5:
		{
			PostMessage(
				unit->getWindow(),
				WM_XBUTTONDOWN,
				MAKEWPARAM(0, XBUTTON2),
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_XBUTTONUP,
				MAKEWPARAM(0, XBUTTON2),
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == false;
		}
		break;
		case WindowsPlatform::WindowsButtons::mouse_scrollForwards:
		{
			PostMessage(
				unit->getWindow(),
				WM_MOUSEWHEEL,
				MAKEWPARAM(0, WHEEL_DELTA * 1),
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == true;

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == false;
		}
		break;
		case WindowsPlatform::WindowsButtons::mouse_scrollBackwards:
		{
			PostMessage(
				unit->getWindow(),
				WM_MOUSEWHEEL,
				MAKEWPARAM(0, WHEEL_DELTA * -1),
				0
			);

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == true;

			unit->update();
			successes += unit->getButton((WindowsPlatform::WindowsButtons)i) == false;
		}
		break;
		}
	}

	delete unit;
	unit = nullptr;

	if ((successes / 2) == (int)WindowsPlatform::WindowsButtons::keyboard_ESC)
	{
		return std::string();
	}

	return "facade window buttons test failed\n";
}
