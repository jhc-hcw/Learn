all:client server

obj_c=tcp_client.cpp 
obj_s=tcp_server.cpp 
obj_p=tcp_process.cpp
client:client.o process.o
	g++ -o client client.o process.o
server:server.o process.o
	g++ -o server server.o process.o
client.o:$(obj_c)
	g++ -c $(obj_c) -o client.o
server.o:$(obj_s) 
	g++ -c $(obj_s) -o server.o
process.o:$(obj_p)
	g++ -c $(obj_p)  -o process.o

clean:
	rm -f *.o

