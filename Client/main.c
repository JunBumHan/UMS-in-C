#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 256

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

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1)
        err_handling("SOCKET() ERROR");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        err_handling("CONNECT() ERROR");
    
    // write(sock, "hello", sizeof("hello"));
    read(sock, recv_msg, sizeof(recv_msg)-1);
    printf("%s", recv_msg);

    scanf("%s", transmit_msg);
    write(sock, transmit_msg, sizeof(transmit_msg));

    



}
