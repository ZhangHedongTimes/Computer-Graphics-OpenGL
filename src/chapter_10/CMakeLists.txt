#Chapter_10
cmake_minimum_required(VERSION 2.6)
set(HRADFILE ${HEADER_PATH}/chapter10.h)
set(SRCFILE main.cpp chapter10.cpp)
add_executable(Chapter_10 ${HRADFILE} ${SRCFILE})

#target_link_libraries(Chapter_10 ${LIBRARY_OUTPUT_PATH}/Debug/OpenGLBase.lib)#包含输出库文件
target_link_libraries(Chapter_10 ${LIBRARY_OUTPUT_PATH}/Release/OpenGLBase.lib)#包含输出库文件




