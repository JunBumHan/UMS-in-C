#ifndef UNTILS_H
# define UNTILS_H

// #include <stdio.h>
#include <stdlib.h> // atoi
#include <string.h> // memset
#include <unistd.h> // sockaddr_in, read, write
#include <arpa/inet.h> // htonl, htons, INADDR_ANY, sockaddr_in
#include <sys/socket.h>
// <UMS-By-C/srcs/server>

    // tcp_server.c
    int start_tcp_server(char *port[], struct sockaddr_in *serv_addr, struct sockaddr_in *clnt_addr, int listen_number);


// [sniffer_code]

// <sniffer_code.c>
void sniffied(int SCN);

// <error.c>
void print_error(int SCN);

#endif
