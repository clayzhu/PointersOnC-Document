//
//  ch4_6.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/8/29.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>

int substr(char dst[], char src[], int start, int len);

int main(void) {
    char dst[3];
    char src[] = "abcdefg";
    int substr_len = substr(dst, src, 1, 3);
    printf("substr:%s, len:%d\n", dst, substr_len);
    return EXIT_SUCCESS;
}

int substr(char dst[], char src[], int start, int len) {
        if (start < 0 || len < 0 || src[start] == '\0') {
            dst = "";
            return 0;
        }
    
        int dst_index = 0, src_index = start;
        while (dst_index < len) {
            if (src[src_index] != '\0') {   // 子串还未到 len 长度，但已取完 src 的数据
                dst[dst_index] = src[src_index];
                dst_index ++;
                src_index ++;
            } else {
                dst[dst_index] = '\0';  // 补充子串最后一个 NUL 字符
                break;
            }
        }
        return dst_index;
}
#endif
