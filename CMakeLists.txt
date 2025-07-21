cmake_minimum_required(VERSION 3.10)

# ✅ Project metadata
project(DevBuddy VERSION 1.0)

# ✅ Set C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ✅ Include directories
include_directories(include)

# ✅ Add main executable
add_executable(devbuddy src/main.cpp)

# ✅ Add unit tests (optional to run)
enable_testing()
add_subdirectory(tests)
