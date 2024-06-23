aux_source_directory(. SRC_LIST)
aux_source_directory(./proto PROTO_LIST)

add_executable(ChatServer ${SRC_LIST} ${PROTO_LIST})

target_link_libraries(ChatServer protobuf zookeeper_mt hiredis mytool mytcp myrpc pthread)