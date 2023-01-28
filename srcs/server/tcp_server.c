#include <stdio.h>
#include <stdlib.h> // atoi
#include <string.h> // memset
#include <unistd.h> // sockaddr_in, read, write
#include <arpa/inet.h> // htonl, htons, INADDR_ANY, sockaddr_in
#include <sys/socket.h>

#include "./../../head/define.h"
#include "./../../head/untils.h"


extern int is_server_info_socket;
extern int g_server_socket;


static int set_tcp_server_socket(char *port[], struct sockaddr_in *serv_addr);
static int set_tcp_server_socket(char *port[], struct sockaddr_in *serv_addr);
static int connect_tcp_client(int serv_sock, struct sockaddr_in *serv_addr, struct sockaddr_in *clnt_addr, int listen_number);

/*
    이 함수는 tcp 서버를 실행 시킨 다음, 연결된 client의 파일디스크립트를 반환합니다.
    clnt_addr의 정보를 포인터를 이용해 변할 수 있게 했습니다.
*/
int start_tcp_server(char *port[], struct sockaddr_in *serv_addr, struct sockaddr_in *clnt_addr, int listen_number) {
    
    if(is_server_info_socket == NONE_INFO_SOCKET) {
        g_server_socket = set_tcp_server_socket(port, serv_addr);
        is_server_info_socket = SOME_INFO_SOCKET;
    }   
    
    return connect_tcp_client(g_server_socket, serv_addr, clnt_addr, listen_number);
    
}

/*
    이 함수는 tcp 서버의 소켓을 만든 다음, server 의 파일 디스크립트를 반환합니다.
*/
static int set_tcp_server_socket(char *port[], struct sockaddr_in *serv_addr) {
    int set_serv_sock;

    set_serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(set_serv_sock == ERROR) 
        sniffied(SCN_ERROR_SOCKET);
    
    memset(serv_addr, 0, sizeof((*serv_addr)));
    serv_addr->sin_family = AF_INET;
    serv_addr->sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr->sin_port = htons(atoi(port[1]));

    return set_serv_sock;
}
/*
    이 함수는 서버의 소켓을 이용하여, 클라이언트와 연결 시킨 후, 연결된 클라이언트의 파일 디스크릅트를 반혼합니다.
*/
static int connect_tcp_client(int serv_sock, struct sockaddr_in *serv_addr, struct sockaddr_in *clnt_addr, int listen_number) {
    int clnt_sock;
    int clnt_addr_size;

    if(bind(serv_sock, (struct sockaddr*)serv_addr, sizeof((*serv_addr))) == ERROR) 
        sniffied(SCN_ERROR_BIND);
        
    if(listen(serv_sock, listen_number) == ERROR) 
        sniffied(SCN_ERROR_LISTEN);

    clnt_addr_size = sizeof((*clnt_addr));

    clnt_sock = accept(serv_sock, (struct sockaddr*)clnt_addr, &clnt_addr_size);
    if(clnt_sock == ERROR)
        sniffied(SCN_ERROR_ACCEPT);

    return clnt_sock;
}