//
//  ch5_5.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/11/21.
//  Copyright © 2018 Netease. All rights reserved.
//

#if 1
#include <stdio.h>
#include <stdlib.h>

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit) {
    int length_to_store = starting_bit - ending_bit + 1; // 要存储的位数
    unsigned mask = 0;
    // 步骤 1
    // 先移出掩码中的1，后面多个0
    for (int i = 0; i < length_to_store; i ++) {
        mask |= 1;
        mask <<= 1;
    }
    // 移出掩码后面剩余的0（上面已经移出1个0，这里少移1个）
    for (int i = 0; i < ending_bit - 1; i ++) {
        mask |= 0;
        mask <<= 1;
    }
    // 步骤2
    original_value &= ~mask;
    // 步骤3
    value_to_store <<= ending_bit;
    // 步骤4
    value_to_store &= mask;
    // 步骤5
    unsigned result = value_to_store | original_value;
    return result;
}

int main(void) {
    int store_bit = store_bit_field(0xffff, 0x123, 13, 9);
    printf("%x\n", store_bit);
    return EXIT_SUCCESS;
}
#endif
