project(linux_net)

cmake_minimum_required(3.0.0)

add_executable(client1 client1.cpp proce1.cpp)

add_executable(service1 service.cpp proce1.cpp)