//
//  ch5_2.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/11/19.
//  Copyright © 2018 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>

int encryption(int ch, int base) {
    ch += 13;
    if (ch > base + 26) {   // 超出字母表，从头取
        ch -= 26;
    }
    return ch;
}

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        if ('A' <= ch && ch <= 'Z') {
            putchar(encryption(ch, 'A'));
        } else if ('a' <= ch && ch <= 'z') {
            putchar(encryption(ch, 'a'));
        } else {
            putchar(ch);
        }
    }
    return EXIT_SUCCESS;
}
#endif
