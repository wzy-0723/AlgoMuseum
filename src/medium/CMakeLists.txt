# S.5 选项为打开的将对应子目录项目加入到项目中
if(${MEDIUM_CONTROL})
    add_subdirectory(control)
endif()

if(${MEDIUM_USELESS})
    add_subdirectory(useless)
endif()