#include "WindowDestoryedTest.h"

WindowDestroyedTest::WindowDestroyedTest(HINSTANCE hInstanceValue, int nCmdShowValue)
	: hInstance{ hInstanceValue }, nCmdShow{ nCmdShowValue }, windowClass()
{
	initialiseWindowClass();
}

WindowDestroyedTest::~WindowDestroyedTest()
{
}

BOOL CALLBACK destroyedEnumProcedure(HWND window, LPARAM)
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
	windowsPlatform::ApplicationWindow* unit = new windowsPlatform::ApplicationWindow(
		nCmdShow
	);

	unit->initialise(windowClass);

	delete unit;
	unit = nullptr;

	if (EnumWindows(destroyedEnumProcedure, 0))
	{
		return std::string();
	}

	return "window destoryed test failed\n";
}

HRESULT WindowDestroyedTest::initialiseWindowClass()
{
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = L"window destroyed test";

	if (RegisterClassEx(&windowClass))
	{
		return S_OK;
	}

	return E_FAIL;
}

LRESULT WindowDestroyedTest::windowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(window, message, wParam, lParam);
}
