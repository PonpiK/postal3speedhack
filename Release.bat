@echo off
cd /d "%~dp0"

if exist build rd /s /q build
mkdir build && cd build

cmake .. -A Win32
cmake --build . --config Release --clean-first
pause