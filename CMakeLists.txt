cmake_minimum_required(VERSION 3.10)
project(p3speedhack LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/library/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/library/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/library/safetyhook/include"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    WIN32_LEAN_AND_MEAN
    _CRT_SECURE_NO_WARNINGS
    _CRT_NONSTDC_NO_DEPRECATE
)

target_compile_options(${PROJECT_NAME} PRIVATE
    /O2 /Ot /Oi /Gy /GL
    $<$<COMPILE_LANGUAGE:CXX>:/Zc:inline>
)

target_link_options(${PROJECT_NAME} PRIVATE
    /LTCG
)