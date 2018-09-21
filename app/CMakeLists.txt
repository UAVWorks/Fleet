# CMake version string
cmake_minimum_required(VERSION 3.2.1)

# Project
project(Fleet)

# Version message
message(STATUS "Configuring ${PROJECT_NAME}")

# Enable Qt modules
find_package(Qt5 ${QT_REQUIRED_VERSION} CONFIG REQUIRED COMPONENTS
    Core
    Gui
    Svg
    Quick
    LinguistTools
    Positioning
    QuickControls2
)

# Enable Qt5 qml compiler
#find_package(Qt5QuickCompiler REQUIRED)

# Executable app target
add_executable(${PROJECT_NAME} "")

# Industrial vendor includes & sources
target_include_directories(${PROJECT_NAME} PRIVATE ${INDUSTRIAL_INCLUDES})
target_sources(${PROJECT_NAME} PRIVATE ${INDUSTRIAL_SOURCES})

# Internal app includes & sources
HEADER_DIRECTORIES(INTERNAL_INCLUDES "sources")
target_include_directories(${PROJECT_NAME} PRIVATE ${INTERNAL_INCLUDES})
file(GLOB_RECURSE SOURCES "includes/*.h" "sources/*.h" "sources/*.cpp" "sources/*.hpp")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# Resources
file(GLOB_RECURSE QRC_FILES "resources/*.qrc")

# Create translations QRC file
file(GLOB TS_FILES "translations/*.ts")
tr_to_qrc("${CMAKE_CURRENT_BINARY_DIR}/app_ts.qrc")

# Compile resources
target_sources(${PROJECT_NAME} PRIVATE ${QRC_FILES})

# QML compile resources
file(GLOB_RECURSE QRC_QML_FILES "sources/presentation/qml/*.qrc")
#qtquick_compiler_add_resources(QRC_QML_SOURCES ${QRC_QML_FILES})
target_sources(${PROJECT_NAME} PRIVATE ${QRC_QML_FILES})

# Add Qt libraries
set(QT_LIBRARIES
    Qt5::Core
    Qt5::Gui
    Qt5::Svg
    Qt5::Quick
    Qt5::Positioning
    Qt5::QuickControls2
)

# Link Libraries
target_link_libraries(${PROJECT_NAME} ${CORE} ${QT_LIBRARIES})

# Tests
if(WITH_TESTS)
#    add_subdirectory(tests)
endif(WITH_TESTS)
