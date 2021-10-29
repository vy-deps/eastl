#-------------------------------------------------------------------------------------------
# Copyright (C) Electronic Arts Inc.  All rights reserved.
#-------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.1)
project(EAThread CXX)

file(GLOB EATHREAD_SOURCES "source/*.cpp")
add_library(EAThread ${EATHREAD_SOURCES})
ea_set_cxx_project_properties()

target_compile_definitions(EAThread PRIVATE -D_CHAR16T -D_CRT_SECURE_NO_WARNINGS)
target_include_directories(EAThread PUBLIC include)
target_link_libraries(EAThread PRIVATE EABase)
