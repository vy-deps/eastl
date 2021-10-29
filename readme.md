# EA library set

## Usage

```cmake
FetchContent_Declare(deps-eastl
  GIT_REPOSITORY git@github.com:vy-deps/eastl.git
  GIT_TAG master)
FetchContent_MakeAvailable(deps-eastl)
```

```cmake
target_link_libraries(${PROJECT_NAME} PUBLIC EASTL)
```
