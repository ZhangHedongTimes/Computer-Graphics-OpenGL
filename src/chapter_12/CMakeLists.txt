#Chapter_12
cmake_minimum_required(VERSION 2.6)
set(HRADFILE ${HEADER_PATH}/chapter12.h)
set(SRCFILE main.cpp chapter12.cpp)
add_executable(Chapter_12 ${HRADFILE} ${SRCFILE})

#target_link_libraries(Chapter_12 ${LIBRARY_OUTPUT_PATH}/Debug/OpenGLBase.lib)#包含输出库文件
target_link_libraries(Chapter_12 ${LIBRARY_OUTPUT_PATH}/Release/OpenGLBase.lib)#包含输出库文件




