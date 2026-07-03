set(folder_name "simple_useless")
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

# add_subdirectory(S_N_872X___trees_with_similar_leaves)
# add_subdirectory(S_N_1137___tebonacci_sequence)
# add_subdirectory(S_N_1768___alternate_merge_string)
# add_subdirectory(S_N_1431___most_candy)
# add_subdirectory(S_N_605X___planting_flowers)
# add_subdirectory(S_N_345X___reverse_vowel_of_string)
# add_subdirectory(S_N_392X___determine_subsequence)
# add_subdirectory(S_N_643X___maximum_average)
# add_subdirectory(S_N_1732___highest_altitude)
# add_subdirectory(S_N_742X___center_index)

