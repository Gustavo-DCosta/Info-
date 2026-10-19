cmake_minimum_required(VERSION 3.16)

project(Machine_a_caffe LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The console library (C code)
add_library(console STATIC
        console/console.c
        console/console.h
)
target_include_directories(console PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/console)

# Your executable
add_executable(Machine_a_caffe main.cpp)
target_link_libraries(Machine_a_caffe PRIVATE console)

include(GNUInstallDirs)
install(TARGETS Machine_a_caffe
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)