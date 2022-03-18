#include "MouseDefaultDragTest.h"

MouseDefaultDragTest::MouseDefaultDragTest()
{
}

MouseDefaultDragTest::~MouseDefaultDragTest()
{
}

std::string MouseDefaultDragTest::test()
{
	if (WindowsPlatform::Mouse().getDrag() == WindowsPlatform::Vector2())
	{
		return std::string();
	}

	return "mouse default drag test failed\n";
}
