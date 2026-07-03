# S.5 选项为打开的将对应子目录项目加入到项目中
if(${SIMPLE_CONTROL})
    add_subdirectory(control)
endif()

if(${SIMPLE_USELESS})
    add_subdirectory(useless)
endif()