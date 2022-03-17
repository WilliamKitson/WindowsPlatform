#include "FacadeWindowDragTest.h"

FacadeWindowDragTest::FacadeWindowDragTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, tagPrefix{ "facade window drag test, ESC TO CONTINUE" }
{
}

FacadeWindowDragTest::~FacadeWindowDragTest()
{
}

std::string FacadeWindowDragTest::test()
{
	WindowsPlatform::SubordinateFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		tagPrefix
	);

	while (unit->getButton(WindowsPlatform::WindowsButtons::keyboard_ESC) == false)
	{
		Sleep(1);
		unit->update();

		std::string tag = tagPrefix + "(x:" + std::to_string(unit->getDrag().x) + "/y:" + std::to_string(unit->getDrag().y) + ")";
		unit->setTag(tag);
	}

	delete unit;
	unit = nullptr;

	return std::string();
}
