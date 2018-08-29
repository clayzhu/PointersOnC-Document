//
//  ch4_5.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/8/28.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 127

int main(void) {
    char input_line[LINE_SIZE], previous_line[LINE_SIZE];
    int if_previous_line_printed = 0;   // 0-前一行没打印过，1-前一行已打印过
    if (gets(previous_line) != NULL) {
        while (gets(input_line) != NULL) {
            if (strcmp(previous_line, input_line) == 0) {   // 前一行和刚输入的这一行一样
                if (if_previous_line_printed == 0) {    // 前一行没打印过
                    printf("%s\n", input_line);
                    if_previous_line_printed = 1;   // 前一行设置为已打印，连续相同的行不打印
                }
            } else {
                strcpy(previous_line, input_line);
                if_previous_line_printed = 0;
            }
        }
    }
    return EXIT_SUCCESS;
}
#endif
