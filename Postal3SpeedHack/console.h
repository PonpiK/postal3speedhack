#pragma once
#include <Windows.h>
#include <string>

namespace console {
	void spawn(std::string_view window);
	void printf(std::string_view input);
	void kill();

	inline bool open = false;
	inline std::string window_name;
}