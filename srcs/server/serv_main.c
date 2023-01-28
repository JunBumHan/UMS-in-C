// #include <stdio.h>
// #include <stdlib.h> // atoi
// #include <string.h> // memset
#include <unistd.h> // sockaddr_in, read, write
#include <arpa/inet.h> // htonl, htons, INADDR_ANY, sockaddr_in
// #include <sys/socket.h>

#include "./../../head/define.h"
#include "./../../head/untils.h"

int is_server_info_socket;
int g_server_socket;

int main(int argc, char *argv[]) {
    if(argc != 2) 
        sniffied(SCN_ERROR_INFO_SERVER_SOCKET);

    struct sockaddr_in serv_addr, clnt_addr;
    is_server_info_socket = NONE_INFO_SOCKET;

    start_tcp_server(argv, &serv_addr, &clnt_addr, 5);
    
}


