cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(PCDToPLYExample)

find_package(PCL REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcd_to_ply pcd_to_ply.cpp)
target_link_libraries(pcd_to_ply ${PCL_LIBRARIES})

