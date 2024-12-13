
# 设置程序基本信息
cmake_minimum_required(VERSION 2.6 FATAL_ERROR) # 设置 cmake 的最低版本需求
#set(CMAKE_C_COMPILER "/usr/local/bin/gcc")    # 调用自己安装的gcc
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++")   # 调用自己安装的g++
set(PROJ_NAME geant4)                  # 设置编译后的程序名称
project(${PROJ_NAME} C CXX Fortran)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated -Wno-unused-parameter") # 支持最新c++11，并忽略 deprecated 和 unused-parameter 类型的警告

SET(CMAKE_BUILD_TYPE Debug) # 编译 debug 版本

# 定位 Geant4 包的位置；若设置启用图形界面，则同时定位图形界面包
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)  # 设置为 ON 以启用图形界面
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

# 加入 Geant4 的头文件
include(${Geant4_USE_FILE})

# 加入 ROOT 的头文件
find_package(ROOT REQUIRED)
if(ROOT_FOUND)
  # message("ROOT find...")
  include(${ROOT_DIR}/ROOTUseFile.cmake)
  message(${ROOT_INCLUDE_DIRS})
  message(${ROOT_LIBRARIES})
endif()

# 指定本程序的头文件和源文件
include_directories(${PROJECT_SOURCE_DIR}/include ${Geant4_INCLUDE_DIR} ${ROOT_INCLUDE_DIRS})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)
# file(GLOB libs)

# 加入 main.cc 文件，并将本程序文件和 Geant4 文件链接
add_executable(${PROJ_NAME} main.cc ${sources} ${headers})
target_link_libraries(${PROJ_NAME} ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})

# 将程序运行所需脚本拷贝至 ./build 目录
set(SCRIPTS
   scripts/init.mac
   scripts/init_vis.mac
   scripts/vis.mac
   scripts/geant4.in
   scripts/geant4.out
  )
foreach(_script ${SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
     COPYONLY
    )
endforeach()
