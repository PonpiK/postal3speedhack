#include "console.h"
#include <iostream>
// Shrimple..
// -vannie
void console::spawn(std::string_view window)
{
	if (!AllocConsole())
		return;

	FILE *f{};

	freopen_s(&f, "CONIN$", "r", stdin);
	freopen_s(&f, "CONOUT$", "w", stdout);
	freopen_s(&f, "CONOUT$", "w", stderr);

	SetConsoleTitleA(window.data());

	open = true;
	window_name = window;
}

void console::kill()
{
	if (!open)
		return;

	FreeConsole();
	HWND console = FindWindowA(nullptr, window_name.c_str());
	PostMessageA(console, WM_QUIT, 0, 0);
}

void console::printf(std::string_view input)
{
	if (input.empty())
		return;
	std::cout << input.data() << "\n";
}