cmake_minimum_required(VERSION 3.5)

project(ShortURL)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(src SRC_DIR)

add_subdirectory(libs/drogon)
add_subdirectory(src/funcs)
add_subdirectory(src/controller)

file(COPY etc/config.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY static/index.html DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SRC_DIR})
target_link_libraries(${PROJECT_NAME} drogon funcs controller)

