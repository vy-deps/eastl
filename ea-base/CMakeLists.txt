#-------------------------------------------------------------------------------------------
# Copyright (C) Electronic Arts Inc.  All rights reserved.
#-------------------------------------------------------------------------------------------
project(EABase CXX)

add_library(EABase INTERFACE) 

# ea_set_cxx_project_properties()
target_compile_definitions(EABase INTERFACE -D_CHAR16T)
target_include_directories(EABase INTERFACE include/Common)
