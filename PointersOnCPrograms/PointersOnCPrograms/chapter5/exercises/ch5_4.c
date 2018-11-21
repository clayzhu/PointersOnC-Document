//
//  ch5_4.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/11/20.
//  Copyright © 2018 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 **      Compute the character that will contain the desired bit
 */
unsigned
character_offset( unsigned bit_number )
{
    return bit_number / CHAR_BIT;
}

/*
 **      Compute the bit number within the desired character
 */
unsigned
bit_offset( unsigned bit_number )
{
    return bit_number % CHAR_BIT;
}

/*
 **      Set a specific bit
 */
void
set_bit( char bit_array[], unsigned bit_number )
{
    bit_array[ character_offset( bit_number ) ] |=
    1 << bit_offset( bit_number );
}

/*
 **      Clear a specific bit
 */
void
clear_bit( char bit_array[], unsigned bit_number )
{
    bit_array[ character_offset( bit_number ) ] &=
    ~ ( 1 << bit_offset( bit_number ) );
}

/*
 **      Assign a value to a bit
 */
void
assign_bit( char bit_array[], unsigned bit_number, int value )
{
    if( value != 0 )
        set_bit( bit_array, bit_number );
    else
        clear_bit( bit_array, bit_number );
}

/*
 **      Test a specific bit
 */
int
test_bit( char bit_array[], unsigned bit_number )
{
    return (
            bit_array[ character_offset( bit_number ) ]
            & 1 << bit_offset( bit_number )
            ) != 0;
}

int main(void) {
    char bit_array[] = "100000";
    set_bit(bit_array, 3);
    printf("%s\n", bit_array);
    return EXIT_SUCCESS;
}
#endif
