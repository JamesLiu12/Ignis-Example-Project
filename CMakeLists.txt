cmake_minimum_required(VERSION 3.20)
project(IgnisExampleProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(IGNISEXAMPLEPROJECT_AS_SCRIPT_MODULE "Build IgnisExampleProject as runtime-loaded script module (DLL/.so)" ON)
add_subdirectory(Ignis)

if(NOT TARGET Ignis::Ignis AND TARGET Ignis)
    add_library(Ignis::Ignis ALIAS Ignis)
endif()

file(GLOB_RECURSE IGNISEXAMPLEPROJECT_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/assets/scripts/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/assets/scripts/*.cpp
)

if(IGNISEXAMPLEPROJECT_AS_SCRIPT_MODULE)
    add_library(IgnisExampleProject SHARED ${IGNISEXAMPLEPROJECT_SOURCES})
    target_compile_definitions(IgnisExampleProject PRIVATE IGNISEXAMPLEPROJECT_DLL_EXPORT=1)
else()
    add_library(IgnisExampleProject STATIC ${IGNISEXAMPLEPROJECT_SOURCES})
endif()

set_target_properties(IgnisExampleProject PROPERTIES
    DEBUG_POSTFIX ""
    RELWITHDEBINFO_POSTFIX ""
    MINSIZEREL_POSTFIX ""
)

target_link_libraries(IgnisExampleProject PRIVATE Ignis::Ignis)

target_include_directories(IgnisExampleProject PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/scripts
)

if(MSVC)
    target_compile_options(IgnisExampleProject PRIVATE /utf-8)
endif()

if(IGNISEXAMPLEPROJECT_AS_SCRIPT_MODULE)
    set(_IGNISEXAMPLEPROJECT_PLATFORM "$<IF:$<PLATFORM_ID:Windows>,Windows,$<IF:$<PLATFORM_ID:Darwin>,macOS,Linux>>")
    set(_IGNISEXAMPLEPROJECT_OUTDIR "${CMAKE_SOURCE_DIR}/bin/${_IGNISEXAMPLEPROJECT_PLATFORM}/$<CONFIG>")

    set_target_properties(IgnisExampleProject PROPERTIES
        OUTPUT_NAME "IgnisExampleProject"

        RUNTIME_OUTPUT_DIRECTORY "${_IGNISEXAMPLEPROJECT_OUTDIR}"   # Windows .dll
        LIBRARY_OUTPUT_DIRECTORY "${_IGNISEXAMPLEPROJECT_OUTDIR}"   # macOS .dylib / Linux .so
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${_IGNISEXAMPLEPROJECT_PLATFORM}/$<CONFIG>/lib"
    )

    if(WIN32)
        set_target_properties(IgnisExampleProject PROPERTIES PREFIX "")
    endif()
endif()