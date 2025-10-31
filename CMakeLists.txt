cmake_minimum_required(VERSION 3.28)
set (CMAKE_CXX_STANDARD 23)
project(dml_test)


#add_compile_options(-Wall -Wextra -Wpedantic -Wconversion)
#add_compile_options(-march=native )

Include(FetchContent)

FetchContent_Declare(
  DML
  GIT_REPOSITORY https://github.com/intel/DML
  GIT_TAG        v1.2.0
)

FetchContent_MakeAvailable(DML)

add_subdirectory(src)