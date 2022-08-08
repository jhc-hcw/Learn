#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<iostream>
using namespace std;

const int PORT_SERVER = 8888;
const int BUFF_LEN= 256;
void static udpserver_echo(int s,sockaddr * client){
    int n;
    char buff[BUFF_LEN];
    socklen_t len;
    while(1){
        len = sizeof(*client);
        n= recvfrom(s,buff,BUFF_LEN,0,client,&len);
        cout<<"client :"<<buff<<endl;
        sendto(s,buff,n,0,client,len);
    }
}

int main(int argc,char *argv[]){
    int s;
    sockaddr_in addr_server={0},addr_client;
    s = socket(AF_INET,SOCK_DGRAM,0);
    addr_server.sin_family=AF_INET;
    addr_server.sin_addr.s_addr=htonl(INADDR_ANY);
    addr_server.sin_port = htons(PORT_SERVER);

    bind(s,(sockaddr *)&addr_server,sizeof(addr_server));

    udpserver_echo(s,(sockaddr *)&addr_client);

    return 0;

}
