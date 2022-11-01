project(scnet)


add_executable(client tcp_client.cpp tcp_process.cpp)

add_executable(server tcp_server.cpp tcp_process.cpp)