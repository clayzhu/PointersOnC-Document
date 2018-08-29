//
//  ch1_4.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/7/26.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 1001  // 缓存设置为1001个字符，需要包括输入行的末尾 NUL

int main(void) {
    char input[MAX_INPUT];
    int inputLen;
    char longest[MAX_INPUT];
    int longestLen;
    
    longestLen = -1;
    
    while (gets(input) != NULL) {
        inputLen = strlen(input);
        if (longestLen < inputLen) {
            strcpy(longest, input);
            longestLen = inputLen;
        }
    }
    
    if (longestLen >= 0) {
        puts(longest);
    }
    
    return EXIT_SUCCESS;
}
#endif
