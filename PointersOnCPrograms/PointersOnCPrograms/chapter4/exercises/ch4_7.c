//
//  ch4_7.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/9/3.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deblank(char string[]);

int main(void) {
    char string[] = "  a    fg";
    deblank(string);
    printf("%s\n", string);
    return EXIT_SUCCESS;
}

void deblank(char string[]) {
    char temp[128]; // 临时字符串，存储过滤后所需的字符
    int temp_index = 0;
    for (int i = 0; string[i] != '\0'; i ++) {  // 遍历源字符串
        if (string[i] == ' ' && i > 0 && string[i - 1] == ' ') {    // 源字符串 i 位为空格，且 i 位前一位也为空格，则跳过
            continue;
        }
        temp[temp_index] = string[i];
        temp_index ++;
    }
    strcpy(string, temp);   // 使用临时字符串的值覆盖源字符串
}
#endif
