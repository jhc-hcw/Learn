project(linux_net)


add_executable(client1 client1.cpp proce1.cpp)

add_executable(service1 service.cpp proce1.cpp)

add_executable(client2 client1.cpp proce2.cpp)

add_executable(service2 service.cpp proce2.cpp)

add_executable(client3 client1.cpp proce3.cpp)

add_executable(service3 service.cpp proce3.cpp)

add_executable(client4 proce4.cpp client2.cpp)