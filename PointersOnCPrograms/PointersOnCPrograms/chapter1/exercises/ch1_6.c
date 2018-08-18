//
//  ch1_6.c
//  PointersOnCPrograms
//
//  Created by Netease on 2018/7/30.
//  Copyright © 2018年 Netease. All rights reserved.
//

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define    MAX_COLS    20    /* max # of columns to process */
#define    MAX_INPUT    1000    /* max len of input & output lines */

int    read_column_numbers( int columns[], int max );
void    rearrange_ch1_6( char *output, char const *input,
                  int n_columns, int const columns[] );

int
main( void )
{
    int    n_columns;        /* # of columns to process */
    int    columns[MAX_COLS];    /* the columns to process */
    char    input[MAX_INPUT];    /* array for input line */
    char    output[MAX_INPUT];    /* array for output line */
    
    /*
     ** Read the list of column numbers
     */
    n_columns = read_column_numbers_ch1_6( columns, MAX_COLS );
    
    /*
     ** Read, process and print the remaining lines of input.
     */
    while( gets( input ) != NULL ){
        printf( "Original input : %s\n", input );
        rearrange_ch1_6( output, input, n_columns, columns );
        printf( "Rearranged line: %s\n", output );
    }
    
    return EXIT_SUCCESS;
}

/*
 ** Read the list of column numbers, ignoring any beyond the specified
 ** maximum.
 */
int
read_column_numbers( int columns[], int max )
{
    int    num = 0;
    int    ch;
    
    /*
     ** Get the numbers, stopping at eof or when a number is < 0.
     */
    while( num < max && scanf( "%d", &columns[num] ) == 1
          && columns[num] >= 0 )
        num += 1;
    
    /*
     ** Make sure we have an even number of inputs, as they are
     ** supposed to be paired.
     */
#if 0
    if( num % 2 != 0 ){
        puts( "Last column number is not paired." );
        exit( EXIT_FAILURE );
    }
#endif
    
    /*
     ** Discard the rest of the line that contained the final
     ** number.
     */
    while( (ch = getchar()) != EOF && ch != '\n' )
        ;
    
    return num;
}

/*
 ** Process a line of input by concatenating the characters from
 ** the indicated columns.  The output line is then NUL terminated.
 */
void
rearrange_ch1_6( char *output, char const *input,
          int n_columns, int const columns[] )
{
    int    col;        /* subscript for columns array */
    int    output_col;    /* output column counter */
    int    len;        /* length of input line */
    
    len = strlen( input );
    output_col = 0;
    
    /*
     ** Process each pair of column numbers.
     */
    for( col = 0; col < n_columns; col += 2 ){
        int nchars;
        if (col + 1 == n_columns) { // 列标号为奇数个，此 col 为最后一个数
            nchars = len - col; // 此时需要复制的字符串个数为剩余的全部个数
        } else {
            nchars = columns[col + 1] - columns[col] + 1;
        }
        
        /*
         ** If the input line isn't this long or the output
         ** array is full, we're done.
         */
        if( columns[col] >= len ||
           output_col == MAX_INPUT - 1 )
            break;
        
        /*
         ** If there isn't room in the output array, only copy
         ** what will fit.
         */
        if( output_col + nchars > MAX_INPUT - 1 )
            nchars = MAX_INPUT - output_col - 1;
        
        /*
         ** Copy the relevant data.
         */
        strncpy( output + output_col, input + columns[col],
                nchars );
        output_col += nchars;
    }
    
    output[output_col] = '\0';
}
#endif
