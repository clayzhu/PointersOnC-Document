//
//  ch1_2.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/7/23.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ch; // 输入的字符
    int line = 1;   // 行号
    int at_beginning = 1;   // 表示输入的是第1个字符
    while ((ch = getchar()) != EOF) {
        // 在输入第1个字符，先打印行号
        if (at_beginning == 1) {
            printf("%d", line);
            line += 1;
            at_beginning = 0;
        }
        
        putchar(ch);
        
        if (ch == '\n') {
            at_beginning = 1;
        }
    }
    
    return EXIT_SUCCESS;
}
#endif
