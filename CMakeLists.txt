cmake_minimum_required(VERSION 3.21.0)
project(ea)

macro(ea_set_cxx_project_properties)
  set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)
  target_compile_definitions(${PROJECT_NAME} PUBLIC
    $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang,GNU>>:_DEBUG>
    $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANG_AND_ID:C,AppleClang,Clang,GNU>>:_DEBUG>)
endmacro()

add_subdirectory(ea-base)
add_subdirectory(ea-assert)
add_subdirectory(ea-thread)
add_subdirectory(ea-stl)
add_subdirectory(ea-stdc)
