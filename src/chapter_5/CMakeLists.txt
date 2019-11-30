#Chapter_5
cmake_minimum_required(VERSION 2.6)

set(HEADFILE ${HEADER_PATH}/OpenGLBase.h)
set(SRCFILE OpenGLBase.cpp)

add_library(OpenGLBase STATIC  ${HEADFILE}  ${SRCFILE})#构建静态库


set(SRCFILE main.cpp)
add_executable(Chapter_5 ${SRCFILE})

if(UNIX)
    target_link_libraries( Chapter_5 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
endif(UNIX)


