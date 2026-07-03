# message(STATUS "pro:datalistener")
# message(STATUS "author：Why")
# message(STATUS "CMAKE_CURRENT_SOURCE_DIR：${CMAKE_CURRENT_SOURCE_DIR}")
# message(STATUS "CMAKE_BINARY_DIR：${CMAKE_BINARY_DIR}")
# 工程基础配置
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(leetcode_training)
set(CMAKE_CXX_STANDARD 17)		# C++17标准
set(CMAKE_CXX_EXTENSIONS OFF)	# 关闭编译器特有扩展

# 设置支持VS工程文件夹
if(MSVC)
    message(STATUS "set MSVC use folders")
	# 使项目中的源文件按 CMake 中定义的目录结构在 IDE 中分组显示
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
	# 开启多处理器编译
	add_compile_options(/MP)
endif()

include(cmake/common.cmake)
add_subdirectory(src)