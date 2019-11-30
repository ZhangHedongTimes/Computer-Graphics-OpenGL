cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME CGWithOpenGL)
project(${PROJECT_NAME})

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)

if(WIN32)
    # set path 'exe'
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/exe)#输出exe文件放置的位置

    # set path 'lib'
    set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)#输出静态库文件放置的位置
    # set variable 'HEADER_PATH'
    set(HEADER_PATH ${PROJECT_SOURCE_DIR}/include)#设置头文件
    set(LIB_PATH ${PROJECT_SOURCE_DIR}/lib)#设置库文件（外部库）

    include_directories(${HEADER_PATH})#包含头文件

    link_directories(${LIB_PATH})#包含外部库文件

    link_directories(${LIBRARY_OUTPUT_PATH})#包含外部库文件

    #从库文件目录拷贝动态库到可执行文件目录
    file(COPY ${LIB_PATH}/glut.dll DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Debug )
    file(COPY ${LIB_PATH}/glut32.dll DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Debug )

    file(COPY ${LIB_PATH}/glut.dll DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Release )
    file(COPY ${LIB_PATH}/glut32.dll DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Release )

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")#命令行设置

elseif(UNIX)
    set(HEADER_PATH ${PROJECT_SOURCE_DIR}/include)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

    include_directories( ${HEADER_PATH} )

    link_directories(${LIBRARY_OUTPUT_PATH})

    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)

    # include_directories( ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} )
    # link_directories( ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

    # message(STATUS "------------------^_^---------------------")
    # message(STATUS "OpenGL INCLUDE path: " ${OPENGL_INCLUDE_DIR} )
    # message(STATUS "GLUT INCLUDE path: " ${GLUT_INCLUDE_DIR} )
    # message(STATUS "OpenGL LIBRARIES path: " ${OPENGL_LIBRARIES} )
    # message(STATUS "GLUT LIBRARY path: " ${GLUT_LIBRARY} )
    # message(STATUS "------------------^_^---------------------")

endif(WIN32)


set(USE_EIGEN        ON)

message(STATUS "------------------------------------")
message(STATUS "| USE_EIGEN       " ${USE_EIGEN})
message(STATUS "------------------------------------")


if (USE_EIGEN)
    find_package(Eigen3 REQUIRED)#自动查找库
    include_directories(${EIGEN3_INCLUDE_DIR})
    message(STATUS "found Eigen " ${EIGEN3_VERSION_STRING} " for project")
endif ()

add_subdirectory(src)#添加子目录