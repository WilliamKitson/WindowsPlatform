#include "FacadeEventMouseTest.h"

FacadeEventMouseTest::FacadeEventMouseTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, successes{ 0 }
{
}

FacadeEventMouseTest::~FacadeEventMouseTest()
{
}

std::string FacadeEventMouseTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade event mouse test"
	);

	for (int i{ 0 }; i < (int)WindowsPlatform::MouseButtons::size; i++)
	{
		switch ((WindowsPlatform::MouseButtons)i)
		{
		case WindowsPlatform::MouseButtons::mouse_LMB:
		{
			PostMessage(
				unit->getWindow(),
				WM_LBUTTONDOWN,
				0,
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_LBUTTONUP,
				0,
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == false;
		}
		break;
		case WindowsPlatform::MouseButtons::mouse_RMB:
		{
			PostMessage(
				unit->getWindow(),
				WM_RBUTTONDOWN,
				0,
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_RBUTTONUP,
				0,
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == false;
		}
		break;
		case WindowsPlatform::MouseButtons::mouse_MMB:
		{
			PostMessage(
				unit->getWindow(),
				WM_MBUTTONDOWN,
				0,
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_MBUTTONUP,
				0,
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == false;
		}
		break;
		case WindowsPlatform::MouseButtons::mouse_MB4:
		{
			PostMessage(
				unit->getWindow(),
				WM_XBUTTONDOWN,
				MAKEWPARAM(0, XBUTTON1),
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_XBUTTONUP,
				MAKEWPARAM(0, XBUTTON1),
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == false;
		}
		break;
		case WindowsPlatform::MouseButtons::mouse_MB5:
		{
			PostMessage(
				unit->getWindow(),
				WM_XBUTTONDOWN,
				MAKEWPARAM(0, XBUTTON2),
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == true;

			PostMessage(
				unit->getWindow(),
				WM_XBUTTONUP,
				MAKEWPARAM(0, XBUTTON2),
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == false;
		}
		break;
		case WindowsPlatform::MouseButtons::mouse_scrollForwards:
		{
			PostMessage(
				unit->getWindow(),
				WM_MOUSEWHEEL,
				MAKEWPARAM(0, WHEEL_DELTA * 1),
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == true;

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == false;
		}
		break;
		case WindowsPlatform::MouseButtons::mouse_scrollBackwards:
		{
			PostMessage(
				unit->getWindow(),
				WM_MOUSEWHEEL,
				MAKEWPARAM(0, WHEEL_DELTA * -1),
				0
			);

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == true;

			unit->update();
			successes += unit->getMouse((WindowsPlatform::MouseButtons)i) == false;
		}
		break;
		}
	}

	delete unit;
	unit = nullptr;

	if ((successes / 2) == (int)WindowsPlatform::MouseButtons::size)
	{
		return std::string();
	}

	return "facade event mouse test failed\n";
}
