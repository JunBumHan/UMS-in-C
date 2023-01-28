#ifndef DEFINE_H
# define DEFINE_H

#define TRUE 1
#define FALSE 0


// Server
#define NONE_INFO_SOCKET -404
#define SOME_INFO_SOCKET  404

// SCN[Sniffer code number defines]
#define ERROR                   -1
// [ERROR] (0 ~ 255)
#define SCN_ERROR_INFO_SOCKET   0   // 소켓에 대한 정보가 이상 
#define SCN_ERROR_SOCKET        1   // 소켓 생성시 이상
#define SCN_ERROR_BIND          2   // 소켓 바인드시 이상
#define SCN_ERROR_LISTEN        3   // 소켓 listen시 이상
#define SCN_ERROR_ACCEPT        4   // 소켓 Accept시 이상

// [BUG] (256 ~ 512)

// [EXCEPTION] (513 ~ 768)

#endif