cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
message("generator is set to ${CMAKE_GENERATOR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


set(SOURCE_EXE src/Main.cpp src/Snake.cpp src/Draw.cpp src/Engine.cpp src/Input.cpp src/Update.cpp)
set(SOURCE_LIB src/Snake.h src/Engine.h)

add_library(Engine ${SOURCE_LIB})
set_target_properties(Engine PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main ${SOURCE_EXE})
target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()

install(TARGETS main)
