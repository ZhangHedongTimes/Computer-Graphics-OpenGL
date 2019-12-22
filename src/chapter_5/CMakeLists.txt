#Chapter_5
cmake_minimum_required(VERSION 2.6)

set(HEADFILE ${HEADER_PATH}/OpenGLBase.h)
set(SRCFILE OpenGLBase.cpp)

add_library(OpenGLBase STATIC  ${HEADFILE}  ${SRCFILE})#Éú³É¿â


set(SRCFILE main.cpp)
add_executable(Chapter_05 ${SRCFILE})




