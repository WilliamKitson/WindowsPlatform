#include "FacadeDefaultDragTest.h"

FacadeDefaultDragTest::FacadeDefaultDragTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeDefaultDragTest::~FacadeDefaultDragTest()
{
}

std::string FacadeDefaultDragTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance, 
		nCmdShow, 
		"facade default drag test"
	);

	WindowsPlatform::Vector2 drag = unit->getDrag();

	delete unit;
	unit = nullptr;

	if (drag == WindowsPlatform::Vector2())
	{
		return std::string();
	}

	return "facade default drag test failed\n";
}
