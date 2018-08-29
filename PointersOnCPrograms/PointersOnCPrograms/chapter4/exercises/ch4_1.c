//
//  ch4_1.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/8/16.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float num;
    printf("请输入数字：");
    scanf("%f", &num);
    
    // 不允许输入0或负数
    if (num <= 0) {
        printf("请输入正数\n");
        return EXIT_FAILURE;
    }
    
    float sqrt_last, sqrt_new = 1.0;
    do {
        sqrt_last = sqrt_new;
        sqrt_new = (sqrt_last + num / sqrt_last) / 2;
        printf("中间近似值：%.15e\n", sqrt_new);
    } while (sqrt_last != sqrt_new);
    printf("平方根：%g\n", sqrt_new);
    return EXIT_SUCCESS;
}
#endif
