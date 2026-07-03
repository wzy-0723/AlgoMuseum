# 获取当前 CMakeLists.txt 所在的路径
get_filename_component(current_dir ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${current_dir})

# 搜索源码并编译
file(GLOB_RECURSE project_headers *.h)
file(GLOB_RECURSE project_cpps *.cpp)
set(all_sourcefile ${project_headers} ${project_cpps})
add_executable(${PROJECT_NAME} ${all_sourcefile})

# 设置VS下所属文件夹
set_target_properties_by_demand(${PROJECT_NAME} ${folder_name})