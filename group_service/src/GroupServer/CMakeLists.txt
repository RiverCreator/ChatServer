project(GroupServer)
get_filename_component(PARENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
aux_source_directory(. SRC_LIST)
aux_source_directory(${PARENT_FOLDER}/proto PROTO_LIST)

add_executable(GroupServer ${SRC_LIST} ${PROTO_LIST})

target_link_libraries(GroupServer Pool mysqlclient myrpc mytcp protobuf mylog zookeeper_mt mytool pthread)