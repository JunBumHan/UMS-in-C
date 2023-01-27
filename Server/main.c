#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

void err_handling(char * arg) {
    printf("%s\n", arg);
    exit(1);  
}

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;

    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;

    if(argc != 2) {
        printf("Usage : %s <port>", argv[0]);
        exit(1);
    }
    printf("Start server");

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1) 
        err_handling("SOCKET() ERROR");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) 
        err_handling("BIND() ERROR");
        
    if(listen(serv_sock, 5) == -1) 
        err_handling("LISTEN() ERROR");

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if(clnt_sock == -1)
        err_handling("ACCEPT() ERROR");

    printf("Welcome client[%s]", inet_ntoa(clnt_addr.sin_addr));
    char msg[15];
    
    while(1){
        read(clnt_sock, msg, sizeof(msg)-1);
    printf("%s : %s", inet_ntoa(clnt_addr.sin_addr), msg);
    }


}