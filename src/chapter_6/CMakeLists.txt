#Chapter_6
cmake_minimum_required(VERSION 2.6)
set(HRADFILE ${HEADER_PATH}/chapter6.h)
set(SRCFILE main.cpp chapter6.cpp)
add_executable(Chapter_6 ${HRADFILE} ${SRCFILE})

if(WIN32)
    target_link_libraries(Chapter_6 ${LIBRARY_OUTPUT_PATH}/Debug/OpenGLBase.lib)#包含输出库文件
    target_link_libraries(Chapter_6 ${LIBRARY_OUTPUT_PATH}/Release/OpenGLBase.lib)#包含输出库文件

elseif(UNIX)
    target_link_libraries( Chapter_6 libOpenGLBase.a ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

endif(WIN32)


