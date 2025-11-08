cmake_minimum_required(VERSION 3.14)

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()

if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

project(FiguresRotation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(figures_app
    main.cpp
    Polygon.cpp
    Array.cpp
)

target_include_directories(figures_app PRIVATE .)

if(MSVC)
    target_compile_options(figures_app PRIVATE /W4)
else()
    target_compile_options(figures_app PRIVATE -Wall -Wextra -pedantic)
endif()