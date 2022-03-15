#include "WindowDestroyedTest.h"

WindowDestroyedTest::WindowDestroyedTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }
{
}

WindowDestroyedTest::~WindowDestroyedTest()
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

std::string WindowDestroyedTest::test()
{
	WindowsPlatform::ApplicationWindow* unit = new WindowsPlatform::ApplicationWindow(
		hInstance,
		nCmdShow,
		"window destroyed test"
	);

	delete unit;
	unit = nullptr;

	if (EnumWindows(destroyedTestEnumProcedure, 0))
	{
		return std::string();
	}

	return "window destroyed test failed\n";
}
