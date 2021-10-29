#-------------------------------------------------------------------------------------------
# Copyright (C) Electronic Arts Inc.  All rights reserved.
#-------------------------------------------------------------------------------------------
project(EAStdC CXX)

file(GLOB EASTDC_SOURCES "source/*.cpp")
add_library(EAStdC ${EASTDC_SOURCES})

ea_set_cxx_project_properties()
target_compile_definitions(EAStdC PRIVATE
  -D_CRT_SECURE_NO_WARNINGS
  -D_SCL_SECURE_NO_WARNINGS
  -D_CHAR16T)
target_include_directories(EAStdC PUBLIC include)
target_link_libraries(EAStdC PUBLIC EABase EAAssert EAThread)
