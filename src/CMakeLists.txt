cmake_minimum_required(VERSION 3.28)
project(curlex)

set(EXE_NAME "curlex")
set(
    SOURCE_FILES
    main.cpp
)

find_package(GTest REQUIRED)
if(GTest_FOUND)
    message(STATUS "GTest found.")
else()
    message(FATAL_ERROR "GTest not found")
endif()
include_directories(${GTEST_INCLUDE_DIRS})

find_package(CURL REQUIRED)
if(CURL_FOUND)
    message(STATUS "CURL found.")
else()
    message(FATAL_ERROR "CURL not found")
endif()

add_executable(
    ${EXE_NAME}
    ${SOURCE_FILES}
)
target_include_directories(${EXE_NAME} PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(${EXE_NAME} PRIVATE ${CURL_LIBRARIES})
target_link_libraries(${EXE_NAME} PRIVATE ${GTEST_BOTH_LIBRARIES})