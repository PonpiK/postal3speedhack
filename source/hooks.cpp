#include "hooks.h"

SafetyHookInline move{};

using namespace cl_move;

void __cdecl cl_move::function(float accumulated_extra_samples, bool final_tick)
{
	move.ccall<void>(accumulated_extra_samples, final_tick); // CCALL = __cdecl call.

	if (GetAsyncKeyState(VK_CONTROL))
	{
		for (int i = 0; i < 5; i++)
		{ // 5 speedhack value
			move.ccall<void>(accumulated_extra_samples, final_tick);
		}
	}
}

void cl_move::init()
{
	move = safetyhook::create_inline(signatures::cl_move, function);
}

void cl_move::uninit()
{
	move = {};
}