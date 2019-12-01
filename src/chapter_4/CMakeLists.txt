#Chapter_4
cmake_minimum_required(VERSION 2.6)

set(HEADFILE ${HEADER_PATH}/chapter4.h)

set(SRCFILE main.cpp)
add_executable(Chapter_4 ${HEADFILE} ${SRCFILE})

if(UNIX)
    target_link_libraries( Chapter_4 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
endif(UNIX)