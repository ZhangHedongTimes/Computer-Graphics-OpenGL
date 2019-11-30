#Chapter_3
cmake_minimum_required(VERSION 3.6)

set(SRCFILE main.cpp)
#option()

add_executable(Chapter_3 ${SRCFILE})

if(UNIX)
    target_link_libraries( Chapter_3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
endif(UNIX)