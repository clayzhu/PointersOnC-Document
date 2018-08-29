//
//  ch2_2.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/8/11.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ch;
    int bracePair = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '{') {
            bracePair ++;
        }
        
        if (ch == '}') {
            if (bracePair == 0) {
                printf("多余的右花括号\n");
                return EXIT_FAILURE;
            } else {
                bracePair --;
            }
        }
    }
    if (bracePair == 0) {
        printf("花括号都正确地成对出现\n");
    } else {
        printf("%d个花括号未正确地成对出现\n", bracePair);
    }
    return EXIT_SUCCESS;
}
#endif
