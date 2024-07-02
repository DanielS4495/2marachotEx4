cmake_minimum_required(VERSION 3.10)

# Set path to Qt installation
set(Qt6_DIR /home/daniel/Desktop/QT/Tools/QtDesignStudio/qt6_design_studio_reduced_version/lib/cmake/Qt6)

# Set the project name
project(TreeVisualization)

# Set the CMAKE_PREFIX_PATH to help CMake find the Qt installation
set(CMAKE_PREFIX_PATH "/home/daniel/Desktop/QT/Tools/QtDesignStudio/qt6_design_studio_reduced_version")

# Find the Qt package
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Include the directories for Qt headers
include_directories(${Qt6Widgets_INCLUDE_DIRS})

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    Demo.cpp
    Tree.hpp
    TreeNode.hpp
    Iterator.hpp
    TreeDrawingClass.hpp    
)

# Add the executable
add_executable(TreeVisualization ${SOURCES})

# Link the Qt libraries
target_link_libraries(TreeVisualization Qt6::Widgets)
