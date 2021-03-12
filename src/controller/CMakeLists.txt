aux_source_directory(. CONTROLLER_SRC_DIR)

add_library(controller ${CONTROLLER_SRC_DIR})

target_include_directories(controller PRIVATE ../)

target_link_libraries(controller drogon funcs)
