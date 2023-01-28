#include <stdio.h>
#include "./../../head/define.h"
#include "./../../head/untils.h"


void print_error(int SCN) {
    switch(SCN) {
        case SCN_ERROR_INFO_SOCKET :
            printf("./exe [PORT]\n");
            break;
        case SCN_ERROR_SOCKET :
            printf("SOCKET ERROR\n");
            break;
        case SCN_ERROR_BIND :
            printf("BIND ERROR\n");
            break;
        case SCN_ERROR_LISTEN :
            printf("LISTEN ERROR\n");
            break;
        case SCN_ERROR_ACCEPT : 
            printf("BIND ERROR\n");

        default :
            printf("Unknown Argument value.\nArgument : %d\n", SCN);
    }
}