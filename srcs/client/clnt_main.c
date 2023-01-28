#include <stdio.h>
// #include <stdlib.h> // atoi
// #include <string.h> // memset
#include <unistd.h> // sockaddr_in, read, write
#include <arpa/inet.h> // htonl, htons, INADDR_ANY, sockaddr_in
// #include <sys/socket.h>

#include "./../../head/define.h"
#include "./../../head/untils.h"


int main(int argc, char *argv[]) {
    if(argc != 3) 
        sniffied(SCN_ERROR_INFO_CLIENT_SOCKET);
    
    struct sockaddr_in serv_addr;
    char SWICH[BUF_SIZE];

    connect_tcp_server(argv, &serv_addr);
    
    func_swich(SWICH_MAIN_MENU);
    while(TRUE) {
        scanf(" %[^\n]s", SWICH);
        func_swich(SWICH);
    }
}