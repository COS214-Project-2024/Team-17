cmake_minimum_required(VERSION 3.10)
project(WorksOnMyMachineTeam)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the source files, excluding the Tests/ folder
file(GLOB_RECURSE ALL_SOURCES "src/*.cpp")

# Filter out main.cpp files that are not in the root directory
set(SOURCES "")
foreach(SOURCE ${ALL_SOURCES})
    if(NOT SOURCE MATCHES ".*/main.cpp$")
        list(APPEND SOURCES ${SOURCE})
    endif()
endforeach()

# Add the DemoMain.cpp file from the root directory if it exists
if(EXISTS "${CMAKE_SOURCE_DIR}/DemoMain.cpp")
    list(APPEND SOURCES "${CMAKE_SOURCE_DIR}/DemoMain.cpp")
else()
    message(FATAL_ERROR "DemoMain.cpp not found in the root directory")
endif()

# Ensure SOURCES is not empty
if(NOT SOURCES)
    message(FATAL_ERROR "No source files found")
endif()

# Define the header files
file(GLOB_RECURSE HEADERS "src/*.h")

# Add the executable
add_executable(Main ${SOURCES})

# Find and link pthread
find_package(Threads REQUIRED)
target_link_libraries(Main ${CMAKE_THREAD_LIBS_INIT})

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link Google Test libraries
target_link_libraries(Main ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

# Enable testing
enable_testing()

# Add a test executable
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
if(TEST_SOURCES)
    add_executable(MyTest ${TEST_SOURCES})
    target_link_libraries(MyTest ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
    add_test(NAME MyTest COMMAND MyTest)
else()
    message(WARNING "No test source files found in the tests directory")
endif()