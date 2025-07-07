#include "signatures.h"

void signatures::init() {
	cl_move = memory::find_signature<DWORD>("engine.dll", "83 EC ? 83 3D ? ? ? ? ? 0F 8C ? ? ? ? E8");
}