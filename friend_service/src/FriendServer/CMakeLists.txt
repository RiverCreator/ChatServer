project(FriendServer)
get_filename_component(PARENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
aux_source_directory(. SRC_LIST)
aux_source_directory(${PARENT_FOLDER}/proto PROTO_LIST)

add_executable(FriendServer ${SRC_LIST} ${PROTO_LIST})

target_link_libraries(FriendServer hiredis Pool mysqlclient myrpc mytcp protobuf mylog zookeeper_mt mytool pthread)