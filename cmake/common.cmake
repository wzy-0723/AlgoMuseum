
macro(set_target_properties_by_demand proj_name file_name)
    set_target_properties(${proj_name} PROPERTIES FOLDER ${file_name})
endmacro()

set(folder_name "simple_control")

set(simple_control_file_name "simple_control")
set(simple_useless_file_name "simple_useless")

set(medium_control_file_name "medium_control")
set(medium_useless_file_name "medium_useless")

set(hard_control_file_name "hard_control")
set(hard_useless_file_name "hard_useless")