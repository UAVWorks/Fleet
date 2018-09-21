# CMake version string
cmake_minimum_required(VERSION 3.2.1)
cmake_policy(VERSION 3.4.1)

# Project
project(Fleet)

# Versions
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)

# Get git revision hash
execute_process(
    COMMAND git rev-parse HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_REVISION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get version from git
add_definitions(-DVERSION_MAJOR=${VERSION_MAJOR})
add_definitions(-DVERSION_MINOR=${VERSION_MINOR})
add_definitions(-DVERSION_PATCH=${VERSION_PATCH})
add_definitions(-DGIT_REVISION="${GIT_REVISION}")

# Version message
message(STATUS
    "Configuring ${PROJECT_NAME} ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}(${GIT_REVISION})"
)

# Minimum Qt version
set(QT_REQUIRED_VERSION 5.9.0)

# Set default output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/result)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/result)

# Instruct CMake to run moc and rcc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add compiler flags
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -fPIC)

# Targets
add_subdirectory(core)
#add_subdirectory(plugins)
#add_subdirectory(app)

# Tests
option(WITH_TESTS "Enable tests")
if(WITH_TESTS)
    enable_testing()
endif(WITH_TESTS)
