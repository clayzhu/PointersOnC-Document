//
//  ch4_2.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/8/16.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        int primeNum = 1;   // 值为1表示质数
        for (int j = 2; j < i; j ++) {  // 除去1和 i 本身
            if (i % j == 0) {   // 余数为0则整除，表示非质数
                primeNum = 0;
                break;
            }
        }
        if (primeNum) {
            printf("%d\n", i);
        }
    }
    return EXIT_SUCCESS;
}
#endif
