project(eastl-example)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE EASTL EAStdC EAAssert EAThread EABase)
