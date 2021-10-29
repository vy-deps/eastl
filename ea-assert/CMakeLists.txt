#-------------------------------------------------------------------------------------------
# Copyright (C) Electronic Arts Inc.  All rights reserved.
#-------------------------------------------------------------------------------------------
project(EAAssert CXX)

file(GLOB EAASSERT_SOURCES "source/*.cpp")
add_library(EAAssert ${EAASSERT_SOURCES})

ea_set_cxx_project_properties()
target_compile_definitions(EAAssert PRIVATE -D_CHAR16T)
target_include_directories(EAAssert PUBLIC include)
target_link_libraries(EAAssert PRIVATE EABase)
