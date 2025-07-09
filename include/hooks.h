#pragma once
#include "memory.h"
#include "signatures.h"
#include "safetyhook.hpp"
#include "Zydis.h"

namespace cl_move
{
	void __cdecl function(float accumulated_extra_samples, bool final_tick);

	void init();
	void uninit();
}