cmake_minimum_required(VERSION 3.5)
project( GenAscii )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( GenAscii src/main.cpp )
set_target_properties(GenAscii PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output")
target_link_libraries( GenAscii ${OpenCV_LIBS} )
