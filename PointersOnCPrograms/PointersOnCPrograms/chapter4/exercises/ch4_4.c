//
//  ch4_4.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/8/17.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 1000

void copy_n(char dst[], char src[], int n);

int main(void) {
    char dst[MAX_COUNT];
    char src[] = "Hello World!";
    int n = 40;
    copy_n(dst, src, n);
    printf("%s\n", dst);
    return EXIT_SUCCESS;
}

void copy_n(char dst[], char src[], int n) {
    if (n == 0) {
        return;
    }
    
    int dst_index, src_index;
    src_index = 0;
    for (dst_index = 0; dst_index < n; dst_index ++) {
        dst[dst_index] = src[src_index];
        if (src[src_index] != 0) {
            src_index ++;
        }
    }
}
#endif
