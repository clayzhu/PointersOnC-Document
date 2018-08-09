//
//  ch1_3.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/7/24.
//  Copyright © 2018年 Netease. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#if 0
int main (void) {
    int ch;
    signed char checksum = -1;  // 要声明为 char，而不是 int
    while ((ch = getchar()) != EOF) {
        putchar(ch);
        checksum += ch;
    }
    printf("%d\n", checksum);
    return EXIT_SUCCESS;
}
#endif
