# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(scPDSI)

# Set the C++ standard
# set(CMAKE_CXX_STANDARD 14)

include_directories(Include)

# Add executable target with source files
add_executable(${PROJECT_NAME} 
  src/basic.cpp
  src/llist.cpp
  src/scPDSI.cpp
  src/main.cpp  
)
