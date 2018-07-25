/*
** A client that uses the generic stack module to create two stacks
** holding different types of data.
*/
#include <stdlib.h>
#include <stdio.h>
#include "g_stack.h"

/*
**	Create two stacks, one of integers and one of floats.
*/
GENERIC_STACK( int, _int, 10 )
GENERIC_STACK( float, _float, 5 )

int
main()
{
	/*
	** Push several values on each stack.
	*/
	push_int( 5 );
	push_int( 22 );
	push_int( 15 );
	push_float( 25.3 );
	push_float( -40.5 );

	/*
	** Empty the integer stack and print the values.
	*/
	while( !is_empty_int() ){
		printf( "Popping %d\n", top_int() );
		pop_int();
	}

	/*
	** Empty the float stack and print the values.
	*/
	while( !is_empty_float() ){
		printf( "Popping %f\n", top_float() );
		pop_float();
	}

	return EXIT_SUCCESS;
}
