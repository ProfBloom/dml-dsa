cmake_minimum_required(VERSION 3.28)
project(dml_test)


file(GLOB files "*.cpp")
foreach (source_file ${files})
    get_filename_component(example_name ${source_file} NAME_WE)
    set(example_name "hl_${example_name}")

    add_executable(${example_name} ${source_file})
    target_link_libraries(${example_name} PRIVATE dmlhl)

    if(WIN32)
        target_compile_options(${example_name} PRIVATE "$<$<CONFIG:Release>:-02>" /WX)
    else()
        target_compile_options(${example_name} PRIVATE "$<$<CONFIG:Release>:-03>" -Werror -Wall)
    endif()
    
endforeach()
