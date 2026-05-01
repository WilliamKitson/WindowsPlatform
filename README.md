# WindowsPlatform

WindowsPlatform is a small C++ Win32 platform layer for creating a native Windows window and reading common application input state. It wraps window creation, message processing, mouse input, keyboard input, raw mouse drag data, minimise/quit events, and frame delta timing behind a simple facade API.

The repository contains a Visual Studio solution with the platform library and a separate test application.

## Projects

- `WindowsPlatform` - static library containing the platform layer.
- `TestSuite` - Windows application that exercises the domain and application behaviour.

## Features

- Native Win32 window creation.
- Window title, resolution, borderless, and windowed mode controls.
- Per-frame update loop for Win32 messages.
- Quit and minimise event flags.
- Mouse cursor position, button state, extra mouse buttons, and scroll wheel events.
- Raw mouse movement for drag-style input.
- Keyboard state for common keyboard and numpad keys.
- Frame delta timing.

## Requirements

- Windows 10 SDK.
- Visual Studio 2022 C++ build tools, or another MSVC environment with platform toolset `v143`.
- MSBuild, if building from the command line.

This project uses Win32 headers and APIs, so it must be built on Windows or in a Windows-capable MSVC environment.

## Repository Layout

```text
.
|-- WindowsPlatform.sln
|-- WindowsPlatform/
|   |-- WindowsPlatform.vcxproj
|   `-- src/
|       |-- Facade.h
|       |-- Implimentation.h
|       |-- Window.h
|       |-- Mouse.h
|       |-- Keyboard.h
|       |-- Delta.h
|       |-- Resolution.h
|       `-- ...
`-- TestSuite/
    |-- TestSuite.vcxproj
    `-- src/
        |-- Entrypoint.cpp
        |-- MemoryTest.cpp
        |-- application/
        `-- domain/
```

## Building

Open `WindowsPlatform.sln` in Visual Studio and build the desired configuration:

- `Debug|x64`
- `Release|x64`
- `Debug|x86`
- `Release|x86`

From a Developer Command Prompt, the same build can be run with MSBuild:

```bat
msbuild WindowsPlatform.sln /p:Configuration=Debug /p:Platform=x64
```

Release x64 build:

```bat
msbuild WindowsPlatform.sln /p:Configuration=Release /p:Platform=x64
```

Build outputs are written under:

```text
bin/<ProjectName>/build/<Configuration>/<Platform>/
```

Intermediate files are written under:

```text
bin-int/<ProjectName>/build/<Configuration>/<Platform>/
```

After `WindowsPlatform` builds, its public headers are copied to:

```text
bin/WindowsPlatform/include/
```

## Running Tests

Build and run the `TestSuite` project from Visual Studio, or build it from a Developer Command Prompt:

```bat
msbuild TestSuite\TestSuite.vcxproj /p:Configuration=Debug /p:Platform=x64
```

Then run the generated `TestSuite.exe` from the matching output directory.

The test application displays message boxes containing any test failures. It also runs a CRT memory leak check in debug builds.

## Basic Usage

Include the platform headers and create the concrete facade implementation from a Win32 entry point:

```cpp
#include "Implimentation.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    windowsPlatform::Implimentation platform(hInstance, nCmdShow, "Example");

    while (!platform.getQuit())
    {
        platform.update();

        if (platform.getKeyboard(windowsPlatform::Keys::keyboard_ESC))
        {
            break;
        }

        float delta = platform.getDelta();
        windowsPlatform::Vector2 cursor = platform.getCursor();
    }

    return 0;
}
```

Useful API calls:

- `update()` - processes pending window messages and updates frame delta time.
- `getWindow()` - returns the native `HWND`.
- `getQuit()` - reports a close-window event for the current update.
- `getMinimise()` - reports a minimise event for the current update.
- `getCursor()` - returns the current cursor position.
- `getDrag()` - returns raw mouse movement from `WM_INPUT`.
- `getMouse(Buttons)` - reads a mouse button or wheel event state.
- `getKeyboard(Keys)` - reads a keyboard key state.
- `getDelta()` - returns elapsed time since the previous update.
- `setTag(std::string)` - changes the window title.
- `setResolution(Vector2)` - changes the window size.
- `setBorderless()` - switches to borderless style.
- `setWindowed()` - switches to windowed style.

## Notes

- The concrete implementation class is currently named `Implimentation` in the codebase.
- `Facade` provides the virtual interface, while `Implimentation` contains the Win32-backed behaviour.
- `TestSuite` references `WindowsPlatform` directly and includes headers from `WindowsPlatform/src`.
