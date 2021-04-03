cmake_minimum_required(VERSION 3.17)

project(probabilistic_filters CXX)
include(cmake/StandardProjectSettings.cmake)

set(CMAKE_CXX_STANDARD 17)
# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
  if(ENABLE_BUILD_WITH_TIME_TRACE)
    target_compile_options(project_options INTERFACE -ftime-trace)
  endif()
endif()

# define input directory
file(GLOB SENSOR_DATA "data/*.csv" )
set(PATH_TO_SENSOR_DATA "${SENSOR_DATA}")
configure_file("run_filter.h.in" "run_filter.h")

add_library(sensor_data_reader sensor_data_reader.cpp)

add_executable(run_filter run_filter.cpp)

target_link_libraries(run_filter sensor_data_reader)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

option(ENABLE_TESTING "Enable Test Builds" OFF)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()

#add_subdirectory(src)