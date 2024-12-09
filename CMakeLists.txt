cmake_minimum_required(VERSION 3.16)
project(CPace)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(ENGINE_DIR "${CMAKE_SOURCE_DIR}/engine")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp" "${ENGINE_DIR}/*.cpp")

add_subdirectory(${LIB_DIR}/glfw)
add_subdirectory(${LIB_DIR}/glad)
add_subdirectory(${LIB_DIR}/glm)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR} ${ENGINE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${LIB_DIR}/glfw/include ${LIB_DIR}/glm/glm ${LIB_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad glm)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR}/Debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR}/Release
)
