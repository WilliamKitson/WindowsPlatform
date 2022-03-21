#include "FacadeDestroyedTest.h"

FacadeDestroyedTest::FacadeDestroyedTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

FacadeDestroyedTest::~FacadeDestroyedTest()
{
}

BOOL CALLBACK destroyedTestEnumProcedure(HWND window, LPARAM)
{
	if (!window)
	{
		return FALSE;
	}

	int size = GetWindowTextLength(window);
	size++;

	std::vector<wchar_t> buffer(size);

	GetWindowText(
		window,
		&buffer[0],
		size
	);

	std::wstring title = &buffer[0];

	if (title == L"window destroyed test")
	{
		return FALSE;
	}

	return TRUE;
}

std::string FacadeDestroyedTest::test()
{
	WindowsPlatform::SubordianteFacade* unit = new WindowsPlatform::SubordinateImplimentation(
		hInstance,
		nCmdShow,
		"facade destroyed test"
	);

	delete unit;
	unit = nullptr;

	if (EnumWindows(destroyedTestEnumProcedure, 0))
	{
		return std::string();
	}

	return "facade destroyed test failed\n";
}
