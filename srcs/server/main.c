#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define SOCKET_INFO_ERROR 0
#define SOCKET_ERROR -1
#define BIND_ERROR -2
#define LISTEN_ERROR -3
#define ACCEPT_ERROR -4
#define ERROR -1

#define BUF_SIZE 256

int start_tcp_server(char *port[], struct sockaddr_in *clnt_addr);
void err_handling(int error);

int main(int argc, char *argv[]) {
    int clnt_sock;
    struct sockaddr_in clnt_addr;
    
    char recv_msg[BUF_SIZE];
    char transmit_msg[BUF_SIZE];
            
    if(argc != 2) 
        err_handling(SOCKET_INFO_ERROR);
    

    clnt_sock = start_tcp_server(argv, &clnt_addr); 
    if(clnt_sock <= ERROR) 
        err_handling(clnt_sock);
    

    printf("Welcome client[%s]\n", inet_ntoa(clnt_addr.sin_addr));

    char main_menu[BUF_SIZE] = {"Welcome!, UMS\n> Join  (1)\n> Login (2)\n> quit (3)\n"};
    read(clnt_sock, recv_msg, sizeof(recv_msg) - 1);
    printf("%s", recv_msg);
    


}

/*
    이 함수는 tcp 서버를 실행 시킨 다음, client의 파일디스크립트를 반환합니다.
    clnt_addr의 정보를 포인터를 이용해 변할 수 있게 했습니다.
*/
int start_tcp_server(char *port[], struct sockaddr_in *clnt_addr) {
    int serv_sock, clnt_sock;

    struct sockaddr_in serv_addr;
    socklen_t clnt_addr_size;

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == ERROR) 
        return SOCKET_ERROR;

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(port[1]));

    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == ERROR) 
        return BIND_ERROR;
        
    if(listen(serv_sock, 5) == ERROR) 
        return LISTEN_ERROR;

    clnt_addr_size = sizeof((*clnt_addr));
    clnt_sock = accept(serv_sock, (struct sockaddr*)clnt_addr, &clnt_addr_size);
    if(clnt_sock == ERROR)
        return BIND_ERROR;

    return clnt_sock;

}

void err_handling(int error) {
    switch(error) {
        case SOCKET_INFO_ERROR :
            printf("Usage : ./* <port>\n");
            break;
        case SOCKET_ERROR :
            printf("SOCKET() ERROR\n");
            break;
        case BIND_ERROR :
            printf("BIND() ERROR\n");
            break;
        case LISTEN_ERROR :
            printf("LISTEN() ERROR\n");
            break;
        case ACCEPT_ERROR :
            printf("ACCEPT() ERROR\n");
            break;
        default :
            printf("??? ERROR\n");
    }
    exit(1);
}