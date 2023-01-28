#include <stdio.h>
#include <stdlib.h>

#include "./../../head/define.h"
#include "./../../head/untils.h"

static int is_error(int SCN);
static int is_bug(int SCN);
static int is_exception(int SCN);
static void termination();

void sniffied(int SCN) {

    // 에러 인가?   
    if(is_error(SCN) == TRUE) 
        print_error(SCN);
    
    // 버그 인가?
    // 예외 인가?
    termination();
} 

static int is_error(int SCN) {
    if(0 <= SCN && SCN <= 255)
        return TRUE;
    return FALSE;
}

static int is_bug(int SCN) {
    if(256 <= SCN && SCN <= 512)
        return TRUE;
    return FALSE;
}

static int is_exception(int SCN) {
    if(513 <= SCN && SCN <= 768)
        return TRUE;
    return FALSE;
}

static void termination() {
    /*동적 할당 해제*/
    printf("Exit the program\n");
    exit(1);
}