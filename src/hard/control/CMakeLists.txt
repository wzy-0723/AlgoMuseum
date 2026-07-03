set(folder_name "hard_control")

# 获取当前 CMakeLists.txt 所在目录的路径
get_filename_component(CURRENT_DIR ${CMAKE_CURRENT_LIST_DIR} ABSOLUTE)

# 遍历当前目录下的所有子目录
file(GLOB SUBDIRS RELATIVE ${CURRENT_DIR} */)

# 为每个子目录添加子项目
foreach(SUBDIR ${SUBDIRS})
	# 忽略某些特定文件（CMakeLists.txt）
    if(NOT SUBDIR STREQUAL "CMakeLists.txt")
        add_subdirectory(${SUBDIR})
    endif()
endforeach()