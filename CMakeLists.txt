cmake_minimum_required(VERSION 3.20)

project(LibraryV3 LANGUAGES CXX)

# ---------- C++ ----------
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------- Export compile_commands.json ----------
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---------- Warnings ----------
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

# ---------- Sources ----------
file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)

file(GLOB_RECURSE HEADERS
    CONFIGURE_DEPENDS
    include/*.h
)

# ---------- Windows Icon ----------
if(WIN32)
    set(APP_ICON
        "${CMAKE_CURRENT_SOURCE_DIR}/assets/LibraryV3.rc"
    )
endif()

# ---------- Executable ----------
add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${APP_ICON}
)

# ---------- Include Directories ----------
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        include
)