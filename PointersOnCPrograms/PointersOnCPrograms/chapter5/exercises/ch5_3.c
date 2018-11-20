//
//  ch5_3.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/11/20.
//  Copyright © 2018 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bits( unsigned int value ) {
    unsigned int result = 0;
    
    for (unsigned int i = 1; i != 0; i <<= 1) {
        result <<= 1;
        if (value & 1) {
            result |= 1;
        }
        value >>= 1;
    }
    
    return result;
}

int main(void) {
    unsigned int value;
    scanf("%ud", &value);
    printf("%ud\n", reverse_bits(value));
    return EXIT_SUCCESS;
}
#endif
