cmake_minimum_required(VERSION 3.10)          # 4.1 is too new; use a stable version
project(Lab)

set(CMAKE_CXX_STANDARD 14)

# -------------------------------------------------------------------
# 1. Find SDL2 (must be installed, e.g. via Homebrew)
# -------------------------------------------------------------------
find_package(SDL2 REQUIRED)

# -------------------------------------------------------------------
# 2. Include directories
# -------------------------------------------------------------------
# SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})

# SDL_bgi headers (the library's own header and font files)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SDL_bgi/src)

# -------------------------------------------------------------------
# 3. List the source files needed for your program
# -------------------------------------------------------------------
set(SOURCES
        class_1/basic.cpp                # your main program
        SDL_bgi/src/SDL_bgi.c             # the SDL_bgi implementation
)

# (Optional) If SDL_bgi consists of more than one .c file, add them here.
# For example, if there is also a font helper: SDL_bgi/src/fonts.c

# -------------------------------------------------------------------
# 4. Create the executable
# -------------------------------------------------------------------
add_executable(Lab ${SOURCES})

# -------------------------------------------------------------------
# 5. Link with SDL2 libraries
# -------------------------------------------------------------------
target_link_libraries(Lab ${SDL2_LIBRARIES})

# On macOS you might also need to link with the following frameworks:
# target_link_libraries(Lab ${SDL2_LIBRARIES} "-framework Cocoa")
# (Usually not required when using the SDL2 CMake config.)