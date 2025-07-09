#include <Windows.h>
#include "signatures.h"
#include "console.h"
#include "hooks.h"
DWORD WINAPI main_thread(LPVOID arguments)
{
	signatures::init(); // get the sig(s).
	console::spawn("Postal 3 Speedhack | Made by vannie74 on UC");
	cl_move::init();
	console::printf("Attached!");
	while (!GetAsyncKeyState(VK_END))
		std::this_thread::sleep_for(std::chrono::milliseconds(350));
	console::printf("Deattaching!");
	cl_move::uninit();
	console::kill(); // goodbye!!
	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(arguments), EXIT_SUCCESS);
}

BOOL APIENTRY DllMain(HMODULE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
		if (const HANDLE hMain = CreateThread(0, 0, main_thread, hInstance, 0, 0))
			CloseHandle(hMain);

	return true;
}