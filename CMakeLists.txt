
cmake_minimum_required(VERSION 3.24) # set cmake version
set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE) # close DEPRECATION WARNING...
include(${CMAKE_SOURCE_DIR}/utils.cmake) # custom print_message() function.

set(NAME Cui)
set(CMAKE_CXX_STANDARD 20) # Cpp compiler version
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SRC
        CuiApp/main.cpp
        CuiApp/Assert.h
        CuiApp/Noncopyable.h
        CuiApp/App.cpp
        CuiApp/App.h
)

# configure cmake project
# ----------------------------------------------------------------------------
project(${NAME}) # set project name
add_executable(${NAME} ${SRC})

# OpenGL
# ----------------------------------------------------------------------------
# 시스템에서 패키지를 찾고, 그 위치와 바이너리 이름들을 변수로 자동 저장해준다.
find_package(OpenGL REQUIRED) # stops processing with an error message if the package cannot be found.
set(OpenGL_GL_PREFERENCE LEGACY)
print_message(STATUS "OpenGL included at ${OPENGL_INCLUDE_DIR}") # path set by "find_package"

# GLM math library
# ----------------------------------------------------------------------------
# https://github.com/g-truc/glm/blob/master/manual.md#-15-finding-glm-with-cmake
set(glm_DIR ${CMAKE_SOURCE_DIR}/dependency/glm/cmake/glm) # if necessary
find_package(glm CONFIG REQUIRED)
target_link_libraries(${NAME} PRIVATE glm::glm)
print_message(STATUS "GLM included at ${GLM_INCLUDE_DIRS}") # path set by "find_package"

# set include path for glad, glfw
# ----------------------------------------------------------------------------
include_directories(SYSTEM # to use '#include <...>'
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/dependency/glad/build/include
        ${CMAKE_SOURCE_DIR}/dependency/glfw/include
        ${CMAKE_SOURCE_DIR}/dependency/glm/glm
        ${CMAKE_SOURCE_DIR}/dependency/stb_image
)

# link libraries (archive files)
# ----------------------------------------------------------------------------
target_link_libraries(${NAME} PUBLIC
        OpenGL::GL
        ${CMAKE_SOURCE_DIR}/dependency/glad/build/libglad.a
        ${CMAKE_SOURCE_DIR}/dependency/glfw/build/src/libglfw3.a
)

# Link: https://coderefinery.github.io/cmake-workshop/environment/
if (CMAKE_SYSTEM_NAME STREQUAL "Linux") # Linux
    target_link_libraries(${NAME}
            PRIVATE
            -lX11
    )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin") # MacOS
    target_link_libraries(${NAME}
            PRIVATE
            "-framework Cocoa"
            "-framework IOKit"
    )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows") # Windows
else ()
endif ()

# Add custom rule (ex make fclean, re)
# ----------------------------------------------------------------------------
ADD_CUSTOM_TARGET(re
        COMMENT "Re-building..."
        COMMAND make fclean && make all
        # ...
)

ADD_CUSTOM_TARGET(fclean
        COMMENT "Cleaning executable and binaries..."
        COMMAND make clean # cmake이 생성하는 clean은 fclean과 동일.
)
