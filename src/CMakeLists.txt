include_directories(${CMAKE_CURRENT_SOURCE_DIR}/0XXX___solution_template)


# S.4 配置编译选择项
list(
    APPEND
    LC_SOLUTION_LIST
	SIMPLE_CONTROL 							# 简单；掌握
	SIMPLE_USELESS 							# 简单；忽略
	MEDIUM_CONTROL 							# 中等；掌握
	MEDIUM_USELESS  						# 中等；忽略
	HARD_CONTROL 							# 困难；掌握
	HARD_USELESS  							# 困难；忽略
)
#将所有编译选项都设为On打开
foreach(BUILD_ITEM ${LC_SOLUTION_LIST})
    option(${BUILD_ITEM} "${BUILD_ITEM}" ON)
	#message(STATUS "set ${BUILD_ITEM}：${${BUILD_ITEM}}")
endforeach()



add_subdirectory(0XXX___solution_template)
add_subdirectory(simple)
add_subdirectory(medium)
add_subdirectory(hard)



