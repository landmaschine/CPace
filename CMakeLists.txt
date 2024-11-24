cmake_minimum_required(VERSION 3.16)
project(CPace)

# Set C standard
set(CMAKE_C_STANDARD 17)

# Define the source folders
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(ENGINE_DIR "${CMAKE_SOURCE_DIR}/engine")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.c" "${ENGINE_DIR}/*.c")
file(GLOB_RECURSE HEADER_FILES "${SRC_DIR}/*.h" "${ENGINE_DIR}/*.h")

include_directories(${INCLUDE_DIR} ${ENGINE_DIR} ${LIB_DIR})

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})

add_subdirectory(${LIB_DIR}/glfw)

add_subdirectory(${LIB_DIR}/glad)

target_link_libraries(${PROJECT_NAME} glfw glad)
target_include_directories(${PROJECT_NAME} PUBLIC ${LIB_DIR}/glfw/include)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR}/Debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR}/Release
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
