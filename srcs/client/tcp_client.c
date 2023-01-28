// #include <stdio.h>
#include <stdlib.h> // atoi
#include <string.h> // memset
#include <unistd.h> // sockaddr_in, read, write
#include <arpa/inet.h> // htonl, htons, INADDR_ANY, sockaddr_in
#include <sys/socket.h>

#include "./../../head/define.h"
#include "./../../head/untils.h"

/*
    소켓 정보와 서버 주소를 가져와 소켓을 생성하고, 서버 소켓에 연결합니다. 
    연결된 소켓의 디스크립트를 반환합니다.
*/
int connect_tcp_server(char *sock_info[], struct sockaddr_in *serv_addr) {
    int conn_serv_sock;
    
    conn_serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(conn_serv_sock == ERROR)
        sniffied(SCN_ERROR_SOCKET);
        

    memset(serv_addr, 0, sizeof((*serv_addr)));
    serv_addr->sin_family = AF_INET;
    serv_addr->sin_addr.s_addr = inet_addr(sock_info[1]);
    serv_addr->sin_port = htons(atoi(sock_info[2]));

    if(connect(conn_serv_sock, (struct sockaddr*)serv_addr, sizeof((*serv_addr))) == ERROR)
        sniffied(SCN_ERROR_CONNECT);
    
    return conn_serv_sock;
}