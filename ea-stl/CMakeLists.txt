#-------------------------------------------------------------------------------------------
# Copyright (C) Electronic Arts Inc.  All rights reserved.
#-------------------------------------------------------------------------------------------
project(EASTL CXX)

file(GLOB EASTL_SOURCES "source/*.cpp")
add_library(EASTL ${EASTL_SOURCES})

ea_set_cxx_project_properties()
target_compile_definitions(EASTL PRIVATE
  -D_CHAR16T
  -D_CRT_SECURE_NO_WARNINGS
  -D_SCL_SECURE_NO_WARNINGS
  -DEASTL_OPENSOURCE=1)
target_include_directories(EASTL PUBLIC include)
target_link_libraries(EASTL PUBLIC EABase)
