//
//  ch4_3.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/8/16.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float a, b, c;
    printf("请输入三角形三条边的长度，以空格分：");
    scanf("%f %f %f", &a, &b, &c);
    
    // 对边长排序，使得 a 最长，c 最短
    float temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a < c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (b < c) {
        temp = b;
        b = c;
        c = temp;
    }
    
    if (c <= 0 || b + c <= a) { // 负数、两短边之和小于长边
        printf("输入的边长非法\n");
        return EXIT_FAILURE;
    }
    if (a == b && b == c) {
        printf("等边三角形\n");
    } else if (a == b || b == c) {
        printf("等腰三角形\n");
    } else {
        printf("不等边三角形\n");
    }
    return EXIT_SUCCESS;
}
#endif
