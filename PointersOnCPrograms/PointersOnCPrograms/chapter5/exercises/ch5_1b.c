//
//  ch5_1b.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/11/19.
//  Copyright © 2018 Netease. All rights reserved.
//

#if 0
// 习题 ch5_1 另一种解法
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        if ('A' <= ch && ch <= 'Z') {
            ch += 'a' - 'A';
        }
        putchar(ch);
    }
    return EXIT_SUCCESS;
}
#endif
