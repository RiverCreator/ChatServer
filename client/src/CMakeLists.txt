project(Client)
get_filename_component(PARENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

aux_source_directory(. SRC_LIST)
aux_source_directory(./proto PROTO_LIST)

add_executable(Client ${SRC_LIST} ${PROTO_LIST})

target_link_libraries(Client protobuf mytool)