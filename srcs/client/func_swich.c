#include <stdio.h>
#include <string.h>

#include "./../../head/define.h"
#include "./../../head/untils.h"

#include "swich.h"

static int same_str(char *str1, char *str2);

void func_swich(char *SWICH) {

    

    if(same_str(SWICH, SWICH_MAIN_MENU))  
        MAIN_MENU();                       
    

      
 
    

   


}

static int same_str(char *str1, char *str2) {
    if(strcmp(str1, str2) == 0) 
        return TRUE;
    return FALSE;
}