#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 256

int connect_tcp_server(char *sock_info[], struct sockaddr_in *serv_addr) {

    int conn_serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    printf("conn_serv_sock : %d\n", conn_serv_sock);
    if(conn_serv_sock == -1)
        printf("a");

    memset(serv_addr, 0, sizeof((*serv_addr)));
    serv_addr->sin_family = AF_INET;
    serv_addr->sin_addr.s_addr = inet_addr(sock_info[1]);
    serv_addr->sin_port = htons(atoi(sock_info[2]));

    connect(conn_serv_sock, (struct sockaddr*)serv_addr, sizeof((*serv_addr)));
    return conn_serv_sock;


}

void err_handling(char * arg) {
    printf("%s\n", arg);
    exit(1);  
}

int main(int argc, char *argv[]) {

    int sock;
    struct sockaddr_in serv_addr;
    char recv_msg[BUF_SIZE];
    char transmit_msg[BUF_SIZE];

    if(argc != 3) {
        printf("Usage : %s <SERVER IP> <PORT>\n", argv[0]);
        exit(1);
    }

    
    write(connect_tcp_server(argv, &serv_addr), "helllo", sizeof("hello"));
}
